#include <stdio.h>
#include "Paragraph.h"

void showParagraph(Paragraph* storyArr,int progress)//test code for display story
{
	int i;//loop counter
	int input;
	system("CLS");//clear screen
	printf("%s\n", storyArr[progress].content);//display paragraph text
	if (storyArr[progress].item[0] != '\0')//if an item exists here, display notice
		printf("acquired %s\n\n", storyArr[progress].item);
	for (i = 0; i < 5; i++)//display branches if exist
	{
		if (storyArr[progress].branches[i][0] != '\0')
			printf("%s\n", storyArr[progress].branches[i]);
	}
	if (storyArr[progress].branches[0][0] == '\0')//if no branch exist, proceed to next paragraph upon any input
	{
		getchar();
		getchar();
		if(storyArr[progress].next[0]!=-1)//if next paragraph id is -1, it means story ends here
			showParagraph(storyArr, storyArr[progress].next[0]);
	}
	else
	{
		scanf_s("%d", &input);//if branches exist ,scan for input
		input--;
		if (storyArr[progress].next[input] != -1)//if next paragraph id is -1, it means story ends here
		{
			//printf("%d", storyArr[progress].next[input]);
			showParagraph(storyArr, storyArr[progress].next[input]);//next paragraph depends on user input
		}
	}
}