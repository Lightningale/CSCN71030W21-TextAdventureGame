#pragma once
#include "Definition.h"
typedef struct
{
	int id;//serial number of the paragraph
	char speaker[SPEAKERLENGTH];//name of the speaker or narrator
	char content[PARAGRAPHSIZE];//paragraph text
	char item[ITEMLENGTH];//item that can be aquired here if exists
	int metCondition;//id of condition that will be satisfied once coming to this paragraph
	int cancelCondition;//id of condition that will be canceled once coming to this paragraph. System first cancels then meets
	int branchConditions[BRANCHNUM];//id of conditions each branch needs to be revealed. Normal branches rely on condition 0, which is 1 by default.
	char branches[BRANCHNUM][MAXBRANCHLEN];//selection branches text
	int next[BRANCHNUM];//serial number of the next paragraph each branch leads to
}Paragraph;
/*
condition table:
0: default condition, always 1
1: player has not collected all relics yet. Deactivates
2: player has collected all the relics.


inventory table:





*/