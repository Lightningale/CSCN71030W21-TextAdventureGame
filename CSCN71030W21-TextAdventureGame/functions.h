#include "SaveData.h"
#include "AsciiArt.h"
int showEnding(int ending);
void loadStory(Paragraph* storyArr,char* playerName);
char* replaceWord(char* orig, char rep[], char* with);
int showParagraph(Paragraph* storyArr, AsciiArt* asciiArts, SaveData* saveArr, SaveData* currentSave, char itemData[][ITEMLENGTH],char playerName[]);
void writeSave(char* userName, SaveData* saveData, SaveData currentSave, int saveID);
void loadSaveFile(char* userName, SaveData* saveData);
void loadSaveSlot(SaveData* saveData, int saveID, SaveData* currentSave);
void loadAA(AsciiArt* asciiArts);
int showMainMenu(AsciiArt* asciiArts);
int loadSaveMenu(SaveData* saveData);
int WriteSaveMenu(SaveData* saveData);
void resetSave(SaveData* currentSave);