#include "SaveData.h"
#include "AsciiArt.h"
void showEnding(int ending);
void loadStory(Paragraph* storyArr,char* playerName);
char* replaceWord(char* orig, char rep[], char* with);
int showParagraph(Paragraph* storyArr, AsciiArt* asciiArts, SaveData* saveArr, SaveData* currentSave, char itemData[][ITEMLENGTH]);
void writeSave(char* userName, SaveData* saveData, SaveData currentSave, int saveID);
void loadSaveFile(char* userName, SaveData* saveData);
void loadSaveSlot(SaveData* saveData, int saveID, SaveData* currentSave);
void loadAA(AsciiArt* asciiArts);
void showMainMenu(AsciiArt* asciiArts);
void loadSaveMenu(SaveData* saveData);
void WriteSaveMenu(SaveData* saveData);