#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "AsciiArt.h"
int showMainMenu(AsciiArt* asciiArts)
{
	int i = 0,j=0;
	int cursor = 0;
	char command = 0;
	char offset[30] = "                         ";

	while (1)
	{
		system("CLS"); 
		for (i = 0; i < 20; i++)
		{
			printf("%s\n", asciiArts[j].aaGrid[i]);
		}
		if (cursor == 0)
		{
			printf("%s%s\n", offset, ">Start new game");
		}
		else 
		{
			printf("%s%s\n", offset, " Start new game");
		}
		if (cursor == 1)
		{
			printf("%s%s\n", offset, ">Load save");
		}
		else
		{
			printf("%s%s\n", offset, " Load save");
		}
		if (cursor == 2)
		{
			printf("%s%s\n", offset, ">Exit game");
		}
		else
		{
			printf("%s%s\n", offset, " Exit game");
		}
		//printf("%s%s\n", offset, "Start new game");
		//printf("%s%s\n", offset, "Load save");
		//printf("%s%s\n", offset, "Exit");
		command = getch();
		if (command == 72 && cursor > 0)//move cursor up
		{
			cursor--;
		}
		if (command == 80 && cursor < 2)//move cursor down
		{
			cursor++;
		}
		if (command == '\r')//move cursor down
		{
			return cursor;
		}
	}

	return 0;
}