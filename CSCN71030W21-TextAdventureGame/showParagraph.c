#include <stdio.h>
#include <stdlib.h>
#include "Paragraph.h"
#include "SaveData.h"
#include "functions.h"
int showParagraph(Paragraph* storyArr, int progress, SaveData* currentSave,char itemData[][ITEMLENGTH])//test code for display story
{
	int i,j=0;//loop counter
	int input;
	char command;
	char branches[BRANCHNUM][MAXBRANCHLEN] = { 0 };//A buffer holding the valid branches
	int next[BRANCHNUM] = { 0 };//A buffer holding the next ids of valid branches
	int branchConditions[BRANCHNUM] = { 0 };
	int cursor = 0;//the current branch cursor is b=pointing at.


	system("CLS");//clear screen
	currentSave->conditions[storyArr[progress].cancelCondition] = 0;
	currentSave->conditions[storyArr[progress].metCondition] = 1;//Update the condition data this paragraph meets in current save data.
	if (storyArr[progress].speaker[0] != '\0')
	{
		printf("%s:\n", storyArr[progress].speaker);//display speaker if exists
	}
	printf("%s\n", storyArr[progress].content);//display paragraph text
	
	//if (storyArr[progress].item[0] != '\0')//if an item exists here, display notice
		//printf("acquired %s\n\n", storyArr[progress].item);
	printf("Inventory:");
	for (i = 0; i < INVENTORYSIZE; i++)//display inventory items here
	{
		if (currentSave->inventory[i])
		{
			printf("%s; ",itemData[i]);
		}
	}
	printf("\n");
	if (storyArr[progress].item > 0)//make changes to inventory after displaying 
		currentSave->inventory[storyArr[progress].item] = 1;
	else if(storyArr[progress].item < 0)
		currentSave->inventory[-storyArr[progress].item] = 0;

	if (storyArr[progress].branches[0][0] == '\0')//if no branch exist, proceed to next paragraph upon any input
	{
		
		//command=getchar();
		command=getchar();
		//getchar();
		if(command=='\n')
		for (i = 0; i < BRANCHNUM; i++)
		{
			if (storyArr[progress].next[i] >=0 && currentSave->conditions[storyArr[progress].branchConditions[i]])//check if conditions are met to proceed to next paragraph. Branches ahead in array are more prioritized.
			{
				return showParagraph(storyArr, storyArr[progress].next[i], currentSave,itemData);
				break;
			}
			else if (storyArr[progress].next[i] <0 && currentSave->conditions[storyArr[progress].branchConditions[i]])//This means end of story is reached.
			{
				return -storyArr[progress].next[i];
				break;
			}
		}
	}
	else//if branch exist
	{
		
		while (1)//keep taking inputs if input is invalid
		{
			system("CLS");//clear screen
			currentSave->conditions[storyArr[progress].cancelCondition] = 0;
			currentSave->conditions[storyArr[progress].metCondition] = 1;//Update the condition data this paragraph meets in current save data.
			if (storyArr[progress].speaker[0] != '\0')
			{
				printf("%s:\n", storyArr[progress].speaker);//display speaker if exists
			}
			printf("%s\n", storyArr[progress].content);//display paragraph text

			j = 0;
			for (i = 0; i < BRANCHNUM; i++)//display branches
			{
				//printf("%c %d %d should be char and 0 and 1\n", storyArr[progress].branches[i][0], storyArr[progress].branchConditions[i], currentSave->conditions[storyArr[progress].branchConditions[i]]);
				if (storyArr[progress].branches[i][0] != '\0' && currentSave->conditions[storyArr[progress].branchConditions[i]])//j is the id of actually displaying branches
				{
					next[j] = storyArr[progress].next[i];
					branchConditions[j] = storyArr[progress].branchConditions[i];
					if (cursor == j)
						printf(">%s\n", storyArr[progress].branches[i]);
					else
						printf(" %s\n", storyArr[progress].branches[i]);
					j++;
				}
			}
			printf("Inventory:");
			for (i = 0; i < INVENTORYSIZE; i++)//display inventory items here
			{
				if (currentSave->inventory[i])
				{
					printf("%s; ", itemData[i]);
				}
			}
			printf("\n");
			if (storyArr[progress].item > 0)//make changes to inventory after displaying 
				currentSave->inventory[storyArr[progress].item] = 1;
			else if (storyArr[progress].item < 0)
				currentSave->inventory[-storyArr[progress].item] = 0;

			command = getch();
			if (command == 72 && cursor > 0)//move cursor up
			{
				cursor--;
			}
			if (command == 80 && cursor < j-1)//move cursor down
			{
				cursor++;
			}
			if (command == '\r')//enter key pressed
			{
				if (next[cursor] >=0 && currentSave->conditions[branchConditions[cursor]])//make sure conditions are met
				{
					return showParagraph(storyArr, next[cursor], currentSave,itemData);//go to paragraph pointed to by the cursor
					break;
				}
				else if (next[cursor] <0 && currentSave->conditions[branchConditions[cursor]])
				{
					return -next[cursor];
					break;
				}
			}
		
		}
	}
	//printf("end of paragraph %d\n",progress);
	//getchar();
}