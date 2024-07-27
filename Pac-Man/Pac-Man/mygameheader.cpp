#include "mygameheader.h"
const int frame = 20;
const int frametime = 1000 / frame;
using namespace std;


void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetCursor(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bVisible; // true ����, false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ��������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}

void settextcolor(int colornum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colornum);
}

bool isrendertime()
{
	static int before = clock();
	static int now = clock();

	now = clock();

	if (now - before >= frametime)
	{
		before += frametime;
		return true;
	}
	return false;
}

bool xycoord::operator==(xycoord v1) //���ο� ������1(==)
{
	if (this->x == v1.x && this->y == v1.y) //���Ϸ��� ����� x�� y�� ��� ���� �� true
	{
		return true;
	}
	return false;
}

void xycoord::operator=(xycoord v1) //���ο� ������2(=)
{
	x = v1.x; //�� ����� x�� y�� ���� ��
	y = v1.y;
}
