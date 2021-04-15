#include <stdio.h>
#include <stdlib.h>
#include "Paragraph.h"
#include "SaveData.h"
#include "functions.h"
int showParagraph(Paragraph* storyArr,AsciiArt* asciiArts, SaveData* saveArr, SaveData* currentSave,char itemData[][ITEMLENGTH])//test code for display story
{
	int i,j=0;//loop counter
	int input;
	char command;
	char branches[BRANCHNUM][MAXBRANCHLEN] = { 0 };//A buffer holding the valid branches
	int next[BRANCHNUM] = { 0 };//A buffer holding the next ids of valid branches
	int branchConditions[BRANCHNUM] = { 0 };
	int cursor = 0;//the current branch cursor is b=pointing at.
	char inventory[78] = "";
	currentSave->conditions[storyArr[currentSave->progress].cancelCondition] = 0;
	currentSave->conditions[storyArr[currentSave->progress].metCondition] = 1;//Update the condition data this paragraph meets in current save data.
	if (storyArr[currentSave->progress].item > 0)//make changes to inventory
		currentSave->inventory[storyArr[currentSave->progress].item] = 1;
	else if (storyArr[currentSave->progress].item < 0)
		currentSave->inventory[-storyArr[currentSave->progress].item] = 0;
	for (i = 0; i < INVENTORYSIZE; i++)//display inventory items here
	{
		if (currentSave->inventory[i])
		{
			strcat(inventory, itemData[i]);
			strcat(inventory, " ");
			//printf("%s ", itemData[i]);
		}
	}

	while (1) {
		system("CLS");//clear screen
		char* buff = "bedroom";
		printf("________________________________________________________________________________\n");//length:80
		printf("|                              Location:%-10s                             |\n", storyArr[currentSave->progress].location);
		printf("|______________________________________________________________________________|\n");
		printf("|                                                                              |\n");
		for (i = 0; i < asciiArts[storyArr[currentSave->progress].aaId].height; i++)
		{
			printf("|     %-68s     |\n", asciiArts[storyArr[currentSave->progress].aaId].aaGrid[i]);
		}
		for (; i < 18; i++)
		{
			printf("|                                                                              |\n");
		}
		printf("|______________________________________________________________________________|\n");
		//if (storyArr[currentSave.progress].speaker[0] != '\0')
		//{
		//	printf("%s:\n", storyArr[currentSave.progress].speaker);//display speaker if exists
		//}
		printf("|%-10s                                                                    |\n", storyArr[currentSave->progress].speaker);
		
		
		for (i = 0; i < 5; i++)
		{
			printf("|%-78.78s|\n", storyArr[currentSave->progress].content + i * 78);
		}
		printf("|______________________________________________________________________________|\n");
		j = 0;
		for (i = 0; i < BRANCHNUM; i++)//display branches
		{
			//printf("%c %d %d should be char and 0 and 1\n", storyArr[currentSave.progress].branches[i][0], storyArr[currentSave.progress].branchConditions[i], currentSave->conditions[storyArr[currentSave.progress].branchConditions[i]]);
			if (storyArr[currentSave->progress].branches[i][0] != '\0' && currentSave->conditions[storyArr[currentSave->progress].branchConditions[i]])//j is the id of actually displaying branches
			{
				next[j] = storyArr[currentSave->progress].next[i];
				branchConditions[j] = storyArr[currentSave->progress].branchConditions[i];
				if (cursor == j)
					printf("|>%-77s|\n", storyArr[currentSave->progress].branches[i]);
				else
					printf("| %-77s|\n", storyArr[currentSave->progress].branches[i]);
				j++;
			}
		}
		for (i = j; i < 5; i++)
		{
			printf("| %-77s|\n", " ");
		}
		printf("|______________________________________________________________________________|\n");
		printf("|%-78s|\n","Inventory");
		printf("|%-78s|\n",inventory);
		//printf("%s", inventory);
		//printf("%-79s|\n"," ");
		printf("|______________________________________________________________________________|\n");
		printf("[S]:Save [L]:Load [E]:Exit game");
		printf("\n");
		command = getch();
		if (command == 72 && cursor > 0)//move cursor up
		{
			cursor--;
		}
		if (command == 80 && cursor < j - 1)//move cursor down
		{
			cursor++;
		}

		if (storyArr[currentSave->progress].branches[0][0] == '\0')//if no branch exist, proceed to next paragraph upon any input
		{

			//command=getchar();
			//getchar();
			if (command == '\r')
				for (i = 0; i < BRANCHNUM; i++)
				{
					if (storyArr[currentSave->progress].next[i] >= 0 && currentSave->conditions[storyArr[currentSave->progress].branchConditions[i]])//check if conditions are met to proceed to next paragraph. Branches ahead in array are more prioritized.
					{
						currentSave->progress = storyArr[currentSave->progress].next[i];
						return showParagraph(storyArr, asciiArts,&saveArr, currentSave, itemData);
						break;
					}
					else if (storyArr[currentSave->progress].next[i] < 0 && currentSave->conditions[storyArr[currentSave->progress].branchConditions[i]])//This means end of story is reached.
					{
						return -storyArr[currentSave->progress].next[i];
						break;
					}
				}
		}
		else
		{
			if (command == '\r')//enter key pressed
			{
				if (next[cursor] >= 0 && currentSave->conditions[branchConditions[cursor]])//make sure conditions are met
				{
					currentSave->progress = next[cursor];
					return showParagraph(storyArr, asciiArts, &saveArr, currentSave, itemData);//go to paragraph pointed to by the cursor
					break;
				}
				else if (next[cursor] < 0 && currentSave->conditions[branchConditions[cursor]])
				{
					return -next[cursor];
					break;
				}
			}
		}
	}
	

	
	//printf("end of paragraph %d\n",currentSave.progress);
	//getchar();
}