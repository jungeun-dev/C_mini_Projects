#include "time.h"

void DrawTimeAndScore(int t)
{
	int time45 = (DEFAULT_TIME - t + 1) / 2;
	setcolor(15, 0);
	SetCurrentCursorPos(0, 0);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖忙式式式式式式式式式式式忖");
	SetCurrentCursorPos(0, 1);
	printf("弛  TIME  ");
	for (int i = 0; i < time45; i++)printf("﹥");
	for (int i = time45; i < 45; i++)printf("  ");
	printf("弛弛 %7d 錳弛", score);
	SetCurrentCursorPos(0, 2);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎戌式式式式式式式式式式式戎");
	SetCurrentCursorPos(97, 3);
	if (level == 3 && waitingGuest >= 3) setcolor(4, 0);
	printf("渠晦 槳椒 熱 : %d\n", waitingGuest);
}