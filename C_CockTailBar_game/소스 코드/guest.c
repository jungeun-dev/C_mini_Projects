#include "guest.h"

void initGuest() {
	int i;
	for (i = 0; i < 3; i++) {	// 손님 초기화
		guest[i].flag = 0;
		guest[i].num = i;
		guest[i].clear = 0;
	}
}

void welcomeGuest() {
	int i, min = 0, max = 0;
	int r = randInt(0, 2), rr;

	if (level == 1) {
		min = 9;
		max = 12;
	}
	else if (level == 2) {
		min = 8;
		max = 11;
	}
	else if (level == 3) {
		min = 6;
		max = 9;
	}

	// 새로운 손님 등장
	if (guestNum == 0 || t - lastGuestTime > randInt(min, max)) {
		lastGuestTime = t;

		if (guestNum == 3) {	// 손님이 꽉 차있을 경우
			waitingGuest++;
		}
		else {
			for (i = 0; i < 3; i++) {
				rr = (r + i) % 3;

				if (guest[rr].flag == 0) {
					guestNum++;

					guest[rr].flag = 1;
					if (level == 1)	guest[rr].cocktail = cockTail_level1[randInt(0, 3)];
					else if (level == 2) guest[rr].cocktail = cockTail_level2[randInt(0, 4)];
					else guest[rr].cocktail = cockTail_level3[randInt(0, 5)];
					makingBar[rr].guest = guest[rr];	// 테이블과 손님 연결 추가
					printGuestBoard(guest[rr]);
					break;
				}
			}
		}
	}
	// 대기 손님 등장
	if (guestNum < 3 && waitingGuest > 0) {
		waitingGuest--;
		for (i = 0; i < 3; i++) {
			rr = (r + i) % 3;

			if (guest[rr].flag == 0) {
				guestNum++;

				guest[rr].flag = 1;
				if (level == 1)	guest[rr].cocktail = cockTail_level1[randInt(0, 3)];
				else if (level == 2) guest[rr].cocktail = cockTail_level2[randInt(0, 4)];
				else guest[rr].cocktail = cockTail_level3[randInt(0, 5)];
				makingBar[rr].guest = guest[rr];	// 테이블과 손님 연결 추가
				printGuestBoard(guest[rr]);

				SetCurrentCursorPos(97, 3);
				if (level == 3 && waitingGuest >= 3) setcolor(4, 0);
				else setcolor(15, 0);
				printf("대기 손님 수 : %d\n", waitingGuest);

				break;
			}
		}
	}
}

void printGuestBoard(GUEST g) {
	switch (g.num)
	{
	case 0:
		printSpeechBubble(0, 4);
		printRecipe(g.cocktail, 2, 5);
		printOrder(g.cocktail, 11, 11);
		break;
	case 1:
		printSpeechBubble(38, 4);
		printRecipe(g.cocktail, 40, 5);
		printOrder(g.cocktail, 49, 11);
		break;
	case 2:
		printSpeechBubble(76, 4);
		printRecipe(g.cocktail, 78, 5);
		printOrder(g.cocktail, 87, 11);
		break;
	default:
		break;
	}
}

void removeGuestBoard(GUEST g) {
	switch (g.num)
	{
	case 0:
		for (int y = 4; y < 18; y++) {
			for (int x = 0; x < 37; x++) {
				SetCurrentCursorPos(x, y);
				printf(" ");
			}
		}
		break;
	case 1:
		for (int y = 4; y < 18; y++) {
			for (int x = 38; x < 75; x++) {
				SetCurrentCursorPos(x, y);
				printf(" ");
			}
		}
		break;
	case 2:
		for (int y = 4; y < 18; y++) {
			for (int x = 76; x < 113; x++) {
				SetCurrentCursorPos(x, y);
				printf(" ");
			}
		}
		break;
	default:
		break;
	}
}

void printSpeechBubble(int x, int y) {
	setcolor(15, 0);
	SetCurrentCursorPos(x, y);
	printf("┌───────────────────────────────────┐\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("└───────────────────────────────────┘\n");
	SetCurrentCursorPos(x, ++y);
	printf("┌───────────────────────────────────┐\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("│                                   │\n");
	SetCurrentCursorPos(x, ++y);
	printf("└───────────┐┌──────────────────────┘\n");
	SetCurrentCursorPos(x, ++y);
	printf("            │/                       \n");
	SetCurrentCursorPos(x, ++y);
	printf("         (●'v'●)                     \n");
}

void printRecipe(int cocktail, int x, int y) {
	switch (cocktail) {
	case 0:	// 마가리타
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("데킬라 1.5oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("트리플섹 1.0oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("라임즙 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q 글라스\n");
		break;
	case 1:	// 시에스타
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("데킬라 2oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("심플시럽 1.0oz 캄파리 0.5oz\n");
		SetCurrentCursorPos(x, ++y);
		printf("자몽주스 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("라임즙 1oz ");
		setcolor(15, 0);
		printf("E 글라스\n");
		break;
	case 2:	// 다이키리
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("럼 2oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("심플시럽 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("라임즙 1.0oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E 글라스\n");
		break;
	case 3:	// 모히토
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("럼 1.5oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("심플시럽 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("라임즙 0.5oz 탄산수 2.0oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("W 글라스\n");
		break;
	case 4:	// 에비에이션
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("진 2.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("마라스키노 리큐르 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("레몬즙 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E 글라스\n");
		break;
	case 5:	// 프렌치75
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("진 1.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("심플시럽 0.5oz 샴페인 2oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("레몬즙 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E 글라스\n");
		break;
	case 6:	// 코스모
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("보드카 1.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("트리플섹 0.5oz 크랜베리 주스 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("라임즙 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E 글라스\n");
		break;
	case 7:	// 카미카제
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("보드카 1.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("트리플섹 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("라임즙 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q 글라스\n");
		break;
	case 8:	// 골드러시
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("버번 2.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("꿀 1.0oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("레몬즙 1.0oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q 글라스\n");
		break;
	case 9:	// 위스키 사워
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("버번 1.5oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("심플시럽 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("레몬즙 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q 글라스\n");
		break;
	default:
		break;
	}
}

void printOrder(int cocktail, int x, int y) {
	SetCurrentCursorPos(x, y);

	switch (cocktail)
	{
	case 0:
		printf("마가리타 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("7000원");
		break;
	case 1:
		printf("시에스타 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("12000원");
		break;
	case 2:
		printf("다이키리 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("8000원");
		break;
	case 3:
		SetCurrentCursorPos(++x, y);
		printf("모히또 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("10000원");
		break;
	case 4:
		SetCurrentCursorPos(--x, y);
		printf("에비에이션 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("8000원");
		break;
	case 5:
		printf("프렌치75 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("10000원");
		break;
	case 6:
		SetCurrentCursorPos(++x, y);
		printf("코스모 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("8000원");
		break;
	case 7:
		printf("카미카제 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("7000원");
		break;
	case 8:
		printf("골드러시 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("9000원");
		break;
	case 9:
		SetCurrentCursorPos(x - 2, y);
		printf("위스키 사워 주세요!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("7000원");
		break;
	default:
		break;
	}
}