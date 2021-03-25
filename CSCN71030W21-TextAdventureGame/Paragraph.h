#pragma once
typedef struct
{
	int id;
	char speaker[10];
	char content[300];
	char branches[5][50];
	char item[20];
	int next[5];
}Paragraph;