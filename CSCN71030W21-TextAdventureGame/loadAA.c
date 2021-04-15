#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "AsciiArt.h"
void loadAA(AsciiArt* asciiArts)
{
	char line[MAXLINELEN];//line buffer
	int length = 0;
	int height = 0;
	int i = 0, j = 0;
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "ascii.txt", "r")) != 0)//load story file
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
			sscanf_s(line, "%d %d", &height, &length);//first scan for id,  branch number, item check, and met condition.
			asciiArts[i].height = height;
			for (j = 0; j < height; j++)
			{
				fgets(asciiArts[i].aaGrid[j], length, fp);
				strtok(asciiArts[i].aaGrid[j], "\n");
			}
			i++;
		}
	}
	fclose(fp);
}