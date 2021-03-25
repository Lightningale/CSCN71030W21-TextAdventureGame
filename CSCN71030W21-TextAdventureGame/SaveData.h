#pragma once
#include "Definition.h"
typedef struct
{
	int exist;
	int progress;
	int itemNum;
	int conditionNum;
	char inventory[INVENTORYSIZE][ITEMLENGTH];
	char conditions[CONDITIONNUMBER];
}SaveData;