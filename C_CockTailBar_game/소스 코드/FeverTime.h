#pragma once
#include"basic.h"
#include"time.h"
#include"CocktailMaking.h"
#include"guest.h"
#include"IngredientAndGlass.h"
#include"GameBox.h"

int combo;
int isFeverTime;//1 is fevertime
int feverStartTime ;

int feverTimeNow;

int isChecked;
int checkedTime;


void CheckComboAndFeverTime(int realPay, int pay);
void FeverTimeEffect();

void Init_FeverTime();