#include <stdio.h>
#include<stdlib.h>

void loadSave(char* userName)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, userName, "r")) != 0)//assume file exist first and open file in read mode
	{
		if ((err = fopen_s(&fp, userName, "w+")) != 0)//if failed to open file in r+, assume file don't exist and create new file
		{
			printf("Error: cannot load save data");
			exit(EXIT_FAILURE);
		}
	}
	if (!err && fp != NULL)//test for non-null pointer
	 fclose(fp);
}