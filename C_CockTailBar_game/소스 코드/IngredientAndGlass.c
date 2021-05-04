#include "IngredientAndGlass.h"

int ARROW_CNT;

int arrow[4][5][5] = {			//È­»ìÇ¥ Àü¿ªº¯¼ö
	{{0,0,1,0,0},
	{0,0,0,1,0},
	{1,1,1,1,1},
	{0,0,0,1,0},
	{0,0,1,0,0}},
	{{0,0,1,0,0},
	{0,1,1,1,0},
	{1,0,1,0,1},
	{0,0,1,0,0},
	{0,0,1,0,0}},
	{{0,0,1,0,0},
	{0,1,0,0,0},
	{1,1,1,1,1},
	{0,1,0,0,0},
	{0,0,1,0,0}},
	{{0,0,1,0,0},
	{0,0,1,0,0},
	{1,0,1,0,1},
	{0,1,1,1,0},
	{0,0,1,0,0}}
};

void printArrow(COORD pos, int i) {					//playminigame¿¡¼­ È­»ìÇ¥Ãâ·Â
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			SetCurrentCursorPos(pos.X + 2 * x, pos.Y + y);
			if (arrow[i][y][x] == 1) printf("¡á");
			else printf("  ");
		}
	}
}

void playMinigame() {
	printMinigameframe();
	switch (level) {
	case 1: ARROW_CNT = 4; break;
	case 2: ARROW_CNT = 6; break;
	case 3: ARROW_CNT = 8; break;
	}

	srand((int)time(NULL));

	for (int i = 0; i < ARROW_CNT; i++) {		//È­»ìÇ¥·£´ý¹èÁ¤
		arrownum[i] = rand() % 4;
	}
	setcolor(15, 0);
	for (int i = 0; i < ARROW_CNT; i++) {		//È­»ìÇ¥Ãâ·Â
		pos.X = ARROW_ORIGIN_X + 12 * i;
		pos.Y = ARROW_ORIGIN_Y;
		printArrow(pos, arrownum[i]);
	}

	pass = 0;
	idx = 0;

}

void SettingBar_MINIGAME(int key)
{

	switch (key) {
	case RIGHT:
		userinput[idx] = 0;
		if (arrownum[idx] == userinput[idx]) {
			setcolor(11, 0);
			pos.X = ARROW_ORIGIN_X + 12 * idx;
			pos.Y = ARROW_ORIGIN_Y;
			printArrow(pos, arrownum[idx]);
			idx++;
			if (idx == ARROW_CNT) pass = 1;
		}
		else {
			setcolor(15, 0);
			for (int i = 0; i < idx; i++) {
				pos.X = ARROW_ORIGIN_X + 12 * i;
				pos.Y = ARROW_ORIGIN_Y;
				printArrow(pos, arrownum[i]);
			}
			idx = 0;
		}
		break;
	case UP:
		userinput[idx] = 1;
		if (arrownum[idx] == userinput[idx]) {
			setcolor(11, 0);
			pos.X = ARROW_ORIGIN_X + 12 * idx;
			pos.Y = ARROW_ORIGIN_Y;
			printArrow(pos, arrownum[idx]);
			idx++;
			if (idx == ARROW_CNT) pass = 1;
		}
		else {
			setcolor(15, 0);
			for (int i = 0; i < idx; i++) {
				pos.X = ARROW_ORIGIN_X + 12 * i;
				pos.Y = ARROW_ORIGIN_Y;
				printArrow(pos, arrownum[i]);
			}
			idx = 0;
		}
		break;
	case LEFT:
		userinput[idx] = 2;
		if (arrownum[idx] == userinput[idx]) {
			setcolor(11, 0);
			pos.X = ARROW_ORIGIN_X + 12 * idx;
			pos.Y = ARROW_ORIGIN_Y;
			printArrow(pos, arrownum[idx]);
			idx++;
			if (idx == ARROW_CNT) pass = 1;
		}
		else {
			setcolor(15, 0);
			for (int i = 0; i < idx; i++) {
				pos.X = ARROW_ORIGIN_X + 12 * i;
				pos.Y = ARROW_ORIGIN_Y;
				printArrow(pos, arrownum[i]);
			}
			idx = 0;
		}
		break;
	case DOWN:
		userinput[idx] = 3;
		if (arrownum[idx] == userinput[idx]) {
			setcolor(11, 0);
			pos.X = ARROW_ORIGIN_X + 12 * idx;
			pos.Y = ARROW_ORIGIN_Y;
			printArrow(pos, arrownum[idx]);
			idx++;
			if (idx == ARROW_CNT) pass = 1;
		}
		else {
			setcolor(15, 0);
			for (int i = 0; i < idx; i++) {
				pos.X = ARROW_ORIGIN_X + 12 * i;
				pos.Y = ARROW_ORIGIN_Y;
				printArrow(pos, arrownum[i]);
			}
			idx = 0;
		}
		break;
	default:
		break;
	}


	if (pass == 1)
	{
		ingredient[cursor[select_y][select_x].ingredient].cnt = 10;
		setcolor(15, 0);
		ingredientShelf();
		printIngredient();
		printGlass();
		ingredientBox();
		minigameflag = 0;
	}


}

void printMinigameframe() {
	COORD pos;
	pos.X = MINIGAME_ORIGIN_X;
	pos.Y = MINIGAME_ORIGIN_Y;
	setcolor(15, 0);
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                                                                                              ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
}

void ingredientBox() {    //Àç·á¼±ÅÃ³×¸ðÄ­ Ãâ·Â
	COORD pos;
	pos.X = BOX_ORIGIN_X + select_x * 14;
	pos.Y = BOX_ORIGIN_Y + select_y * 3;
	setcolor(15, 0);
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦Ç¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Á");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦­");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦­");
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ã");
	pos.X += 9;
	pos.Y -= 2;
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦­");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦­");

}

void deleteIngredientBox() {    //Àç·á¼±ÅÃ³×¸ðÄ­ »èÁ¦
	COORD pos;
	pos.X = BOX_ORIGIN_X + select_x * 14;
	pos.Y = BOX_ORIGIN_Y + select_y * 3;
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("          ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf(" ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf(" ");
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("          ");
	pos.X += 9;
	pos.Y -= 2;
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf(" ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf(" ");

}

void ingredientShelf() {
	COORD pos = { SHELF_X, SHELF_Y };
	setcolor(15, 0);
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢   Base Liquor             ¦¢   Sweet                   ¦¢   Sour                    ¦¢   Glass                   ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢                           ¦¢                           ¦¢                           ¦¢                           ¦¢");
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

}

void printGlass() {
	COORD pos;
	pos.X = GLASS_ORIGIN_X + 1;
	pos.Y = GLASS_ORIGIN_Y + 1;
	setcolor(15, 0);
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("           ¦¢  ¦¢ ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("           ¦¢  ¦¢ ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¢  ¦¢       ¦¢  ¦¢ ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("¦¦¦¡¦¡¦¥       ¦¦¦¡¦¡¦¥ ");
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("  Q          W  ");
	pos.Y += 2;
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf(" ¡¬£¯");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("  ¦¢ ");
	SetCurrentCursorPos(pos.X, pos.Y++);
	printf("  ¦ª ");
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("  E");
}

int canMoveTo(int y, int x) {
	if (y < 0 || x < 0 || y > 3 || x > 5) return 0;
	if (cursor[y][x].mode == -1) return 0;
	else return 1;
}

void initIngredient() {
	strcpy(ingredient[0].str, "µ¥");
	strcpy(ingredient[1].str, "·³");
	strcpy(ingredient[2].str, "Áø");
	strcpy(ingredient[3].str, "º¸");
	strcpy(ingredient[4].str, "¹ö");

	strcpy(ingredient[5].str, "²Ü");
	strcpy(ingredient[6].str, "½É");
	strcpy(ingredient[7].str, "Å©");
	strcpy(ingredient[8].str, "Ä¯");
	strcpy(ingredient[9].str, "ÀÚ");
	strcpy(ingredient[10].str, "Æ®");
	strcpy(ingredient[11].str, "¼¤");
	strcpy(ingredient[12].str, "¸¶");

	strcpy(ingredient[13].str, "¶ó");
	strcpy(ingredient[14].str, "·¹");
	strcpy(ingredient[15].str, "Åº");

	for (int i = 0; i < 16; i++) {
		if (i < 5) ingredient[i].color = 13;
		else if (i < 13) ingredient[i].color = 14;
		else ingredient[i].color = 3;
		ingredient[i].cnt = 10;
	}
}

void initIngredientCursor() {
	cursor[0][0].mode = 1;
	cursor[1][5].mode = -1;
	cursor[2][1].mode = -1;
	cursor[2][4].mode = -1;
	cursor[2][5].mode = -1;
	cursor[3][0].mode = -1;
	cursor[3][1].mode = -1;
	cursor[3][4].mode = -1;
	cursor[3][5].mode = -1;
	cursor[0][0].ingredient = 0;
	cursor[0][1].ingredient = 1;
	cursor[1][0].ingredient = 2;
	cursor[1][1].ingredient = 3;
	cursor[2][0].ingredient = 4;
	cursor[0][2].ingredient = 5;
	cursor[0][3].ingredient = 6;
	cursor[1][2].ingredient = 7;
	cursor[1][3].ingredient = 8;
	cursor[2][2].ingredient = 9;
	cursor[2][3].ingredient = 10;
	cursor[3][2].ingredient = 11;
	cursor[3][3].ingredient = 12;
	cursor[0][4].ingredient = 13;
	cursor[0][5].ingredient = 14;
	cursor[1][4].ingredient = 15;
}

void printIngredient() {
	COORD pos;
	pos.X = SHELF_X + 5;
	pos.Y = SHELF_Y + 3;
	//»¡°­(Base): 13 / ³ë¶û(Sweet): 14 / ÆÄ¶û(Sour): 3

	setcolor(13, 0);
	int idx = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 2; i++) {
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j);
			printf("%s", ingredient[idx].str);
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j + 1);
			printf("     ");
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j + 1);
			printf("%d/10", ingredient[idx].cnt);
			idx++;
			if (idx == 5) break;
		}
	}
	setcolor(14, 0);
	pos.X = SHELF_X + 33;
	pos.Y = SHELF_Y + 3;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 2; i++) {
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j);
			printf("%s", ingredient[idx].str);
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j + 1);
			printf("     ");
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j + 1);
			printf("%d/10", ingredient[idx].cnt);
			idx++;
			if (idx == 13) break;
		}
	}
	setcolor(3, 0);
	pos.X = SHELF_X + 61;
	pos.Y = SHELF_Y + 3;

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j);
			printf("%s", ingredient[idx].str);
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j + 1);
			printf("     ");
			SetCurrentCursorPos(pos.X + 14 * i, pos.Y + 3 * j + 1);
			printf("%d/10", ingredient[idx].cnt);
			idx++;
			if (idx == 16) break;
		}
	}

	setcolor(15, 0);

}