#include <stdio.h>
#include <stdlib.h>
#include "Definition.h"
#include "SaveData.h"
void writeSave(char* userName,SaveData* saveData, int saveID,int progress,int conditions[CONDITIONNUMBER], char inventory[INVENTORYSIZE][ITEMLENGTH])
{
	FILE* fp;
	errno_t err;
	int i = 0,j=0;
	int conditionNum = 0;
	int itemNum = 0;
	saveData[saveID].exist = 1;//Mark the save slot as having a save file
	saveData[saveID].progress = progress;//store the story progress
	for (i = 0; i < CONDITIONNUMBER; i++)//save the condition array in save data
	{
		if (conditions[i] != 0)
		{
			saveData[saveID].conditionNum++;
			saveData[saveID].conditions[i] = conditions[i];
		}
	}
	for (i = 0; i < INVENTORYSIZE; i++)//save the inventory in save data
	{
		if (inventory[i][0] != 0)
		{
			itemNum++;
			strncpy_s(saveData[saveID].inventory[i], ITEMLENGTH, inventory[i], ITEMLENGTH);
		}
	}
	saveData[saveID].itemNum = itemNum;
	printf("save data prepared\n");
	if ((err = fopen_s(&fp, userName, "w+")) != 0)//open file in write mode
	{
		printf("Error: failed to save data");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_SET);//go to start of file to start rewrite
	printf("savefile opened\n");
	printf("has data %d\n", saveData[1].conditions[2]);
	for (i = 0; i < SAVESLOTS; i++)//write the save data array to save file. Each save file consists of three lines
	{
		fprintf_s(fp, "%d %d %d %d\n", saveData[i].exist, saveData[i].progress, saveData[i].conditionNum, saveData[i].itemNum);//in first line, store the exist flag, progress, item and condition numbers
		printf("first line printed\n");
		for (j = 0; j < CONDITIONNUMBER; j++)//second line prints the condition array;
		{
			if (saveData[i].conditions[j] != 0)
			{
				fprintf_s(fp, "%d ", j);
				printf("%d %d\n", i, j);
			}
				
		}
		fprintf_s(fp,"\n");
		printf("second line printed\n");
		for (j = 0; j < itemNum; j++)
		{
			fprintf_s(fp,"%s ", saveData[i].inventory[j]);
		}
		fprintf_s(fp,"\n");
		printf("third line printed\n");
	}
	
	fclose(fp);
	printf("save complete\n");
}