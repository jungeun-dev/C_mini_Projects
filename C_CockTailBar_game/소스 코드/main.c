#include "basic.h"
#include "time.h"
#include "guest.h"
#include "CocktailMaking.h"
#include "IngredientAndGlass.h"
#include "ItemCall.h"
#include "GameStart.h"
#include "GameExplanation.h"
#include "FeverTime.h"
#include "StageAndEnding.h"
#include "GameBox.h"

#pragma once

int level = 0;

//gamestart
GAMESTART gamest[2];
int gamestartflag = 0;
char Name[20] = "";

// time
int score = 0;	// 점수
int waitingGuest = 0;	// 대기 손님 수
int t = 0;	// 게임 플레이 시간

// guest
int guestNum = 0;	// 손님의 수
int lastGuestTime = 0;	// 마지막 손님이 온 시간
GUEST guest[3];

// CocktailMaking
MAKINGBAR makingBar[3];
int bar_number = -1;  //정은 전역 변수 추가
int minigameflag = 0; // 전역 변수 추가 (정은 보은)

// IngredientAndGlass
int select_x = 0;
int select_y = 0;
INGREDIENTCURSOR cursor[4][6] = { 0 };
INGREDIENT ingredient[16];

//lever별 칵테일
int cockTail_level1[4] = { 0,6,7,9 };
int cockTail_level2[5] = { 0,2,3,4,8 };
int cockTail_level3[6] = { 1,3,4,5,6,8 };

void init();
void ProcessKeyInput();
void Stage0();
void Stage1();
void Stage2();
void Stage3();

int main()
{
	system("mode con:cols=160 lines=60");  //보은 변경
	system("title 방구석 칵테일");

	while (1) {
		switch (level) {
		case 0:	// 초기화면
			Stage0();
			break;
		case 1:	// 스테이지 1
			Stage1();
			break;
		case 2:	// 스테이지 2
			Stage2();
			break;
		case 3:	// 스테이지 3
			Stage3();
			break;
		}
	}

	return 0;
}

void init() {
	// time
	score = 0;	// 점수
	waitingGuest = 0;	// 대기 손님 수
	t = 0;	// 게임 플레이 시간

	// guest
	guestNum = 0;	// 손님의 수
	lastGuestTime = 0;	// 마지막 손님이 온 시간

	// CocktailMaking
	bar_number = -1;  //정은 전역 변수 추가
	minigameflag = 0; // 전역 변수 추가 (정은 보은)

	// IngredientAndGlass
	select_x = 0;
	select_y = 0;

	Init_ItemCall();
	Init_FeverTime();
}

void ProcessKeyInput() {
	int key;
	for (int i = 0; i < 20; i++) {
		if (_kbhit() != 0) {
			key = _getch();
			if (minigameflag == 1) SettingBar_MINIGAME(key);
			else {
				SettingBar(key);
				RecieveCall(key);
			}
			SetCurrentCursorPos(116, 13);
			//printf("key = (%d) (%c)", key, key);
		}
		Sleep(50);
	}
}

void Stage0() {
	int i = 0, key;

	PlaySound(TEXT("Funny_Dream.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	// 초기화면
	DrawGameBox_1();
	gamestartset();
	while (1) {
		printbartender(i);
		for (int i = 0; i < 10; i++) {
			if (_kbhit() != 0) {
				key = _getch();
				chooseStart(key);
			}
			Sleep(50);
		}
		i++;
		if (gamestartflag > 0) break;
	}
	system("cls");
	DrawGameBox_1();

	//게임 시작 gamestartflag =1 , 게임 방법 gamestartflag = 2
	if (gamestartflag == 2) {
		PlaySound(NULL, 0, 0);
		user_guide();
	}
	if (gamestartflag == 1) {
		PlaySound(NULL, 0, 0);
		//정은 추가
		YourNameQuestion();
		system("cls");
		DrawGameBox_1();

		gamestartflag = 0;
		level = 1;
	}
	gamest[0].selected = 1;
	gamest[1].selected = 0;
}

void Stage1() {
	init();

	// 게임 시작 << STAGE 1 >>
	DrawGameBox_1();
	stage1_screen();
	system("cls");

	DrawGameBox_1();

	// guest
	initGuest();	// 손님 초기화

	// CocktailMaking
	FirstSetBar();	// 쉐이커 초기화
	SetCocktailBar();	// 쉐이커 그리기

	// IngredientAndGlass
	initIngredient();				//재료구조체 초기화: 이름, 남은 갯수
	initIngredientCursor();			//커서구조체 초기화: 모드, 재료번호

	ingredientShelf();				//재료선반 출력
	printIngredient();				//재료들 출력
	printGlass();					//잔 출력
	ingredientBox();				//재료선택박스 0,0에 출력
	printKeyManual();

	while (DEFAULT_TIME - t >= 0) {
		//break;
		// 시간, 점수판, 대기 손님 수
		DrawTimeAndScore(t);

		// 손님 등장
		welcomeGuest();

		// 정은 추가
		if (bar_number >= 0) { // 앞에서 칵테일 제출했을 때
			Redrawsetting(bar_number); // 지우기
			RedrawOfferdBar(bar_number); // 해당 잔만 다시 출력
			bar_number = -1;
		}

		for (int i = 0; i < 3; i++) {
			DrawCockTail(makingBar[i]);	// 쉐이커
		}

		TelePhone(t);
		FeverTimeEffect();

		if (calling != -1) {
			ProccessKeyInput_ItemCall(calling);
		}
		else {
			ProcessKeyInput();
		}

		t++;
	}

	// 엔딩
	system("cls");
	DrawGameBox_1();
	if (score < 30000) {	// 실패
		FailEnding();
	}
	else {	// 성공
		SuccessEnding1();
	}
}

void Stage2() {
	init();

	// 게임 시작 << STAGE 2 >>
	DrawGameBox_1();
	stage2_screen();
	system("cls");

	DrawGameBox_1();

	// guest
	initGuest();	// 손님 초기화

	// CocktailMaking
	FirstSetBar();	// 쉐이커 초기화
	SetCocktailBar();	// 쉐이커 그리기

	// IngredientAndGlass
	initIngredient();				//재료구조체 초기화: 이름, 남은 갯수
	initIngredientCursor();			//커서구조체 초기화: 모드, 재료번호

	ingredientShelf();				//재료선반 출력
	printIngredient();				//재료들 출력
	printGlass();					//잔 출력
	ingredientBox();				//재료선택박스 0,0에 출력
	printKeyManual();

	while (DEFAULT_TIME - t >= 0) {
		//break;
		// 시간, 점수판, 대기 손님 수
		DrawTimeAndScore(t);

		// 손님 등장
		welcomeGuest();

		// 정은 추가
		if (bar_number >= 0) { // 앞에서 칵테일 제출했을 때
			Redrawsetting(bar_number); // 지우기
			RedrawOfferdBar(bar_number); // 해당 잔만 다시 출력
			bar_number = -1;
		}

		for (int i = 0; i < 3; i++) {
			DrawCockTail(makingBar[i]);	// 쉐이커
		}

		TelePhone(t);
		FeverTimeEffect();

		if (calling != -1) {
			ProccessKeyInput_ItemCall(calling);
		}
		else {
			ProcessKeyInput();
		}

		t++;
	}

	system("cls");
	DrawGameBox_1();
	if (score < 70000) {
		FailEnding();
	}
	else {
		SuccessEnding2();
	}
}

void Stage3() {
	init();

	// 게임 시작 << STAGE 3 >>
	DrawGameBox_1();
	stage3_screen();
	system("cls");

	DrawGameBox_1();

	// guest
	initGuest();	// 손님 초기화

	// CocktailMaking
	FirstSetBar();	// 쉐이커 초기화
	SetCocktailBar();	// 쉐이커 그리기

	// IngredientAndGlass
	initIngredient();				//재료구조체 초기화: 이름, 남은 갯수
	initIngredientCursor();			//커서구조체 초기화: 모드, 재료번호

	ingredientShelf();				//재료선반 출력
	printIngredient();				//재료들 출력
	printGlass();					//잔 출력
	ingredientBox();				//재료선택박스 0,0에 출력
	printKeyManual();

	while (DEFAULT_TIME - t >= 0) {
		if (waitingGuest > 3) break;

		// 시간, 점수판, 대기 손님 수
		DrawTimeAndScore(t);

		// 손님 등장
		welcomeGuest();

		// 정은 추가
		if (bar_number >= 0) { // 앞에서 칵테일 제출했을 때
			Redrawsetting(bar_number); // 지우기
			RedrawOfferdBar(bar_number); // 해당 잔만 다시 출력
			bar_number = -1;
		}

		for (int i = 0; i < 3; i++) {
			DrawCockTail(makingBar[i]);	// 쉐이커
		}

		TelePhone(t);
		FeverTimeEffect();

		if (calling != -1) {
			ProccessKeyInput_ItemCall(calling);
		}
		else {
			ProcessKeyInput();
		}

		t++;
	}

	system("cls");
	DrawGameBox_1();
	if (waitingGuest > 3 || score < 150000) {
		FailEnding();
	}
	else {
		SuccessEnding3();
	}
}