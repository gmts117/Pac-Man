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
	ConsoleCursor.bVisible = bVisible; // true 보임, false 안보임
	ConsoleCursor.dwSize = 1; // 커서사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // 설정
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

bool xycoord::operator==(xycoord v1) //새로운 연산자1(==)
{
	if (this->x == v1.x && this->y == v1.y) //비교하려는 대상의 x와 y가 모두 같을 때 true
	{
		return true;
	}
	return false;
}

void xycoord::operator=(xycoord v1) //새로운 연산자2(=)
{
	x = v1.x; //두 대상의 x와 y를 같게 함
	y = v1.y;
}
