#include "GameExplanation.h"

void user_guide() {

	int idx = 0;
	int key;


	printpage(idx);
	
	printPageDirection(idx);
	while (1) {
		key = _getch();
		switch (key) {
		case LEFT:
			if (idx == 0) break;
			system("cls");
			DrawGameBox_1();
			idx--;
			printpage(idx);
			printPageDirection(idx);
			break;
		case RIGHT:
			if (idx == 4) break;
			system("cls");
			DrawGameBox_1();
			idx++;
			printpage(idx);
			printPageDirection(idx);
			break;
		case ENTER:
			if (idx != 4) break;
			system("cls");
			DrawGameBox_1();
			gamestartflag = 1;
			return;
		}
	}


}
void printpage(int idx) {
	setcolor(15, 0);
	switch (idx) {
	case 0: page1(); break;
	case 1: page2(); break;
	case 2: page3(); break;
	case 3: page4(); break;
	case 4: page5(); break;
	}
}
void printPageDirection(int idx) {
	setcolor(15, 0);
	switch (idx) {
	case 0:
		SetCurrentCursorPos(90, 43);
		printf("NEXT PAGE ▶");
		break;
	case 1: case 2: case 3:
		SetCurrentCursorPos(70, 43);
		printf("◀ PREVIOUS PAGE");
		SetCurrentCursorPos(90, 43);
		printf("NEXT PAGE ▶");
		break;
	case 4:
		SetCurrentCursorPos(70, 43);
		printf("◀ PREVIOUS PAGE");
		SetCurrentCursorPos(87, 42);
		printf("┎━━━━━━━━━━━━━━━━━━┒");
		SetCurrentCursorPos(87, 43);
		printf("┃ ");
		setcolor(13, 0);
		printf("▶ GAME START ◀");
		setcolor(15, 0);
		printf(" ┃ ");
		SetCurrentCursorPos(87, 44);
		printf("┖━━━━━━━━━━━━━━━━━━┚");
		SetCurrentCursorPos(87, 45);
		printf("      ENTER!!");
		break;
	}
}

void page1() {
	COORD pos;
	pos.X = 14;
	pos.Y = 26;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("1. ");
	setcolor(11, 0);
	printf("숫자키");
	setcolor(15, 0);
	printf(" : 손님 앞으로 이동할 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("2. ");
	setcolor(11, 0);
	printf("방향키");
	setcolor(15, 0);
	printf(" : 재료를 변경할 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("3. ");
	setcolor(11, 0);
	printf("엔터");
	setcolor(15, 0);
	printf(" : 재료를 선택해 쉐이커에 담자! 한 번당 0.5oz를 담을 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("4. ");
	setcolor(11, 0);
	printf("D키");
	setcolor(15, 0);
	printf(" : 재료를 잘못 담았다면 D키로 쉐이커를 초기화하자!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("5. ");
	setcolor(11, 0);
	printf("TAB키");
	setcolor(15, 0);
	printf(" : 재료가 부족할 때 미니게임을 하고 재료를 채울 수 있다!");
	
	printCocktailEx(15, 8);
	printShakerEx(65, 8);
	
}

void page2() {
	COORD pos;
	pos.X = 14;
	pos.Y = 12;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("6. ");
	setcolor(11, 0);
	printf("스페이스바");
	setcolor(15, 0);
	printf(" : 재료를 다 담고 연타하여 쉐이커를 10번 흔들자!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("7. ");
	setcolor(11, 0);
	printf("Q, W, E키");
	setcolor(15, 0);
	printf(" : 알맞은 글라스를 골라 서빙하자!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("8. ");
	setcolor(11, 0);
	printf("Z키");
	setcolor(15, 0);
	printf(" : 랜덤 발신자의 전화를 받을 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("   단, 좋은 전화인지 나쁜 전화인지 아무도 모른다!");
	
	printShakerEx(75, 10);
	for (int y = 0; y < 7; y++) {
		SetCurrentCursorPos(90, 15 + y);
		printf("■");
	}
	pos.X = 75;
	pos.Y = 23;
	SetCurrentCursorPos(pos.X,pos.Y);
	printf("  ★Making★  Shaking!!");
	pos.X = 70;
	pos.Y = 25;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("┌─────────────────────┐");
	SetCurrentCursorPos(pos.X, ++pos.Y);
	printf("│     SPACE BAR !!    │");
	SetCurrentCursorPos(pos.X, ++pos.Y);
	printf("└─────────────────────┘");


	pos.X = 20;
	pos.Y = 32;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("            │  │ ");
	SetCurrentCursorPos(pos.X, ++pos.Y);
	printf("            │  │        ＼／");
	SetCurrentCursorPos(pos.X, ++pos.Y);
	printf("│  │        │  │         │");
	SetCurrentCursorPos(pos.X, ++pos.Y);
	printf("└──┘        └──┘         ┴");
	SetCurrentCursorPos(pos.X, ++pos.Y);
	printf("  Q           W          E");

}

void page3() {
	COORD pos;
	pos.X = 14;
	pos.Y = 12;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("   사장님, 물류센터, 주방장에게서 온 전화는 게임에 도움이 되는 좋은 전화, ");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("   진상 손님들과 보수공사업체의 전화는 게임의 원활한 진행을 방해하는 나쁜 전화이다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("   써먹기 나름이니 전략적으로 사용하자");
	setcolor(14, 0);
	printf(" ♪(^∇^*)");
	setcolor(15, 0);
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("9. 연속 세 잔을 완벽히 만들면 10초간 ");
	setcolor(12, 0);
	printf("♨FEVER TIME♨");
	setcolor(15, 0);
	printf("이 주어진다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("   FEVER TIME에는 모든 점수의 1.5배를 획득할 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("   잃는 점수도 1.5배가 되니 주의하자");
	setcolor(14, 0);
	printf(" q(>▽<q)");
	pos.Y += 4;
	setcolor(15, 0);
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("10. STAGE 2부터는 칵테일을 완벽히 완성시 50%%의 확률로 손님에게서 팁을 받을 수 있다!");
	setcolor(15, 0);
}

void page4() {
	COORD pos;
	pos.X = 17;
	pos.Y = 12;
	SetCurrentCursorPos(pos.X, pos.Y);
	setcolor(10, 0);
	printf("☎ 전화 아이템 ☎");
	setcolor(15, 0);
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("사장님 : 10초간 한 테이블을 맡아서 손님을 받아준다");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("주방장 : 남은 시간을 10초 늘려준다");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("물류기사 : 모든 재료들을 꽉 채워준다");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("진상 손님들 : 질문에 대답할 때까지 게임 진행을 방해한다");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("보수 공사 업체 : 3초간 플레이어의 행동을 중단한다");
}

void page5() {
	COORD pos;
	pos.X = 17;
	pos.Y = 12;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("1단계를 성공하면 설거지를 면제할 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("2단계를 성공하면 매니저로 승급할 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("3단계를 성공하면 가게를 인수할 수 있다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("하지만 단계가 올라갈수록 시간은 빨라지고 목표 금액은 높아지고");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("난이도가 올라감을 명심하도록!! ");
	setcolor(12, 0);
	printf("ψ(｀∇´)ψ");
	setcolor(15, 0);
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("한 번이라도 실패한다면 설거지만 해야 하는 운명에 놓이게 된다!");
	pos.Y += 4;
	SetCurrentCursorPos(pos.X, pos.Y);
	printf("준비가 다 되었다면, 지금 바로 바를 인수하러 가보자~~ GOGO~");
}

void printCocktailEx(int x, int y) {
	printSpeechBubble(x, y);
	x += 2;
	y += 1;
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
	x += 9;
	y += 3;
	SetCurrentCursorPos(x, y);
	printf("마가리타 주세요!");
	SetCurrentCursorPos(x + 5, y + 2);
	printf("7000원");
}

void printShakerEx(int x, int y) {
	SetCurrentCursorPos(x, y);
	for (int j = 0; j < 11; j++) {
		SetCurrentCursorPos(x, ++y);
		printf("┃           ┃");
	}
	SetCurrentCursorPos(x, ++y);
	printf("┗━━━━━━━━━━━┛");
	setcolor(13, 0);
	x += 2;
	SetCurrentCursorPos(x, --y);
	printf("데■■■데");
	SetCurrentCursorPos(x, --y);
	printf("데■■■데");
	SetCurrentCursorPos(x, --y);
	printf("데■■■데");
	setcolor(14, 0);
	SetCurrentCursorPos(x, --y);
	printf("트■■■트");
	SetCurrentCursorPos(x, --y);
	printf("트■■■트");
	setcolor(3, 0);
	SetCurrentCursorPos(x, --y);
	printf("라■■■라");
	setcolor(15, 0);
}
