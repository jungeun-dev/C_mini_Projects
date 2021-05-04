#include"basic.h"
#include"time.h"
#include"CocktailMaking.h"
#include"FeverTime.h"
#include"GameBox.h"
#pragma once

combo = 0;
isFeverTime = 0;//1 is fevertime ( for RecipeCheck() )
feverStartTime = -1;

feverTimeNow = 0;//1 is fevertime (for GameBox, timer)

isChecked = 0;
checkedTime = 0;

void CheckComboAndFeverTime(int realPay, int pay)
{
	if (!isChecked)
	{

		if (realPay == pay && isFeverTime == 0)
		{
			combo += 1;
			if (combo == 3) {
				feverTimeNow = 1;
				feverStartTime = t;

				currentGameBoxColor = 12;
				DrawGameBox_1();
				//DrawTimeAndScore(t);
				//SetCocktailBar();	// 쉐이커 그리기
				//for (int i = 0; i < 3; i++) {
				//	DrawCockTail(makingBar[i]);	// 쉐이커
				//}
				//ingredientShelf();				//재료선반 출력
				//printIngredient();				//재료들 출력
				//printGlass();					//잔 출력
				//ingredientBox();				//재료선택박스 0,0에 출력
				/*for (int i = 0; i < 3; i++)
				{
					if (guest[i].flag == 1)printGuestBoard(guest[i]);
				}*/
			}
			if (combo == 4)
			{
				isFeverTime = 1;
				combo = 0;
			}
		}
		else
		{
			combo = 0;
		}
		isChecked = 1;
		checkedTime = t;
	}
	else if (t - checkedTime > 1)
	{
		isChecked = 0;
		CheckComboAndFeverTime(realPay, pay);
	}
}
void FeverTimeEffect()
{
	if (feverTimeNow == 1 && t - feverStartTime >= 15 || t == 90)
	{
		isFeverTime = 0;
		feverTimeNow = 0;
		feverStartTime = -1;
		combo = 0;

		currentGameBoxColor = 8;
		DrawGameBox_1();
		//DrawTimeAndScore(t);
		//SetCocktailBar();	// 쉐이커 그리기
		//for (int i = 0; i < 3; i++) {
		//	DrawCockTail(makingBar[i]);	// 쉐이커
		//}
		//ingredientShelf();				//재료선반 출력
		//printIngredient();				//재료들 출력
		//printGlass();					//잔 출력
		//ingredientBox();				//재료선택박스 0,0에 출력
		//for (int i = 0; i < 3; i++)
		//{
		//	if (guest[i].flag == 1)printGuestBoard(guest[i]);
		//}
	}
}


void Init_FeverTime()
{
	combo = 0;
	isFeverTime = 0;//1 is fevertime
	feverStartTime = -1;

	feverTimeNow = 0;

	isChecked = 0;
	checkedTime = 0;


	currentGameBoxColor = 8;
	DrawGameBox_1();
}