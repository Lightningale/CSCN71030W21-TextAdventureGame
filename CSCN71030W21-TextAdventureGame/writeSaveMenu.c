#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "SaveData.h"
void WriteSaveMenu(SaveData* saveData)
{
	int i = 0, j = 0;
	char line[55] = "--------------------------------------------";
	char offset[20] = "               ";
	char offset2[20] = "                 ";
	printf("%s\n%s%s\n%s\n", line, offset, "Save your progress", line);
	for (i = 0; i < SAVESLOTS; i++)
	{
		if (saveData[i].exist)
		{
			printf("%s%s%d\n", offset2, "Save ", i);
		}
		else
		{
			printf("%s%s\n", offset2, "Empty Slot");
		}
	}
}