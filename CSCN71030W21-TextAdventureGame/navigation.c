#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SaveData.h"
#include "Paragraph.h"
#include "functions.h"
#include "Definition.h"
#include "menuOptions.h"
#include "navigation.h"



void StartGame()
{
	int playerreturnValue;
	char playerOption = "";
	printf("--------START GAME -----------\n");

	DisplayMenuOption(playerOption);

}


void LoadSaveFIle()
{
	//void loadSaveFile(char* userName, SaveData* saveData)
	char* playerName = " ";
	SaveData saveddata[SAVESLOTS] = { {0} };

	loadSaveFile(playerName, saveddata);
}


void LoadSaveSlot()
{
	LoadSaveSlot();
}


void SavePresentData()
{
	//void writeSave(char* userName,SaveData* saveData, SaveData currentSave,int saveID)
}


void WriteSavedData()
{
	/*
	* typedef struct
{
	int exist;
	int progress;
	int itemNum;
	int conditionNum;
	//char inventory[INVENTORYSIZE][ITEMLENGTH];
	int inventory[INVENTORYSIZE];
	int conditions[CONDITIONNUMBER];
}SaveData;
	*/
}


void ReturnToMainMenu() 
{
	char playerInput = "";
	do
	{
		DisplayMenuOption(playerInput);

	} while (true);
	printf("\n");
}


void ExitGame()
{
	char* playerName = "";
	SaveData saveddata[SAVESLOTS] = { {0} };
	SaveData currentSave = { 0 };
	int playerID;

	writeSave(playerName, saveddata, currentSave, playerID);

	int returnValue = -1;
}



