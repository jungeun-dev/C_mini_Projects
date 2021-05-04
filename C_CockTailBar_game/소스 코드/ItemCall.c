#include "ItemCall.h"

recievedCalls = 0;//how many recieved call
currentCall = 0;//0 no ring, 1 ringring
callStart = 0;//t when call start

calling = -1;//-1 not calling, 1 calling, 3 jinsang calling
qNum = 0;

bossTable = -1;//-1 no boss, else tableNum
bossStart = 0;//t when boss start working

void TelePhone(int t)
{
	COORD og = GetCurrentCursorPos();
	setcolor(10, 0);

	//if(t%3==0)
	if ((t >= (recievedCalls * 20 + (randInt(1, 5) + 15))) && currentCall == 0)
	{
		recievedCalls = recievedCalls + 1;
		callStart = t;
		currentCall = 1;
		SetCurrentCursorPos(2, 3);
		printf("링링~~ 전화왔습니다~!~! ☎☎☎☎☎");
	}
	if (t - callStart == 6)
	{
		callStart = 0;
		currentCall = 0;
		SetCurrentCursorPos(2, 3);
		printf("                                                                                     ");
	}
	else if (t - callStart < 6 && currentCall == 1)
	{
		SetCurrentCursorPos(2, 3);
		printf("                                                       ");
		SetCurrentCursorPos(2, 3);
		printf("링링~~ 전화왔습니다~!~! ");
		for (int i = 0; i < 5 + callStart - t; i++)
		{
			printf("☎");
		}
	}


	SetCurrentCursorPos(og.X, og.Y);
	setcolor(15, 0);
}

void IncomingCall()
{
	int level1 = 2;
	int level2[10] = { 1,1,1,1,2,2,3,3,3,3 };
	int level3[10] = { 0,0,0,1,1,2,3,3,4,4 };

	switch (level)
	{
	case 1:
		calling = level1;
		break;
	case 2:
		calling = level2[randInt(0, 9)];
		break;
	case 3:
		calling = level3[randInt(0, 9)];
		break;
	}
	//calling = 0;
	switch (calling)
	{
	case 0:
		BossCall();
		break;
	case 1:
		ChefCall();
		break;
	case 2:
		LogisticsCall();
		break;
	case 3:
		JinsangCall();
		break;
	case 4:
		RepairCall();
		break;
	}
}

void RecieveCall(int key)
{
	if ((key == 'z' || key == 'Z') && currentCall == 1)
	{
		COORD og = GetCurrentCursorPos();
		currentCall = 0;
		SetCurrentCursorPos(2, 3);
		printf("                                             ");

		IncomingCall();

		SetCurrentCursorPos(og.X, og.Y);
	}
}

void BossCall()
{
	COORD og = GetCurrentCursorPos();

	


	for (int i = 0; i < 3; i++)
	{
		if (makingBar[i].selected == 0 && guest[i].flag==1)
		{
			bossTable = i;
		}
	}
	if (bossTable == -1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (makingBar[i].selected == 0)
			{
				bossTable = i;
			}
		}
	}
	if (bossTable == -1)bossTable = randInt(0, 3);

	bossStart = t;

	PrintMiniGameFrame();
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);
	printf("사장님 : 일 잘하고 있지? 내가 %d번 테이블 좀 봐줄게 ^0^", bossTable + 1);
	Sleep(1000);
	ingredientShelf();
	printIngredient();
	ingredientBox();
	printGlass();

	PrintBossFace();

	SetCurrentCursorPos(og.X, og.Y);
}

void ChefCall()
{
	COORD og = GetCurrentCursorPos();

	PrintMiniGameFrame();
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);

	printf("주방장님 : 이거먹고 해 ~ ~  (플레이 시간이 10초 늘어난다.)");


	SetCurrentCursorPos(og.X, og.Y);
}

void LogisticsCall()
{
	COORD og = GetCurrentCursorPos();

	PrintMiniGameFrame();
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);
	printf("기사님 : 모든 재료 채워놨습니다. ^ 0 ^~~                  ");

	for (int i = 0; i < 16; i++) {
		ingredient[i].cnt = 10;
	}

	SetCurrentCursorPos(og.X, og.Y);
}

void JinsangCall()
{
	COORD og = GetCurrentCursorPos();

	qNum = randInt(0, 2);

	PrintMiniGameFrame();
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);

	switch (qNum)
	{
	case 0:
		PrintQuestion("어떤 할아버지 : 거기.. 대기 손님이 몇명이오..?", 0);
		break;
	case 1:
		PrintQuestion("어떤 외국인 : 안녕하세요우. 어륀이대공원녁(Children's Grand Park) 몇호숸이쥬?", 1);
		break;
	case 2:
		PrintQuestion("어떤 초등학생 : 죄송한데 '2 + 3 + 4'가 몇이에요?", 2);
		break;
	case 3:
		PrintQuestion("어떤 소프트웨어학과 학생: 저기 죄송한데,, 소설기 교수님 성함이 뭐죠?", 3);
		break;
	default:
		break;
	}

	SetCurrentCursorPos(og.X, og.Y);
}

void RepairCall()
{
	COORD og = GetCurrentCursorPos();

	PrintMiniGameFrame();
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);
	printf("수리기사 : 수리기사입니다. 수리하겠습니다. 뚝딱 뚝딱 ~_~   남은 시간 : %d", 3 - waiting);
	waiting = 0;


	SetCurrentCursorPos(og.X, og.Y);
}

void PrintMiniGameFrame() {

	COORD og = GetCurrentCursorPos();
	setcolor(15, 0);

	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong);
	printf("┌────────────────────────────────────────────────────────────────────────────────┐");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 1);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 2);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 3);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 4);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 5);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 6);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 7);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 8);
	printf("│                                                                                │");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong, MINIGAME_ORIGIN_Y_dong + 9);
	printf("└──────────────────────┐┌────────────────────────────────────────────────────────┘");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 23, MINIGAME_ORIGIN_Y_dong + 10);
	printf("│/");
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 23, MINIGAME_ORIGIN_Y_dong + 11);
	setcolor(10, 0);
	printf("☎");
	setcolor(15, 0);
	SetCurrentCursorPos(og.X, og.Y);
}


void PrintQuestion(char* q, int qNum)
{
	COORD og = GetCurrentCursorPos();

	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 2);
	printf("%s", q);

	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 4);
	switch (qNum)
	{
	case 0:
		printf("1. %d명   2. %d명   3. %d명   4. %d명", waitingGuest, waitingGuest + 1, waitingGuest + 3, waitingGuest + 2); break;
	case 1:
		printf("1. 7호선   2. 6호선   3. 4호선   4. 사실 분당선입니다."); break;
	case 2:
		printf("1. 7   2. 8   3. 9   4. 10"); break;
	case 3:
		printf("1. 최주연   2. 최준연   3. 최즌연   4. 최준언"); break;
	default: break;
	}

	SetCurrentCursorPos(og.X, og.Y);
}

void ProcessKeyInput_JinsangMiniGame() {
	int key;
	int correct = 0; // 0 = incorrect, 1 = correct

	for (int i = 0; i < 20; i++) {
		if (_kbhit() != 0) {
			key = _getch();
			if ((qNum == 0 && key == '1') || (qNum == 1 && key == '1') || (qNum == 2 && key == '3') || (qNum == 3 && key == '2'))
			{
				PrintMiniGameFrame();
				SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 2);
				printf("네 전화 끊을게용ㅎㅎ");
				Sleep(500);
				calling = -1;
				correct = 1;
				break;
			}
			else if (key == '1' || key == '2' || key == '3' || key == '4')
			{
				PrintMiniGameFrame();
				SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 2);
				printf("아니잖아욧!!!          ");
				Sleep(500);
				correct = 0;
				break;
			}
			else
			{
				PrintMiniGameFrame();
				SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 2);
				printf("1 ~ 4 중 정답을 고르세요!     ");
				Sleep(500);
				correct = 0;
				break;
			}
		}
		Sleep(50);
	}
	if (correct)
	{
		ingredientShelf();
		printIngredient();
		ingredientBox();
		printGlass();
	}
	else
	{
		switch (qNum)
		{
		case 0:
			PrintQuestion("어떤 할아버지 : 거기.. 대기 손님이 몇명이오..?", 0);
			break;
		case 1:
			PrintQuestion("어떤 외국인 : 안녕하세요우. 어륀이대공원녁(Children's Grand Park) 몇호숸이쥬?", 1);
			break;
		case 2:
			PrintQuestion("어떤 초등학생 : 죄송한데 '2 + 3 + 4'가 몇이에요?", 2);
			break;
		case 3:
			PrintQuestion("어떤 소프트웨어학과 학생: 저기 죄송한데,, 소설기 교수님 성함이 뭐죠?", 3);
			break;
		default:
			break;
		}
	}
}


void ProccessKeyInput_ItemCall(int calling)
{
	switch (calling) 
	{
	case 0:
		ProcessKeyInput_BossCall();
		break;
	case 1:
		ProccessKeyInput_ChefCall();
		break;
	case 2:
		ProccessKeyInput_LogisticsCall();
		break;
	case 3:
		ProcessKeyInput_JinsangMiniGame();
		break;
	case 4:
		ProcessKeyInput_RepairCall();
		break;
	}
	
}

void ProcessKeyInput_RepairCall()
{
	Sleep(1000);
	waiting += 1;
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);
	printf("수리기사 : 수리기사입니다. 수리하겠습니다. 뚝딱 뚝딱 ~ ~   남은 시간 : %d", 3 - waiting);
	if (waiting == 3)
	{
		calling = -1;
		waiting = 0;
		ingredientShelf();
		printIngredient();
		ingredientBox();
		printGlass();
	}
}

void ProccessKeyInput_ChefCall()
{
	for (int i = 0; i < 10; i++)
	{
		Sleep(100);
		t -= 1;
		if (t < 0)t = 0;
		DrawTimeAndScore(t);
	}


	calling = -1;
	ingredientShelf();
	printIngredient();
	ingredientBox();
	printGlass();
}

void ProccessKeyInput_LogisticsCall()
{
	PrintMiniGameFrame();
	SetCurrentCursorPos(MINIGAME_ORIGIN_X_dong + 2, MINIGAME_ORIGIN_Y_dong + 1);
	printf("기사님 : 모든 재료 채워놨습니다. ^ 0 ^~~                  ");
	Sleep(1000);

	calling = -1;
	ingredientShelf();
	printIngredient();
	ingredientBox();
	printGlass();
}

void PrintBossFace()
{
	int x = makingBar[bossTable].GlassStart_x;
	int y = makingBar[bossTable].GlassStart_y;

	
	SetCurrentCursorPos(x, y + 12);
	setcolor(12, 0);
	printf(" Boss Making!!");
	SetCurrentCursorPos(x, y + 13);
	printf("      %2d", 10 - (t - bossStart));
	setcolor(15, 0);
}

void EraseBossFace()
{
	int x = makingBar[bossTable].GlassStart_x;
	int y = makingBar[bossTable].GlassStart_y;

	SetCurrentCursorPos(x, y + 12);
	printf("                 ");
	SetCurrentCursorPos(x, y + 13);
	printf("                      ");
}

void ProcessKeyInput_BossCall() {


	int recipePriceD[10] = { 7000,11000,8000,8000,8000,9000,7000,7000,9000,7000 };
	int recipeIngredientD[10][10] = {
	  {0,0,0,10,10,13,-1,-1,-1,-1},
	  {0,0,0,0,6,6,8,9,13,13},
	  {1,1,1,1,6,13,13,-1,-1,-1},
	  {1,1,1,6,13,15,15,-1,-1,-1},
	  {2,2,2,2,12,14,-1,-1,-1,-1},
	  {2,2,6,11,11,11,11,14,-1,-1},
	  {3,3,7,10,13,-1,-1,-1,-1,-1},
	  {3,3,10,13,-1,-1,-1,-1,-1,-1},
	  {4,4,4,4,5,5,14,14,-1,-1},
	  {4,4,4,6,14,-1,-1,-1,-1,-1}
	};
	char recipeGlassD[10] = {
   'Q','E','E','W','E','E','E','Q','Q','Q'
	};


	int key;

	for (int i = 0; i < 20; i++)
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			SettingBarOnBoss(key);
		}
		if (i % 2 == 0 && makingBar[bossTable].guest.flag != 0)
		{
			makingBar[bossTable].in[(i + 1) / 2] = recipeIngredientD[makingBar[bossTable].guest.cocktail][(i + 1) / 2];
			DrawCockTail(makingBar[bossTable]);
		}
		PrintBossFace();
		Sleep(50);
	}


	if ((t - bossStart) % 3 == 0 && t - bossStart > 0)
	{
		int bar_boss = bossTable;
		if (makingBar[bar_boss].guest.flag != 0)
		{
			makingBar[bar_boss].glass = recipeGlassD[makingBar[bar_boss].guest.cocktail];

			CleanTable(bar_boss);
			Redrawsetting(bar_boss);
			PrintOfferedCockTail(bar_boss);
			bar_number = OfferCockTail(bar_boss);
		}
	}
	else if (t - bossStart == 10)
	{
		calling = -1;
		EraseBossFace();
		for (int i = 0; i < 3; i++) { Redrawsetting(i); }
		for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		SetCocktailBar();
	}


	

	
}

void SettingBarOnBoss(int key)
{
	int bar_num = -1;
	int idx;

	switch (key) {
	case TAB:
		idx = cursor[select_y][select_x].ingredient;
		if (ingredient[idx].cnt != 10) {
			minigameflag = 1;
			playMinigame();
		}
		break;

	case LEFT:
		if (canMoveTo(select_y, select_x - 1) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_x--;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;
	case RIGHT:
		if (canMoveTo(select_y, select_x + 1) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_x++;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;
	case UP:
		if (canMoveTo(select_y - 1, select_x) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_y--;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;
	case DOWN:
		if (canMoveTo(select_y + 1, select_x) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_y++;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;

	case Q:case 113:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		if (makingBar[bar_num].shacking_num < 10);
		else if (makingBar[bar_num].guest.flag == 0);
		else {
			makingBar[bar_num].glass = 'Q';
			CleanTable(bar_num);
			Redrawsetting(bar_num);
			PrintOfferedCockTail(bar_num);
			bar_number = OfferCockTail(bar_num);
		}
		break;
	case W:case 119:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		if (makingBar[bar_num].shacking_num < 10);
		else if (makingBar[bar_num].guest.flag == 0);
		else {
			makingBar[bar_num].glass = 'W';
			CleanTable(bar_num);
			PrintOfferedCockTail(bar_num);
			bar_number = OfferCockTail(bar_num);
		}
		break;
	case E:case 101:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		if (makingBar[bar_num].shacking_num < 10);
		else if (makingBar[bar_num].guest.flag == 0);
		else {
			makingBar[bar_num].glass = 'E';
			CleanTable(bar_num);
			PrintOfferedCockTail(bar_num);
			bar_number = OfferCockTail(bar_num);
		}
		break;

	case DELETE: case 68:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		for (int j = 0; j < 10; j++) {
			makingBar[bar_num].in[j] = -1;
		}
		makingBar[bar_num].shacking = 0;
		makingBar[bar_num].shacking_num = 0;
		makingBar[bar_num].in_count = 0;
		Redrawsetting(bar_num);
		DrawCockTail(makingBar[bar_num]);
		break;

	case ONE:
		if (bossTable != 0) {
			makingBar[0].selected = 1;
			makingBar[1].selected = 0;
			makingBar[2].selected = 0;
			for (int i = 0; i < 3; i++) { Redrawsetting(i); }
			for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		}
		break;
	case TWO:
		if (bossTable != 1) {
			makingBar[0].selected = 0;
			makingBar[1].selected = 1;
			makingBar[2].selected = 0;
			for (int i = 0; i < 3; i++) { Redrawsetting(i); }
			for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		}
		break;
	case THREE:
		if (bossTable != 2) {
			makingBar[0].selected = 0;
			makingBar[1].selected = 0;
			makingBar[2].selected = 1;
			for (int i = 0; i < 3; i++) { Redrawsetting(i); }
			for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		}
		break;

	case ENTER:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		//if (bar_num == -1) bar_num = 0;
		if (bar_num >= 0 && makingBar[bar_num].in_count < 10) {
			idx = selectIngredient();
			if (idx > -1) {
				makingBar[bar_num].in[makingBar[bar_num].in_count] = idx;
				makingBar[bar_num].in_count++;
				DrawCockTail(makingBar[bar_num]);
			}
		}
		break;

	case SPACE:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		makingBar[bar_num].shacking = 1;
		makingBar[bar_num].shacking_num++;
		DrawCockTail(makingBar[bar_num]);
		break;
	}
}

void Init_ItemCall()
{
	recievedCalls = 0;//how many recieved call
	currentCall = 0;//0 no ring, 1 ringring
	callStart = 0;//t when call start

	calling = -1;//-1 not calling, 1 calling, 3 jinsang calling
	qNum = 0;

	bossTable = -1;//-1 no boss, else tableNum
	bossStart = 0;//t when boss start working
}