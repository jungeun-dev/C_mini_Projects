#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "block.h"
//왼쪽 75, 오른쪽 77 위 72;

#define LEFT 75
#define RIGHT 77
#define UP 119
#define DOWN 120
#define ACROSS_UP_RIGHT 101
#define ACROSS_DOWN_LEFT 122
#define ACROSS_UP_LEFT 113
#define ACROSS_DOWN_RIGHT 99
#define COUNTER_CLOCKWISE 72
#define ROTATION_180 107
#define SPACE 32
#define SUPER 115
/* Size of gameboard*/
#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20

/* Starting point of gameboard*/
#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2


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
int BlockDown(void);
int BlockUp(void);
void RotateBlock(void);
void Movement(int key);
void ProcessKeyInput(void);
void DrawGameBoard(void);
int DetectCollision(char blockModel[4][4], int curPosX, int curPosY);
void SpaceDown(void);
void AddBlockToBoard(void);
int IsGameOver(void);
void RedrawBlocks(void);
void RemoveFillUpLine(void);
void SuperKey(void);
int DetectCollision2(char blockModel[4][4], int PosX, int PosY);

int block_id;
int curPosX = 12, curPosY = 22;
int speed;
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];
int score = 0;

int main() {
    speed = 10;
    srand((unsigned int)time(NULL));

    RemoveCursor();
    DrawGameBoard();

    while (1) {

        block_id = (rand() % 7) * 4;

        curPosX = 30;
        curPosY = 4;
        SetCurrentCursorPos(curPosX, curPosY);
        printf("Score : %d", score);

        curPosX = 12;
        curPosY = 22;
        SetCurrentCursorPos(curPosX, curPosY);
        if (IsGameOver()) {
            break;
        }
        while (1) {
            if (BlockUp() == 0) {
                AddBlockToBoard();
                RemoveFillUpLine();
                break;
            }
            ProcessKeyInput();
        }

    }
    SetCurrentCursorPos(10, 25);
    puts("GAME OVER!");
    getchar();

    return 0;
}
int DetectCollision2(char blockModel[4][4], int PosX, int PosY) {
    int x, y;
    int arrX = (PosX - GBOARD_ORIGIN_X) / 2;
    int arrY = PosY - GBOARD_ORIGIN_Y;

    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            if ((blockModel[y][x] == 1) && (gameBoardInfo[arrY + y][arrX + x] == 2))
                return 0;
        }
    }
    return 1;


}

void SuperKey(void) {
    DeleteBlock(blockModel[block_id]);
    while (DetectCollision2(blockModel[block_id], curPosX, (curPosY - 1))) {
        curPosY--;
    }
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void RedrawBlocks(void) {
    int x, y;

    int cursX, cursY;

    for (y = 1; y < GBOARD_HEIGHT; y++)

    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)

        {
            cursX = x * 2 + GBOARD_ORIGIN_X;

            cursY = y + GBOARD_ORIGIN_Y;

            SetCurrentCursorPos(cursX, cursY);

            if (gameBoardInfo[y][x] == 1)

            {
                printf("■");

            }

            else { printf("  "); }

        }

    }

}
void RemoveFillUpLine(void) {
    int x, y, line;
    for (int y = 1; y <= GBOARD_HEIGHT; y++) {
        for (x = 1; x < GBOARD_WIDTH + 1; x++) {
            if (gameBoardInfo[y][x] != 1) break;
        }
        if (x == (GBOARD_WIDTH + 1)) {
            line = y;
            score += 10;
            while (line <= GBOARD_HEIGHT ) {
                memcpy(&gameBoardInfo[line][1], &gameBoardInfo[line+1][1], GBOARD_WIDTH * sizeof(int));
                line++;
            }
            y--;
        }

        RedrawBlocks();
    }
}
int IsGameOver(void) {
    if (!DetectCollision(blockModel[block_id], curPosX, curPosY)) {
        return 1;
    }
    return 0;
}
void AddBlockToBoard(void) {
    int x, y, arrCurX, arrCurY;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            arrCurX = (curPosX - GBOARD_ORIGIN_X) / 2;
            arrCurY = curPosY - GBOARD_ORIGIN_Y;

            if (blockModel[block_id][y][x] == 1) {
                gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
            }
        }
    }
}

void SpaceDown(void) {
    DeleteBlock(blockModel[block_id]);
    while (DetectCollision(blockModel[block_id], curPosX, (curPosY - 1))) {
        curPosY--;
    }
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
int DetectCollision(char blockModel[4][4], int PosX, int PosY) {
    int x, y;
    int arrX = (PosX - GBOARD_ORIGIN_X) / 2;
    int arrY = PosY - GBOARD_ORIGIN_Y;

    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            if ((blockModel[y][x] == 1) && (gameBoardInfo[arrY + y][arrX + x] == 1 || gameBoardInfo[arrY + y][arrX + x] ==  2))
                return 0;
        }
    }
    return 1;


}
void DrawGameBoard(void) {
    int x, y;
    for (y = 0; y < GBOARD_HEIGHT; y++) {
        gameBoardInfo[y][0] = 2;
        gameBoardInfo[y][GBOARD_WIDTH + 1] = 2;
    }
    for (x = 0; x < GBOARD_WIDTH + 2; x++) {
        gameBoardInfo[0][x] = 2;
    }

    for (y = 0; y < GBOARD_HEIGHT + 1; y++) { // 높이 20
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
        if (y == 0) printf("┏");
        else printf("┃");

        SetCurrentCursorPos(GBOARD_ORIGIN_X + ((GBOARD_WIDTH + 1) * 2), GBOARD_ORIGIN_Y + y);
        if (y == 0)printf("┓");
        else printf("┃");
    }
    for (x = 1; x < GBOARD_WIDTH + 1; x++) {
        SetCurrentCursorPos(x * 2 + GBOARD_ORIGIN_X,  GBOARD_ORIGIN_Y);
        printf("━");
    }

}
void ProcessKeyInput(void) {
    int key;
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            key = _getch();
            Movement(key);
        }
        Sleep(speed);
    }
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
    case SPACE:
        SpaceDown();
        break;
    case SUPER:
        SuperKey();
        break;
    }
}
void RotateBlock(void) {
    int block_base, block_rotated;
    block_base = block_id - block_id % 4;
    block_rotated = block_base + (block_id + 1) % 4;
    if (!DetectCollision(blockModel[block_rotated], curPosX, (curPosY))) {
        return;
    }

    DeleteBlock(blockModel[block_id]);
    block_id = block_rotated;
    ShowBlock(blockModel[block_id]);
}
void ShiftRight(void) {
    if (!DetectCollision(blockModel[block_id], curPosX + 2, (curPosY))) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPosX += 2;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossUpRight(void) {
    if (!DetectCollision(blockModel[block_id], curPosX + 2, (curPosY - 1))) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPosX += 2;
    curPosY -= 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossDownRight(void) {
    if (!DetectCollision(blockModel[block_id], curPosX + 2, (curPosY + 1))) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPosX += 2;
    curPosY += 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftLeft(void) {
    if (!DetectCollision(blockModel[block_id], curPosX - 2, (curPosY))) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPosX -= 2;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossUpLeft(void) {
    if (!DetectCollision(blockModel[block_id], curPosX - 2, (curPosY - 1))) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPosX -= 2;
    curPosY -= 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
void ShiftAcrossDownLeft(void) {
    if (!DetectCollision(blockModel[block_id], curPosX - 2, (curPosY + 1))) {
        return;
    }
    DeleteBlock(blockModel[block_id]);
    curPosX -= 2;
    curPosY += 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
}
int BlockDown(void) {
    if (!DetectCollision(blockModel[block_id], curPosX, (curPosY + 1))) {
        return 0;
    }
    DeleteBlock(blockModel[block_id]);
    curPosY += 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
    return 1;
}
int BlockUp(void) {
    if (!DetectCollision(blockModel[block_id], curPosX, (curPosY - 1))) {
        return 0;
    }
    DeleteBlock(blockModel[block_id]);
    curPosY -= 1;
    SetCurrentCursorPos(curPosX, curPosY);
    ShowBlock(blockModel[block_id]);
    return 1;
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