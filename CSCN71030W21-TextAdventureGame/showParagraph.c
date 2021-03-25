#include <stdio.h>
#include "Paragraph.h"
#include "SaveData.h"
void showParagraph(Paragraph* storyArr, int progress, SaveData* currentSave)//test code for display story
{
	int i;//loop counter
	int input;
	system("CLS");//clear screen
	currentSave->conditions[storyArr[progress].metCondition] = 1;//Update the condition data this paragraph meets in current save data.
	printf("%s\n", storyArr[progress].speaker);//display speaker
	printf("%s\n", storyArr[progress].content);//display paragraph text
	if (storyArr[progress].item[0] != '\0')//if an item exists here, display notice
		printf("acquired %s\n\n", storyArr[progress].item);

	for (i = 0; i < BRANCHNUM; i++)//display branches if they exist and their conditions are met in the current progress
	{
		if (storyArr[progress].branches[i][0] != '\0' && currentSave->conditions[storyArr[progress].branchConditions[i]])
			printf("%s\n", storyArr[progress].branches[i]);
	}

	if (storyArr[progress].branches[0][0] == '\0')//if no branch exist, proceed to next paragraph upon any input
	{
		getchar();
		getchar();
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
			scanf_s("%d", &input);//if branches exist ,scan for input
			input--;
			if (storyArr[progress].next[input] != -1 && currentSave->conditions[storyArr[progress].branchConditions[input]])//make sure conditions are met
			{
				showParagraph(storyArr, storyArr[progress].next[input], currentSave);//next paragraph depends on user input
				break;
			}
			else if(storyArr[progress].next[input] == -1 && currentSave->conditions[storyArr[progress].branchConditions[input]])
			{
				break;
			}
		}
	}
}