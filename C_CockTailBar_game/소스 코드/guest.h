#include "basic.h"
#include "time.h"

#pragma once

extern int guestNum;
extern int lastGuestTime;	// 마지막 손님이 온 시간

void initGuest();
void welcomeGuest();
void printGuestBoard(GUEST g);
void printSpeechBubble(int x, int y);
void printRecipe(int cocktail, int x, int y);
void printOrder(int cocktail, int x, int y);
void removeGuestBoard(GUEST g);