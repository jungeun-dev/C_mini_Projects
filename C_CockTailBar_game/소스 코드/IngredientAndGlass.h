#include "basic.h"
#include<string.h>

#pragma once

#define BOX_ORIGIN_X 3
#define BOX_ORIGIN_Y 21

#define SHELF_X 0
#define SHELF_Y 19

#define GLASS_ORIGIN_X 89
#define GLASS_ORIGIN_Y 21

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define TAB 9

#define MINIGAME_ORIGIN_X 8
#define MINIGAME_ORIGIN_Y 23

#define ARROW_ORIGIN_X 10
#define ARROW_ORIGIN_Y 25

extern int select_x;
extern int select_y;
extern INGREDIENT ingredient[16];
extern INGREDIENTCURSOR cursor[4][6];


void ingredientBox();
void deleteIngredientBox();
void ingredientShelf();

void printGlass();
int canMoveTo(int y, int x);
void initIngredient();
void initIngredientCursor();
void printIngredient();

void playMinigame();
void printArrow(COORD pos, int i);
void printMinigameframe();

int arrownum[8];
int userinput[8];
int pass;
int idx;

COORD pos;

void SettingBar_MINIGAME(int key);