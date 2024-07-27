#include "player.h"

void player::SetDir()
{
	if (nextDir.x != 0 || nextDir.y != 0) //미래방향이 있을 때
	{
		if (mymap->map[myxy.y + nextDir.y][myxy.x + nextDir.x] != 1)// 미래방향으로 가는것이 가능할 때
		{
			nowDir = nextDir; //갈 수 있는 미래방향을 현재방향으로 설정
			nextDir = { 0,0 }; //미래방향 초기화
		}
	}

	if (mymap->map[myxy.y + nowDir.y][myxy.x + nowDir.x] == 1) //현재방향으로 가면 벽이 있을 때 
	{
		nowDir = { 0,0 }; //현재 방향 초기화
	}
}

void player::Move() //플레이어의 움직임을 담당
{
	static int count = 0; //처음 한 번만 실행되는 코드
	SetDir(); //움직일 방향을 설정
	count++;
	if (count == 20 - speed)
	{
		count = 0;
		//설정한 방향으로 움직임
		myxy.x += nowDir.x;
		myxy.y += nowDir.y;
	}

}

xycoord player::whereRU()
{
	return myxy; //내 위치를 반환
}


xycoord player::getNowDir()
{
	return nowDir; //현재방향을 반환
}

xycoord player::getNextDir()
{
	return nextDir; //미래 방향을 반환
}


void player::setNowDir(xycoord Dir)
{
	nowDir = Dir;
}

void player::setNextDir(xycoord Dir)
{
	nextDir = Dir;
}

void player::SetMyMap(GameMap* mymap)
{
	this->mymap = mymap; //게임맵을 mymap이라 지칭
}


string player::getShape()
{
	return shape; //모양을 반환
}


