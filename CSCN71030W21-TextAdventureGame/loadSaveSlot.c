#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "SaveData.h"
void loadSaveSlot(SaveData* saveData, int saveID, SaveData* currentSave)
{
	int i;
	currentSave->progress = saveData[saveID].progress;
	//*currentSave->conditions = saveData[saveID].conditions;
	for (i = 0; i < CONDITIONNUMBER; i++)
	{
		currentSave->conditions[i] = saveData[saveID].conditions[i];
	}
	for (i = 0; i < INVENTORYSIZE; i++)
	{
		currentSave->inventory[i] = saveData[saveID].inventory[i];
	}
}