// CSCN71030W21-TextAdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "Paragraph.h"
#include "functions.h"
#define MAXPARAGRAPHS 50
int main(int argc, char** argv)
{
	Paragraph storyArr[50] = { {0} };//stores the story. Story is anticipated to take 50 paragraphs at most here
	printf("waiting to open...\n");
	loadStory(storyArr);//load story from file
	printf("file loaded...\n");
	showParagraph(storyArr, 0);//display first paragraph. Function will proceed to next parts of story automatically
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
