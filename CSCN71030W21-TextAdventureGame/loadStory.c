#include <stdio.h>
#include<stdlib.h>
#include "Paragraph.h"
#include "Definition.h"

void loadStory(Paragraph* storyArr)//load story data from file
{
	int branches, item;//number of selection branches and if player can acquire an item here
	char line[MAXLINELEN];//line buffer
	int i=0,j = 0;
    FILE* fp;
    errno_t err;
	if ((err = fopen_s(&fp, "story", "r")) != 0)//load story file
	{
		printf("error: game data corrupted");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAXLINELEN, fp) != NULL)//each loop reads data for a paragraph
	{
		if (line[0] == '\n')//ignore empty lines
			continue;
		else
		{
			sscanf_s(line, "%d %d", &branches, &item);//first scan for branch number and check for item
			fgets(storyArr[i].content, MAXLINELEN, fp);//scan story text
			for (j = 0; j < branches; j++)//scan selection branches if they exist
			{
				fgets(storyArr[i].branches[j], MAXBRANCHLEN, fp);
			}
			if (item)//scan item if it exist
			{
				fgets(storyArr[i].item, ITEMLENGTH, fp);
			}
			//scan for followup paragraph ids. multiple ids may exist if there is selection branch here
			fgets(line, MAXLINELEN, fp);
			sscanf_s(line, "%d %d %d %d %d", &storyArr[i].next[0], &storyArr[i].next[1], &storyArr[i].next[2], &storyArr[i].next[3], &storyArr[i].next[4]);
			//printf("%d %d %d %d %d\n", storyArr[i].next[0], storyArr[i].next[1], storyArr[i].next[2], storyArr[i].next[3], storyArr[i].next[4]);
			i++;
		}
	}

	fclose(fp);

}