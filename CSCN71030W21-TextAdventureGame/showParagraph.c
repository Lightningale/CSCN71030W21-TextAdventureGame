#include <stdio.h>
#include <stdlib.h>
#include "Paragraph.h"
#include "SaveData.h"
void showParagraph(Paragraph* storyArr, int progress, SaveData* currentSave)//test code for display story
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
	
	if (storyArr[progress].item[0] != '\0')//if an item exists here, display notice
		printf("acquired %s\n\n", storyArr[progress].item);



	if (storyArr[progress].branches[0][0] == '\0')//if no branch exist, proceed to next paragraph upon any input
	{
		
		command=getchar();
		command=getchar();
		//getchar();
		if(command=='\n')
		for (i = 0; i < BRANCHNUM; i++)
		{
			if (storyArr[progress].next[i] != -1 && currentSave->conditions[storyArr[progress].branchConditions[i]])//check if conditions are met to proceed to next paragraph. Branches ahead in array are more prioritized.
			{
				showParagraph(storyArr, storyArr[progress].next[i], currentSave);
				break;
			}
			else if (storyArr[progress].next[i] == -1 && currentSave->conditions[storyArr[progress].branchConditions[i]])//This means end of story is reached.
			{

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
			printf("%d\n", j);
			//scanf_s("%d", &input);//if branches exist ,scan for input
			//input--;
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
				if (next[cursor] != -1 && currentSave->conditions[branchConditions[cursor]])//make sure conditions are met
				{
					showParagraph(storyArr, next[cursor], currentSave);//go to paragraph pointed to by the cursor
					break;
				}
				else if (next[cursor] == -1 && currentSave->conditions[branchConditions[cursor]])
				{
					break;
				}
			}
		
		}
	}
}