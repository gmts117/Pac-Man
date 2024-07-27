#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>

void gotoxy(int x, int y);
void SetCursor(bool bVisible);

void settextcolor(int colornum);
bool isrendertime();

struct	xycoord
{
	int x;
	int y;
	bool operator==(xycoord v1); //새론
	void rotateCW() //시계방향으로 회전
	{
		int a = x;
		x = y;
		y = -a;
	}
	void rotateCCW() //시계반대방향으로 회전
	{
		int a = x;
		x = -y;
		y = a;
	}
	void operator=(xycoord v1);
};