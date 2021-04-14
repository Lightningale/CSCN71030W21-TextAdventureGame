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
	char playerAnswer = " ";
	char nextOption = "";
	char* playerName = " ";
	SaveData saveddata[SAVESLOTS] = { {0} };
	printf(" Do you wish to start again or continue? \n");
	printf("Select 'A' for Start Again and 'B' for Continue\n");
	if (scanf_s("%c", &playerAnswer) == "A")
	{
		StartGame();
	}
	else if(scanf_s("%c", &playerAnswer) == "B")
	{
		loadSaveFile(playerName, saveddata);
	}	
}


void LoadSaveSlot()
{
	LoadSaveSlot();
}


void SavePresentData()
{
	char playerAnswer = " ";
	char nextOption = "";
	char* playerName = "";
	SaveData saveddata[SAVESLOTS] = { {0} };
	SaveData currentSave = { 0 };
	int playerID;
	printf(" Do you wish to continue? \n");
	printf("Select 'A' for Yes and 'B' for No\n");
	if (scanf_s("%c", &playerAnswer) == "A") 
	{
		DisplayMenuOption(nextOption);
	}
	else if (scanf_s("%c", &playerAnswer) == "B")
	{
		writeSave(playerName, saveddata, currentSave, playerID);
	}
	
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



