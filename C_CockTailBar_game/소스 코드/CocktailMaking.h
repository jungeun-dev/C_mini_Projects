#include "basic.h"
#include "guest.h"
#include "IngredientAndGlass.h"
#include "time.h"
#include"FeverTime.h"

#pragma once

#define SPACE 32
#define ENTER 13
#define TABLE_CENTER 7
#define ONE 49
#define TWO 50
#define THREE 51
#define DELETE 100
#define Q 81
#define W 87
#define E 69

#define GLASS_WIDTH 6
#define GLASS_START 12

extern int bar_number;  //정은 전역 변수 추가

void FirstSetBar(void);
void SetCocktailBar(void);
void SettingBar(int key);
void Redrawsetting(int bar_num);
void DrawCockTail(MAKINGBAR bar);
void DrawShakingGageBar(MAKINGBAR bar);
int selectIngredient(void);
void CleanTable(int bar_num);
void PrintOfferedCockTail(int bar_num);
int OfferCockTail(int bar_num);
void RedrawOfferdBar(int bar_num);