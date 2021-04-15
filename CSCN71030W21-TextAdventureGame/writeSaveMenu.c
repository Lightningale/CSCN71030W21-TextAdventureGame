#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "SaveData.h"
int WriteSaveMenu(SaveData* saveData)
{
	int i = 0, j = 0;
	int cursor = 0;
	char command = 0;
	char line[55] = "--------------------------------------------";
	char offset[20] = "               ";
	char offset2[20] = "                 ";
	while (1)
	{
		system("CLS");
		printf("%s\n%s%s\n%s\n", line, offset, "Save progress", line);
		for (i = 0; i <= SAVESLOTS; i++)
		{
			printf("%s", offset2);
			if (cursor == i)
				printf(">");
			else
				printf(" ");
			if (i == SAVESLOTS)
			{
				printf("%s\n", "CANCEL");
			}
			else if (saveData[i].exist)
			{
				printf("%s%d\n", "Save ", i);
			}
			else if(!saveData[i].exist)
			{
				printf("%s\n", "Empty Slot");
			}
		}
		command = getch();
		if (command == 72 && cursor > 0)//move cursor up
		{
			cursor--;
		}
		if (command == 80 && cursor < SAVESLOTS)//move cursor down
		{
			cursor++;
		}
		if (command == '\r')//move cursor down
		{
			
			return cursor;
		}
	}

}