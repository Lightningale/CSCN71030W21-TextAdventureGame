#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "AsciiArt.h"
void showMainMenu(AsciiArt* asciiArts)
{
	int i = 0,j=0;
	char offset[30] = "                             ";


		for (i = 0; i < 20; i++)
		{
			printf("%s\n", asciiArts[j].aaGrid[i]);
		}

	printf("%s%s\n", offset,"Start new game");
	printf("%s%s\n", offset, "Load save");
	printf("%s%s\n", offset, "Exit");
}