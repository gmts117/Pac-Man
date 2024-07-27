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
	bool operator==(xycoord v1); //����
	void rotateCW() //�ð�������� ȸ��
	{
		int a = x;
		x = y;
		y = -a;
	}
	void rotateCCW() //�ð�ݴ�������� ȸ��
	{
		int a = x;
		x = -y;
		y = a;
	}
	void operator=(xycoord v1);
};