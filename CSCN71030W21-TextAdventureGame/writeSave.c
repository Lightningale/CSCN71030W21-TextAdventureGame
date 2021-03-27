#include <stdio.h>
#include <stdlib.h>
#include "Definition.h"
#include "SaveData.h"
void writeSave(char* userName,SaveData* saveData, SaveData currentSave,int saveID)
{
	FILE* fp;
	errno_t err;
	int i = 0,j=0;
	int conditionNum = 0;
	int itemNum = 0;
	saveData[saveID].exist = 1;//Mark the save slot as having a save file
	saveData[saveID].progress = currentSave.progress;//store the story progress
	for (i = 0; i < CONDITIONNUMBER; i++)//save the condition array in save data
	{
		if (currentSave.conditions[i] != 0)
		{
			saveData[saveID].conditionNum++;
			saveData[saveID].conditions[i] = currentSave.conditions[i];
		}
	}
	for (i = 0; i < INVENTORYSIZE; i++)//save the inventory in save data
	{
		saveData[saveID].inventory[i] = currentSave.inventory[i];
	}
	saveData[saveID].itemNum = currentSave.itemNum;
	saveData[saveID].conditionNum = currentSave.conditionNum;
	//printf("save data prepared\n");
	if ((err = fopen_s(&fp, userName, "w+")) != 0)//open file in write mode
	{
		printf("Error: failed to save data");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_SET);//go to start of file to start rewrite
	//printf("savefile opened\n");
	for (i = 0; i < SAVESLOTS; i++)//write the save data array to save file. Each save file consists of three parts
	{
		fprintf_s(fp, "%d %d %d %d\n", saveData[i].exist, saveData[i].progress, saveData[i].conditionNum, saveData[i].itemNum);//in first part, store the exist flag, progress, item and condition numbers
		for (j = 0; j < CONDITIONNUMBER; j++)//second part prints the condition array;
		{
			fprintf_s(fp, "%d ", saveData[i].conditions[j]);	
		}
		fprintf_s(fp,"\n");
		for (j = 0; j < INVENTORYSIZE; j++)//third part prints the inventory array
		{
			fprintf_s(fp,"%d ", saveData[i].inventory[j]);
		}
		fprintf_s(fp,"\n");
	}
	
	fclose(fp);
}