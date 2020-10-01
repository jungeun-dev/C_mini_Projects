#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "block.h"
#include <conio.h>

#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 120
#define ACROSS_UP_RIGHT 101
#define ACROSS_DOWN_LEFT 122
#define ACROSS_UP_LEFT 113
#define ACROSS_DOWN_RIGHT 99
#define COUNTER_CLOCKWISE 106
#define ROTATION_180 107

void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void); 
void ShowBlock(char blockInfo[4][4]);
void DeleteBlock(char blockInfo[4][4]);
void movement(int Direction, int block_id, COORD start);
void RemoveCursor(void);
void ShiftRight(void);
void ShiftAcrossDownRight(void);
void ShiftAcrossUpRight(void);
void ShiftLeft(void);
void ShiftAcrossUpLeft(void);
void ShiftAcrossDownLeft(void);
void BlockDown(void);
void BlockUp(void);
void RotateBlock(void);
void Movement(int key);

int block_id;
int curPosX = 0, curPosY = 0;

int main() {
    srand((unsigned int)time(NULL));
    RemoveCursor();
    block_id = rand() % 28;
    int key;
    ShowBlock(blockModel[block_id]);
    while (1) {
        while (!_kbhit()) {
            Sleep(200);
        }
        key = _getch();
        Movement(key);           
    }

    getchar();

    return 0;
}

void Movement(int key) {
    switch (key) {
    case LEFT:
        ShiftLeft();
        break;

    case RIGHT:
        ShiftRight();
        break;
    case UP:
        BlockUp();
        break;
    case DOWN:
        BlockDown();
        break;
    case ACROSS_UP_RIGHT:
        ShiftAcrossUpRight();
        break;
    case ACROSS_DOWN_RIGHT:
        ShiftAcrossDownRight();
        break;
    case ACROSS_UP_LEFT:
        ShiftAcrossUpLeft();
        break;
    case ACROSS_DOWN_LEFT:
        ShiftAcrossDownLeft();
        break;
    case COUNTER_CLOCKWISE:
        RotateBlock();
        break;
    case ROTATION_180:
        RotateBlock();
        RotateBlock();
        break;
    }
}
void RotateBlock(void) {
    int block_base;
    int i;
    DeleteBlock(blockModel[block_id]);
    block_base = block_id -block_id%4;
    i = block_id % 4;
    i++;
    block_id = block_base + i % 4;
    ShowBlock(blockModel[block_id]);
}
void ShiftRight(void) {
    DeleteBlock(blockModel[block_id]);
    curPosX += 2;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossUpRight(void) {
    DeleteBlock(blockModel[block_id]);
    curPosX += 2;
    curPosY -= 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossDownRight(void) {
    DeleteBlock(blockModel[block_id]);
    curPosX += 2;
    curPosY += 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftLeft(void) {
    DeleteBlock(blockModel[block_id]);
    curPosX -= 2;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossUpLeft(void) {
    DeleteBlock(blockModel[block_id]);
    curPosX -= 2;
    curPosY -= 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossDownLeft(void) {
    DeleteBlock(blockModel[block_id]);
    curPosX -= 2;
    curPosY += 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void BlockDown(void) {
    DeleteBlock(blockModel[block_id]);
    curPosY += 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void BlockUp(void) {
    DeleteBlock(blockModel[block_id]);
    curPosY -= 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void RemoveCursor(void)

{

    CONSOLE_CURSOR_INFO curInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

    curInfo.bVisible = 0;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void movement(int Direction, int block_id, COORD start) {
    int j = 0;
    // vs의 기본 console창 크기 120 * 30 에 맞게 제작하였습니다.
    switch (Direction) {
    case 1:
        for (; start.X <= 112; start.X += 2) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);

            j++;
        }
        break;
    case 2:
        for (; start.Y >= 0 && start.X <= 112; start.X += 2, start.Y -= 1) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);

            j++;
        }
        break;

    case 3:
        for (; start.Y >= 0; start.Y -= 1) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);
            j++;
        }
        break;

    case 4:
        for (; start.Y >= 0 && start.X >= 0; start.X -= 2, start.Y -= 1) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);
            j++;
        }
        break;
    case 5:
        for (; start.X >= 0; start.X -= 2) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);
            j++;
        }
        break;

    case 6:
        for (; start.Y <= 26 && start.X >= 0; start.X -= 2, start.Y++) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);
            j++;
        }
        break;
    case 7:
        for (; start.Y <= 26; start.Y++) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);
            j++;
        }
        break;
    case 8:
        for (; start.Y <= 26 && start.X <= 112; start.X += 2, start.Y++) {
            SetCurrentCursorPos(start.X, start.Y);
            ShowBlock(blockModel[block_id + (j % 4)]);
            Sleep(200);
            DeleteBlock(blockModel[block_id + (j % 4)]);
            j++;
        }
        break;
    }

}

void SetCurrentCursorPos(int x, int y) {
    COORD p = { x,y };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, p);
}

COORD GetCurrentCursorPos(void) {
    COORD curpoint;
    CONSOLE_SCREEN_BUFFER_INFO curinfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
    curpoint.X = curinfo.dwCursorPosition.X;
    curpoint.Y = curinfo.dwCursorPosition.Y;

    return curpoint;
}

void ShowBlock(char blockInfo[4][4]) {
    int y, x;
    COORD curPos = GetCurrentCursorPos();

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);

            if (blockInfo[y][x] == 1)printf("■");
        }
    }
    SetCurrentCursorPos(curPos.X, curPos.Y);
}

void DeleteBlock(char blockInfo[4][4]) {
    int y, x;
    COORD curPos = GetCurrentCursorPos();

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);

            if (blockInfo[y][x] == 1)printf("  ");
        }
    }
    SetCurrentCursorPos(curPos.X, curPos.Y);
}