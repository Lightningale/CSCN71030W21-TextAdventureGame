// CSCN71030W21-TextAdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>
#include "SaveData.h"
#include "Paragraph.h"
#include "AsciiArt.h"
#include "functions.h"
#include "Definition.h"

int main(int argc, char** argv)
{
	//Back end module should define story array on heap to avoid memory failure
	Paragraph storyArr[MAXPARAGRAPHS] = {0};//stores the story. Story is anticipated to take 100 paragraphs at most here
	AsciiArt asciiArts[ASCIIARTSNUM] = { 0 };
	SaveData saveData[SAVESLOTS] = { {0} };//stores the save data of the user.
	char* playerName = "Akira";//username and player's name shown in script. This should be read from commandline input in official version.
	//int conditions[CONDITIONNUMBER] = { 0 };//conditions player must meet to reveal new branches. 0 means not condition unmet and 1 means condition met
	//conditions[0] = 1;//condition 0 is met by default, it's for paragraphs that don't need special requirement
	//char inventory[INVENTORYSIZE][ITEMLENGTH] = { {0} };//stores the items player have. Backend module should make sure all items are appended to the front of array
	char itemData[INVENTORYSIZE][ITEMLENGTH] = { "Snacks","Alarm clock","Folder","Medal","USB drive","ID card","ID card","Potato chips","ice cream puffs","chocolate bars"};
	int ending=0;//return value of showParagraph, shows what end the story has come to
	int i = 0;
	int command = 0;
	int repeatflag = 0;
	SaveData currentSave = { 0 };//stores the current progress of player in game
	currentSave.conditions[0] = 1;//condition 0 is met by default, it's for paragraphs that don't need special requirement
	currentSave.conditions[1] = 1;
	currentSave.conditions[3] = 1;
	currentSave.conditions[5] = 1;
	currentSave.conditions[7] = 1;
	currentSave.conditions[12] = 1;
	currentSave.progress = 0;
	//currentSave.conditions[8] = 1;
	//SaveData* currentSave = (SaveData *)malloc(sizeof(SaveData));
	//currentSave->conditions[0] = 1;
	//currentSave->conditionNum++;
	/*
	if (argc < 2)
	{
		printf("please input username");
		return 0;
	}
	else
	{
		strncpy(playerName, MAXUSERNAME, argv[1], MAXUSERNAME);
	}*/
	printf("waiting to open...\n");
	loadSaveFile(playerName, &saveData);
	loadAA(asciiArts);
	loadStory(storyArr, playerName);//load story from file
	printf("story file loaded...\n");
	while (1)
	{
		system("CLS");
		command = showMainMenu(asciiArts);
		if (command == 0)
		{
			ending = showParagraph(storyArr, asciiArts, saveData, &currentSave, itemData,playerName);//display first paragraph. Function will proceed to next parts of story automatically
			if (ending > 0)
			{
				ending--;
				showEnding(ending);
				resetSave(&currentSave);
				//break;
			}
			
		}
		else if (command == 1)
		{
		    command=loadSaveMenu(saveData);
			if (command < SAVESLOTS)
			{
				loadSaveSlot(saveData, command, &currentSave);
				ending = showParagraph(storyArr, asciiArts, saveData, &currentSave, itemData,playerName);//display first paragraph. Function will proceed to next parts of story automatically
				if (ending > 0)
				{
					ending--;
					showEnding(ending);
					resetSave(&currentSave);
					//break;
				}
			}
		}
		else if (command == 2)
		{
			exit(0);
		}
	}

	//loadSaveMenu(saveData);
	

	//ending=showParagraph(storyArr, asciiArts,&saveData,&currentSave,itemData);//display first paragraph. Function will proceed to next parts of story automatically
	//ending--;
	//showEnding(ending);
	
	
	


	/*
	//test writesave function
	currentSave.conditions[2] = 1;
	currentSave.conditions[4] = 1;
	currentSave.inventory[3]=1;
	currentSave.inventory[4]=1;
	currentSave.exist = 1;
	currentSave.progress = 4;
	writeSave(playerName, saveData, currentSave,1);
	currentSave.conditions[3] = 0;
	currentSave.inventory[5] = 1;
	writeSave(playerName, saveData, currentSave, 9);
	
	//test read save functions
	loadSaveFile(playerName, &saveData);
	loadSaveSlot(saveData, 1, &currentSave);
	for (i = 0; i < CONDITIONNUMBER; i++)
	{
		printf("%d ", currentSave.conditions[i]);
	}
	printf("\n");
	for (i = 0; i < INVENTORYSIZE; i++)
	{
		printf("%d ", currentSave.inventory[i]);
	}
	printf("\n");
	loadSaveSlot(saveData, 9, &currentSave);
	for (i = 0; i < CONDITIONNUMBER; i++)
	{
		printf("%d ", currentSave.conditions[i]);
	}
	printf("\n");
	for (i = 0; i < INVENTORYSIZE; i++)
	{
		printf("%d ", currentSave.inventory[i]);
	}
	printf("\n");
	*/
	
	return 0;
}

