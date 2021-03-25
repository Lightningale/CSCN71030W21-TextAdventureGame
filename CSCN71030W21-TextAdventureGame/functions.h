void loadStory(Paragraph* storyArr);
void showParagraph(Paragraph* storyArr,int progress, SaveData* currentSave);
void writeSave(char* userName, SaveData* saveData, SaveData currentSave, int saveID);
void loadSaveFile(char* userName, SaveData* saveData);
void loadSaveSlot(SaveData* saveData, int saveID, SaveData* currentSave);