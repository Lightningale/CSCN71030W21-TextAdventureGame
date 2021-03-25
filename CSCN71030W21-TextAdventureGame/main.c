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
	Paragraph storyArr[MAXPARAGRAPHS] = {0};//stores the story. Story is anticipated to take 200 paragraphs at most here
	SaveData saveData[SAVESLOTS] = { {0} };//stores the save data of the user.
	char* playerName = "Akira";//username and player's name shown in script. This should be read from commandline input in official version.
	int conditions[CONDITIONNUMBER] = { 0 };//conditions player must meet to unlock new branches. 0 means not unlocked and 1 means unlocked
	char inventory[INVENTORYSIZE][ITEMLENGTH] = { {0} };//stores the items player have

	printf("%s\n", inventory);
	printf("waiting to open...\n");
	loadStory(storyArr);//load story from file
	printf("story file loaded...\n");
//	showParagraph(storyArr, 0);//display first paragraph. Function will proceed to next parts of story automatically
	
	//test writesave function
	conditions[2] = 1;
	conditions[4] = 1;
	strncpy_s(inventory[0], ITEMLENGTH, "apple", ITEMLENGTH);
	strncpy_s(inventory[1], ITEMLENGTH, "racket", ITEMLENGTH);
	printf("preparing to write\n");
	writeSave(playerName, saveData, 1, 3, conditions, inventory);
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
