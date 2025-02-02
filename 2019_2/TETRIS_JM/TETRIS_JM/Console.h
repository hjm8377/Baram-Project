#pragma once
#pragma once


#include <windows.h>
/*키보드 방향키 ASCII*/
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32
#define ENTER 13

enum {
	BLACK, BLUE, GREEN, Cyan, RED, PURPLE, YELLOW, WHITE, GREY, SKYBLUE, GRASSGREEN, Turquoise, PINK
};

//──────────────────────────────────────────────────────
// 화면을 지워주고 커서의 위치를 0,0 으로 이동시키는 함수
//──────────────────────────────────────────────────────
void Clear(void);
//──────────────────────────────────────────────────────
// 커서의 위치를 _x, _y 로 변경하는 함수
//──────────────────────────────────────────────────────
void GotoXY(int _x, int _y);
//──────────────────────────────────────────────────────
// console 창의 title을 변경해 주는 함수
//──────────────────────────────────────────────────────
//void SetTitle(char* _szConsoleName);
//──────────────────────────────────────────────────────
// 배경색, 글자색을 변경해 주는 함수
//──────────────────────────────────────────────────────
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
//──────────────────────────────────────────────────────
// cursor를 보이게, 안보이게 하는 함수 
//──────────────────────────────────────────────────────
void SetCursor(BOOL _bShow);
//──────────────────────────────────────────────────────
// console 창의 크기를 정하는 함수 ( 디폴트 80, 25 )
//──────────────────────────────────────────────────────
void SetConsoleSize(int _col, int _lines);