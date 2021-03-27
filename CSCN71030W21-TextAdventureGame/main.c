// CSCN71030W21-TextAdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>
#include "SaveData.h"
#include "Paragraph.h"
#include "functions.h"
#include "Definition.h"

int main(int argc, char** argv)
{
	//Back end module should define story array on heap to avoid memory failure
	Paragraph storyArr[MAXPARAGRAPHS] = {0};//stores the story. Story is anticipated to take 100 paragraphs at most here
	SaveData saveData[SAVESLOTS] = { {0} };//stores the save data of the user.
	char* playerName = "Akira";//username and player's name shown in script. This should be read from commandline input in official version.
	//int conditions[CONDITIONNUMBER] = { 0 };//conditions player must meet to reveal new branches. 0 means not condition unmet and 1 means condition met
	//conditions[0] = 1;//condition 0 is met by default, it's for paragraphs that don't need special requirement
	//char inventory[INVENTORYSIZE][ITEMLENGTH] = { {0} };//stores the items player have. Backend module should make sure all items are appended to the front of array
	int ending;
	SaveData currentSave = { 0 };//stores the current progress of player in game
	currentSave.conditions[0] = 1;//condition 0 is met by default, it's for paragraphs that don't need special requirement
	currentSave.conditions[1] = 1;
	currentSave.conditions[3] = 1;
	currentSave.conditions[5] = 1;
	currentSave.conditions[7] = 1;
	currentSave.conditions[12] = 1;
	//currentSave.conditions[8] = 1;
	currentSave.conditionNum++;
	//SaveData* currentSave = (SaveData *)malloc(sizeof(SaveData));
	//currentSave->conditions[0] = 1;
	//currentSave->conditionNum++;


	printf("waiting to open...\n");
	loadStory(storyArr);//load story from file
	printf("story file loaded...\n");
	ending=showParagraph(storyArr, 1,&currentSave);//display first paragraph. Function will proceed to next parts of story automatically
	ending--;
	showEnding(ending);
	getchar();
	//free(currentSave);
	/*
	//test read save functions
	loadSaveFile(playerName, &saveData);
	loadSaveSlot(saveData, 9, &currentSave);
	printf("%d %d %s\n", currentSave.progress,currentSave.conditions[2], currentSave.inventory[1]);

	//test writesave function
	currentSave.conditions[2] = 1;
	currentSave.conditions[4] = 1;
	currentSave.conditionNum = 2;
	strncpy_s(currentSave.inventory[0], ITEMLENGTH, "apple", ITEMLENGTH);
	strncpy_s(currentSave.inventory[1], ITEMLENGTH, "racket", ITEMLENGTH);
	currentSave.itemNum = 2;
	currentSave.exist = 1;
	currentSave.progress = 4;
	writeSave(playerName, saveData, currentSave,1);*/
	printf("test complete.\n");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
