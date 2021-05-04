#include "basic.h"

#pragma once

#define UP 72
#define DOWN 80
#define ENTER 13

extern char Name[20];

void gameboard(void);
void printbartender(int color_change);
void printword(void);
void printbox(GAMESTART gamest);
void erasebox(GAMESTART gamest);
void chooseStart(key);
void gamestartset(void);
void PrintYourNameFrame(void);
void YourName(void);
void YourNameQuestion(void);
void printKeyManual();