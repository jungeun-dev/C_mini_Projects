#include<Windows.h>
#include<time.h>
#include<stdio.h> 
#include<stdlib.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#pragma once

// 구조체
typedef struct guest {
	int num;
	int cocktail;
	int flag;
	int clear;
} GUEST;

typedef struct makingbar {
	GUEST guest;
	int guest_in; // 손님 유무
	int Tablenum;
	int GlassStart_x;
	int GlassStart_y;
	int selected; // 해당자리에서 만들기 시작할때 1 
	int in[10];//들어있는 재료들
	int in_count; //들어있는 재료들 총 개수
	int shacking; // shacking 유무
	int shacking_num;// shacking 횟수
	char glass;
}MAKINGBAR;

typedef struct ingredient {
	char str[10];
	int cnt;
	short color;
}INGREDIENT;

typedef struct ingredientcursor {
	int mode;
	int ingredient;
}INGREDIENTCURSOR;

typedef struct gamestart {
	int origin_x;
	int origin_y;
	int selected;
}GAMESTART;

// 전역 변수
extern GUEST guest[3];
extern MAKINGBAR makingBar[3];
extern GAMESTART gamest[2];

extern int gamestartflag;
extern int minigameflag;		

extern int score;
extern int level;

//정은
extern int cockTail_level1[4];
extern int cockTail_level2[5];
extern int cockTail_level3[6];

// 함수 선언
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
void setcolor(unsigned short text, unsigned short back);
void RemoveCursor();
int randInt(int min, int max);
void ProcessKeyInput();