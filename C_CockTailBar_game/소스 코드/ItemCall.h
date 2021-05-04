#include "IngredientAndGlass.h"
#include"CocktailMaking.h"
#include"basic.h"
#include"guest.h"



#define MINIGAME_ORIGIN_X_dong 16
#define MINIGAME_ORIGIN_Y_dong 22

//Telephone
int recievedCalls;
int currentCall;
int callStart;

//IncomingCall
int calling;

//PrintQuestion
int qNum;

//RepairCall
int waiting;

//BossCall
int bossTable;
int bossStart;






void TelePhone(int t);

void IncomingCall();
void BossCall();
void ChefCall();
void LogisticsCall();
void JinsangCall();
void RepairCall();

void RecieveCall(int key);

void PrintMiniGameFrame();
void PrintQuestion(char* q, int qNum);


void ProccessKeyInput_ItemCall(int calling);

void ProcessKeyInput_JinsangMiniGame();
void ProcessKeyInput_RepairCall();
void ProccessKeyInput_ChefCall();
void ProccessKeyInput_LogisticsCall();
void ProcessKeyInput_BossCall();


//boss
void PrintBossFace();
void EraseBossFace();
void SettingBarOnBoss(int key);


//init
void Init_ItemCall();