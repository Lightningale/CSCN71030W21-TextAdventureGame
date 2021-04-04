#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menuOptions.h"


int DisplayMenuOption(char menuInput)
{
	int returnValue = 0;
	char option;

	do
	{
		printf("	a)	Start Game\n");
		printf("	b)	Load Saved File\n");
		printf("	c)	Load Saved Slot\n");
		printf("	d)	Save Present Data\n");
		printf("	e)	Write Saved Data To File\n");
		printf("	f)	Return To Main Menu\n");
		printf("	g)	Exit Game\n");


		print("Select options from a to g:\n");
		if ((scanf_s("%c", &option)) == 1)
		{
			returnValue = DisplayMenuOption(option);

			if (returnValue == -1)
			{
				break;
			}
		}
	} while (true);
			
	scanf_s("%c", &option);
	

	return 0;
}