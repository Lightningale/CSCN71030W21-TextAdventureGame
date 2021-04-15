#include <stdio.h>
#include "Definition.h"
int showEnding(int ending)
{
	int i = 0;
	int cursor = 0;
	char command = 0;
	char endingTitles[10][ENDINGTITLE] = {
		"Fatal Startle",
		"Immersed Audience",
		"A Coin Flipped Sides",
		"New beginning",
		"Perplexed Dreamer",
		"Return to the Void",
		0,
		0,
		0,
		0
	};
	char endingText[10][PARAGRAPHSIZE] = {
		"The flowing text on screen triggered your worst memories, delivering the final blow to your already fragile soul. You fell into another deep sleep, this time there's no wakening again......",
		"The characters walked out of the screen, and stirred turmoils inside your soul. Inside the cinema of memories, you're locked in a perpetual contemplation of time, space and self......",
		"A twin that was never born, a side that was never seen. If the chance ever comes to you one day, will you take on what she's been withstanding in place of you? ",
		"Sun rises and the dews evaporate. The wonderous little adventure was like a dream, leaving nothing but a tiny fragment inside your heart.",
		"Boundaries of conscious obsfucate, where does dream end and reality begin? Memories rust and fade way, but the question will linger on for years to come.",
		"Deep inside the unknown realms of the mind, you touched upon the truth of the world. The mist of data seeped into your soul, everything returned to the void.",
		0,
		0,
		0,
		0
	};
	while (1)
	{
		system("CLS");
		printf("%35s%-30s\n", " ", endingTitles[ending]);
		printf("----------------------------------------------------------------------------------------\n");
		for (i = 0; i < 5; i++)
		{
			printf("%15s%-55.55s\n", " ", endingText[ending] + i * 55);
		}
		
		if (cursor == 0)
		{
			printf("%34s%s\n", " ", ">Back to menu");
		}
		else
		{
			printf("%34s%s\n", " ", " Back to menu");
		}
		if (cursor == 1)
		{
			printf("%34s%s\n", " ", ">Exit game");
		}
		else
		{
			printf("%34s%s\n", " ", " Exit game");
		}
		command = getch();
		if (command == 72 && cursor > 0)//move cursor up
		{
			cursor--;
		}
		if (command == 80 && cursor < 1)//move cursor down
		{
			cursor++;
		}
		if (command == '\r')//move cursor down
		{
			if (cursor == 1)
				exit(0);
			return cursor;
		}
	}

	//printf("%s", endingText[ending]);
}