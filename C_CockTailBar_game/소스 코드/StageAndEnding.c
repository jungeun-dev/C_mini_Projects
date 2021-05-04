#include "StageAndEnding.h"

void stage1_screen() {
	int x = 25, y = 15, i, key;

	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("■■■■■  ■■■■■  ■■■■■  ■■■■■  ■■■■■"); printf("      ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■              ■      ■      ■  ■          ■"); printf("              ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■■■■■      ■      ■■■■■  ■    ■■  ■■■■■"); printf("      ■\n");
	SetCurrentCursorPos(x, y++);
	printf("        ■      ■      ■      ■  ■      ■  ■"); printf("              ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■■■■■      ■      ■      ■  ■■■■■  ■■■■■"); printf("      ■\n");
	
	y += 2;
	SetCurrentCursorPos(x + 30, y++);
	printf("목	표\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("<< 30000원 이상 달성하라! >>\n");
	
	y += 2;
	SetCurrentCursorPos(x + 20, y++);
	printf("- 미니게임 화살표 개수 4개\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("- 전화 : 물류기사 등장\n");

	x += 22;
	y += 6;
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ GAME START ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("        ENTER!!");

	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				return;
			}
		}
	}
}

void stage2_screen() {
	int x = 25, y = 15, i, key;

	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("■■■■■  ■■■■■  ■■■■■  ■■■■■  ■■■■■"); printf("  ■■■■■\n");
	SetCurrentCursorPos(x, y++);
	printf("■              ■      ■      ■  ■          ■"); printf("                  ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■■■■■      ■      ■■■■■  ■    ■■  ■■■■■"); printf("  ■■■■■\n");
	SetCurrentCursorPos(x, y++);
	printf("        ■      ■      ■      ■  ■      ■  ■"); printf("          ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■■■■■      ■      ■      ■  ■■■■■  ■■■■■"); printf("  ■■■■■\n");

	y += 2;
	SetCurrentCursorPos(x + 30, y++);
	printf("목	표\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("<< 70000원 이상 달성하라! >>\n");

	y += 2;
	SetCurrentCursorPos(x + 20, y++);
	printf("- 미니게임 화살표 개수 6개\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("- 전화 : 물류기사/주방장 등장\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("         진상손님 등장\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("- 팁 : 1000원 ~ 3000원\n");

	x += 22;
	y += 6;
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ GAME START ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("        ENTER!!");

	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				return;
			}
		}
	}
}

void stage3_screen() {
	int x = 25, y = 15, i, key;

	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("■■■■■  ■■■■■  ■■■■■  ■■■■■  ■■■■■"); printf("  ■■■■■\n");
	SetCurrentCursorPos(x, y++);
	printf("■              ■      ■      ■  ■          ■"); printf("                  ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■■■■■      ■      ■■■■■  ■    ■■  ■■■■■"); printf("  ■■■■■\n");
	SetCurrentCursorPos(x, y++);
	printf("        ■      ■      ■      ■  ■      ■  ■"); printf("                  ■\n");
	SetCurrentCursorPos(x, y++);
	printf("■■■■■      ■      ■      ■  ■■■■■  ■■■■■"); printf("  ■■■■■\n");

	y += 2;
	SetCurrentCursorPos(x + 30, y++);
	printf("목	표\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("<< 150000원 이상 달성하라! >>\n");

	y += 2;
	SetCurrentCursorPos(x + 20, y++);
	printf("- 미니게임 화살표 개수 8개\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("- 전화 : 물류기사/주방장/사장님 등장\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("         진상손님/보수공사업체 등장\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("- 팁 : 2000원 ~ 5000원\n");
	SetCurrentCursorPos(x + 20, y++);
	printf("- 대기 손님이 3명을 초과할 경우 GAME OVER\n");

	x += 22;
	y += 6;
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ GAME START ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("        ENTER!!");

	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				return;
			}
		}
	}
}

void man1(int x, int y) {
	SetCurrentCursorPos(x, y++);
	printf(" ○\n");
	SetCurrentCursorPos(x, y++);
	printf(" ｜\n");
	SetCurrentCursorPos(x, y++);
	printf("/｜＼\n");
	SetCurrentCursorPos(x, y++);
	printf(" /＼\n");
}
void man2(int x, int y) {
	SetCurrentCursorPos(x, y++);
	printf(" ○\n");
	SetCurrentCursorPos(x, y++);
	printf(" ｜\n");
	SetCurrentCursorPos(x, y++);
	printf("/｜＼\n");
	SetCurrentCursorPos(x, y++);
	printf(" II\n");
}
void removeMan(int x, int y) {
	SetCurrentCursorPos(x, y++);
	printf("        \n");
	SetCurrentCursorPos(x, y++);
	printf("        \n");
	SetCurrentCursorPos(x, y++);
	printf("        \n");
	SetCurrentCursorPos(x, y++);
	printf("        \n");
}

void FailEnding() {
	int i, x, y, key;
	char* fail1 = "사장님 : ", * fail2 = "! ", * fail3 = "넌 설거지나 해!";

	setcolor(15, 0);
	SetCurrentCursorPos(50, 13);
	printf("SCORE : %d원", score);
	Sleep(1000);
	for (i = 0; i < 3; i++) {
		SetCurrentCursorPos(56, 15 + i);
		printf("·");
		Sleep(1000);
	}

	PlaySound(TEXT("typewriter.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetCurrentCursorPos(40, 19);
	for (i = 0; i < strlen(fail1); i++) {
		printf("%c", fail1[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(Name); i++) {
		printf("%c", Name[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(fail2); i++) {
		printf("%c", fail2[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(fail3); i++) {
		printf("%c", fail3[i]);
		Sleep(100);
	}
	PlaySound(NULL, 0, 0);

	Sleep(1000);

	for (i = 0; i < 10; i++) {
		x = 64 - i;
		y = 23;
		removeMan(x, y);
		if (i % 2 == 0) {
			man1(x, y);
		}
		else {
			man2(x, y);
		}
		Sleep(250);
	}
	Sleep(750);

	removeMan(x, y);
	setcolor(4, 0);

	PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetCurrentCursorPos(x - 3, y);
	printf("GAME OVER");
	SetCurrentCursorPos(x, y + 2);
	printf("○TL");
	Sleep(6000);
	PlaySound(NULL, 0, 0);

	x = 47;
	y = 40;
	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ RE START ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("      ENTER!!");
	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				level = 0;
				break;
			}
		}
	}
	system("cls");
}

void SuccessEnding1() {
	int i, x, y, key;
	char* success1 = "사장님 : ", * success2 = "! 자네 바텐더에 소질있구만!";

	setcolor(15, 0);
	SetCurrentCursorPos(50, 13);
	printf("SCORE : %d원", score);
	Sleep(1000);
	for (i = 0; i < 3; i++) {
		SetCurrentCursorPos(56, 15 + i);
		printf("·");
		Sleep(1000);
	}

	PlaySound(TEXT("typewriter.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetCurrentCursorPos(35, 19);
	for (i = 0; i < strlen(success1); i++) {
		printf("%c", success1[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(Name); i++) {
		printf("%c", Name[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(success2); i++) {
		printf("%c", success2[i]);
		Sleep(100);
	}
	PlaySound(NULL, 0, 0);

	Sleep(1000);

	for (i = 0; i < 10; i++) {
		x = 64 - i;
		y = 23;
		removeMan(x, y);
		if (i % 2 == 0) {
			man1(x, y);
		}
		else {
			man2(x, y);
		}
		Sleep(250);
	}
	Sleep(750);
	removeMan(x, y);

	PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	setcolor(6, 0);
	SetCurrentCursorPos(x, y++);
	printf(" ○\n");
	SetCurrentCursorPos(x - 1, y++);
	printf("＼｜/\n");
	SetCurrentCursorPos(x, y++);
	printf(" ｜\n");
	SetCurrentCursorPos(x, y++);
	printf(" /＼\n");
	SetCurrentCursorPos(x - 5, y + 1);
	printf("Congratulation!");
	Sleep(3000);
	PlaySound(NULL, 0, 0);

	x = 47;
	y = 40;
	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ NEXT STAGE ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("        ENTER!!");

	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				level = 2;
				break;
			}
		}
	}
	system("cls");
}

void SuccessEnding2() {
	int i, x, y, key;
	char* success1 = "사장님 : ", * success2 = "! 아주 훌륭하군! 매니저로 일해보는게 어떤가?";

	setcolor(15, 0);
	SetCurrentCursorPos(50, 13);
	printf("SCORE : %d원", score);
	Sleep(1000);
	for (i = 0; i < 3; i++) {
		SetCurrentCursorPos(56, 15 + i);
		printf("·");
		Sleep(1000);
	}

	PlaySound(TEXT("typewriter.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetCurrentCursorPos(35, 19);
	for (i = 0; i < strlen(success1); i++) {
		printf("%c", success1[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(Name); i++) {
		printf("%c", Name[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(success2); i++) {
		printf("%c", success2[i]);
		Sleep(100);
	}
	PlaySound(NULL, 0, 0);

	Sleep(1000);

	for (i = 0; i < 10; i++) {
		x = 64 - i;
		y = 23;
		removeMan(x, y);
		if (i % 2 == 0) {
			man1(x, y);
		}
		else {
			man2(x, y);
		}
		Sleep(250);
	}
	Sleep(750);
	removeMan(x, y);

	PlaySound(TEXT("success.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	setcolor(6, 0);
	SetCurrentCursorPos(x, y++);
	printf(" ○\n");
	SetCurrentCursorPos(x - 1, y++);
	printf("＼｜/\n");
	SetCurrentCursorPos(x, y++);
	printf(" ｜\n");
	SetCurrentCursorPos(x, y++);
	printf(" /＼\n");
	SetCurrentCursorPos(x - 5, y + 1);
	printf("Congratulation!");
	Sleep(3000);
	PlaySound(NULL, 0, 0);

	x = 47;
	y = 40;
	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ NEXT STAGE ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("        ENTER!!");

	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				level = 3;
				break;
			}
		}
	}
	system("cls");
}

void SuccessEnding3() {
	int i, x, y, key;
	char* success1 = "사장님 : ", * success2 = "... ... ... ", * success3 = "... 내가 사장이 되다니!";

	setcolor(15, 0);
	SetCurrentCursorPos(50, 13);
	printf("SCORE : %d원", score);
	Sleep(1000);
	for (i = 0; i < 3; i++) {
		SetCurrentCursorPos(56, 15 + i);
		printf("·");
		Sleep(1000);
	}

	PlaySound(TEXT("typewriter.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetCurrentCursorPos(35, 19);
	for (i = 0; i < strlen(success1); i++) {
		printf("%c", success1[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(success2); i++) {
		printf("%c", success2[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(Name); i++) {
		printf("%c", Name[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(success3); i++) {
		printf("%c", success3[i]);
		Sleep(100);
	}
	PlaySound(NULL, 0, 0);

	Sleep(1000);

	for (i = 0; i < 10; i++) {
		x = 64 - i;
		y = 23;
		removeMan(x, y);
		if (i % 2 == 0) {
			man1(x, y);
		}
		else {
			man2(x, y);
		}
		Sleep(250);
	}
	Sleep(750);
	removeMan(x, y);

	PlaySound(TEXT("Congratulations.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	setcolor(6, 0);
	SetCurrentCursorPos(x, y++);
	printf(" ○\n");
	SetCurrentCursorPos(x - 1, y++);
	printf("＼｜/\n");
	SetCurrentCursorPos(x, y++);
	printf(" ｜\n");
	SetCurrentCursorPos(x, y++);
	printf(" /＼\n");
	SetCurrentCursorPos(x - 5, y + 1);
	printf("Congratulation!");
	Sleep(6000);

	x = 47;
	y = 40;
	setcolor(15, 0);
	SetCurrentCursorPos(x, y++);
	printf("┎━━━━━━━━━━━━━━━━━┒");
	SetCurrentCursorPos(x, y++);
	printf("┃ ");
	setcolor(13, 0);
	printf(" ▶ RE START ◀");
	setcolor(15, 0);
	printf(" ┃");
	SetCurrentCursorPos(x, y++);
	printf("┖━━━━━━━━━━━━━━━━━┚");
	SetCurrentCursorPos(x, y++);
	printf("      ENTER!!");
	while (1) {
		if (_kbhit() != 0) {
			key = _getch();
			if (key == 13) {
				PlaySound(NULL, 0, 0);
				level = 0;
				break;
			}
		}
	}
	system("cls");
}