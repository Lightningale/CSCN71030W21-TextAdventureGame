#pragma once
#define INVENTORYSIZE 10//max number of items to hold at the same time
#define ITEMLENGTH 20//max number of characters for an item text
#define CONDITIONNUMBER 20//number of special conditions for story
#define MAXPARAGRAPHS 100//max number of paragraphs in entire story
#define SAVESLOTS 10//number of saves for each user
#define MAXLINELEN 400//max number of characters in a line in file
#define MAXBRANCHLEN 50//max number of characters in a story branch text
#define SPEAKERLENGTH 10//max size of length of speaker
#define PARAGRAPHSIZE 400//max number of characters in a paragraph
#define BRANCHNUM 10//max branches in a paragraph
#define ENDINGNUM 10//maxnumber of endings to the story
#define ENDINGTITLE 50//max length of ending title
/*
condition table:
0: default condition, always 1
1: player has not collected all relics yet. Deactivates after collecting all relics
2: player has collected all the relics.
3: player has not collected snacks from the company
4: player has collected snacks from the company
5: player has not refused Id's movie request
6: player refused Id's movie request
7: player hasn't watched a movie with Id yet
8: player watched a movie with Id
9: player chose the folder.
10: player chose the medal.
11: player chose the usb drive.
12: player has not received the id card from Superego.
13: player received the id card from Superego.
inventory table:
1: snacks
2: alarm clock
3£ºfolder
4£ºmedal
5£ºusb drive
6: Superego's id card
7: Ego's id card

endings:
-1:Pass out after seeing player's work in the office
-2:Become forever trapped in the movie fire punch
-3:Ego wakes up instead of player
-4:Player wakes up with ideas for his work.
-5:Player wakes up bringing the medal to reality
-6:Player discovers the truth of Memento Space


*/