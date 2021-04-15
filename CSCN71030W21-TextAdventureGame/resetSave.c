#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "SaveData.h"
void resetSave(SaveData* currentSave)
{
	int i;
	currentSave->progress = 0;
	currentSave->exist = 1;
	for (i = 0; i < INVENTORYSIZE; i++)
	{
		currentSave->inventory[i] = 0;
	}
	for (i = 0; i < CONDITIONNUMBER; i++)
	{
		currentSave->conditions[i] = 0;
	}
	currentSave->conditions[1] = 1;
	currentSave->conditions[3] = 1;
	currentSave->conditions[5] = 1;
	currentSave->conditions[7] = 1;
	currentSave->conditions[12] = 1;
}