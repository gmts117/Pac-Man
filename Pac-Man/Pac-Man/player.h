#pragma once
#include "mygameheader.h"
#include "GameMap.h"
using namespace std;
class player
{
private:
	int speed = 11; // 1부터 19까지 바뀔 수 있음.
	xycoord myxy = { 3,3 }; // 플레이어의 위치를 저장
	xycoord nowDir = { 0,0 }; //현재 방향을 저장
	xycoord nextDir = { 0,0 }; //다음 방향을 저장
	string shape = "●"; //모양을 저장
	GameMap* mymap; //게임맵을 저장(읽기전용)
	void SetDir(); //방향을 설정하는 함수
public:
	void Move(); //플레이어의 움직임을 담당
	xycoord whereRU(); //플레이어의 위치를 반환
	xycoord getNowDir(); //현재 방향을 반환
	xycoord getNextDir(); //미래방향을 반환
	void setNowDir(xycoord Dir); //현재 방향을 지정함
	void setNextDir(xycoord Dir); //미래 방향을 지정함
	void SetMyMap(GameMap* mymap); //맵을 불러옴
	string getShape(); //모양을 불러옴
};