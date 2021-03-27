#include <stdio.h>
#include<stdlib.h>
#include "Paragraph.h"
#include "Definition.h"

void loadStory(Paragraph* storyArr)//load story data from file
{
	int paraID, branches, item;//id of paragraph, number of selection branches and if player can acquire an item here
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
			sscanf_s(line, "%d %d %d %d %d %s",&paraID, &branches, &item, &storyArr[i].metCondition, &storyArr[i].cancelCondition, storyArr[i].speaker,SPEAKERLENGTH);//first scan for id,  branch number, item check, and met condition.
			printf("5 data: %d %d %d %d %d %s\n",  paraID, branches, item, storyArr[i].metCondition, storyArr[i].cancelCondition, storyArr[i].speaker);
			//fgets(storyArr[i].speaker, SPEAKERLENGTH, fp);//scan for speaker name
			//printf("speaker: %s\n", storyArr[i].speaker);
			fgets(storyArr[i].content, MAXLINELEN, fp);//scan paragraph text
			printf("content: %s\n", storyArr[i].content);
			for (j = 0; j < branches; j++)//scan selection branches if they exist
			{
				fgets(storyArr[i].branches[j], MAXBRANCHLEN, fp);
			}
			/*if (item)//scan item if it exist
			{
				fgets(storyArr[i].item, ITEMLENGTH, fp);
				printf("item: %s\n", storyArr[i].item);
			}*/
			//scan for branch condition array
			fgets(line, MAXLINELEN, fp);
			printf("branch condition array: %s\n", line);
			sscanf_s(line, "%d %d %d %d %d %d %d %d %d %d", &storyArr[i].branchConditions[0], &storyArr[i].branchConditions[1], &storyArr[i].branchConditions[2], &storyArr[i].branchConditions[3], &storyArr[i].branchConditions[4], &storyArr[i].branchConditions[5], &storyArr[i].branchConditions[6], &storyArr[i].branchConditions[7], &storyArr[i].branchConditions[8], &storyArr[i].branchConditions[9]);
			//scan for followup paragraph ids. multiple ids may exist if there is selection branch here
			fgets(line, MAXLINELEN, fp);
			sscanf_s(line, "%d %d %d %d %d %d %d %d %d %d", &storyArr[i].next[0], &storyArr[i].next[1], &storyArr[i].next[2], &storyArr[i].next[3], &storyArr[i].next[4], &storyArr[i].next[5], &storyArr[i].next[6], & storyArr[i].next[7], & storyArr[i].next[8], & storyArr[i].next[9]);
			printf("next id array:: %d %d %d %d %d %d %d %d %d %d\n", storyArr[i].next[0], storyArr[i].next[1], storyArr[i].next[2], storyArr[i].next[3], storyArr[i].next[4], storyArr[i].next[5], storyArr[i].next[6], storyArr[i].next[7], storyArr[i].next[8], storyArr[i].next[9]);
			i++;
		}
	}

	fclose(fp);

}