#include "SaveData.h"
void showEnding(int ending);
void loadStory(Paragraph* storyArr,char* playerName);
char* replaceWord(char* orig, char rep[], char* with);
int showParagraph(Paragraph* storyArr,int progress, SaveData* currentSave, char itemData[][ITEMLENGTH]);
void writeSave(char* userName, SaveData* saveData, SaveData currentSave, int saveID);
void loadSaveFile(char* userName, SaveData* saveData);
void loadSaveSlot(SaveData* saveData, int saveID, SaveData* currentSave);