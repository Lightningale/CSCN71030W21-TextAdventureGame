#include <stdio.h>
#include<stdlib.h>
#include "Definition.h"
#include "SaveData.h"
void loadSaveFile(char* userName, SaveData* saveData)
{
	FILE* fp;
	errno_t err;
	char line[MAXLINELEN];//line buffer
	int i, j;
	int saveSlot = 0;
	int itemNum = 0, conditionNum = 0;
	if ((err = fopen_s(&fp, userName, "r")) != 0)//assume file exist first and open file in read mode
	{
		if ((err = fopen_s(&fp, userName, "w+")) != 0)//if failed to open file in r+, assume file don't exist and create new file
		{
			printf("Error: cannot load save data");
			exit(EXIT_FAILURE);
		}
	}
	printf("file opened\n");
	while (fgets(line, MAXLINELEN, fp) != NULL&&saveSlot<SAVESLOTS)//each loop reads a copy of save data
	{
		if (line[0] == '\n')//ignore empty lines
			continue;
		else
		{
			sscanf_s(line, "%d %d", &saveData[saveSlot].exist, &saveData[saveSlot].progress);//first read the basic information of save
			if (!saveData[saveSlot].exist)//in case of empty save slot, skip the next two lines
			{
				fgets(line, MAXLINELEN, fp);
				fgets(line, MAXLINELEN, fp);
				saveSlot++;
				continue;
			}
			else
			{
				fgets(line, MAXLINELEN, fp);//load conditions line
				sscanf_s(line, "%d %d %d %d %d %d %d %d %d %d", &saveData[saveSlot].conditions[0], &saveData[saveSlot].conditions[1], &saveData[saveSlot].conditions[2], &saveData[saveSlot].conditions[3], &saveData[saveSlot].conditions[4], &saveData[saveSlot].conditions[5], &saveData[saveSlot].conditions[6], &saveData[saveSlot].conditions[7], &saveData[saveSlot].conditions[8], &saveData[saveSlot].conditions[9]);
				fgets(line, MAXLINELEN, fp);//load items
				sscanf_s(line, "%d %d %d %d %d %d %d %d %d %d", &saveData[saveSlot].inventory[0], &saveData[saveSlot].inventory[1], &saveData[saveSlot].inventory[2], &saveData[saveSlot].inventory[3], &saveData[saveSlot].inventory[4], &saveData[saveSlot].inventory[5], &saveData[saveSlot].inventory[6], &saveData[saveSlot].inventory[7], &saveData[saveSlot].inventory[8], &saveData[saveSlot].inventory[9]);
				//sscanf_s(line, "%s %s %s %s %s", saveData[saveSlot].inventory[0], ITEMLENGTH, saveData[saveSlot].inventory[1], ITEMLENGTH, saveData[saveSlot].inventory[2], ITEMLENGTH, saveData[saveSlot].inventory[3], ITEMLENGTH, saveData[saveSlot].inventory[4], ITEMLENGTH);
				printf("slot%d: %d %d %d %d %d %d %d %d\n",saveSlot, saveData[saveSlot].inventory[0], saveData[saveSlot].inventory[1], saveData[saveSlot].inventory[2], saveData[saveSlot].inventory[3], saveData[saveSlot].inventory[4], saveData[saveSlot].inventory[5], saveData[saveSlot].inventory[6], saveData[saveSlot].inventory[7]);
				saveSlot++;
			}
		}
	}
	
	if (!err && fp != NULL)//test for non-null pointer
	{
		fclose(fp);
		printf("file closed\n");
	}
	 
}