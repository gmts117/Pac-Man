#pragma once
#include <iostream>
#include "mygameheader.h"
#include "GameMap.h"
#include "player.h"
using namespace std;

class AIMonster
{
private:
	int speed = 11; // AI의 속도
	bool CanMoveD[3] = { 0 }; //바라보고 있는 방향을 기준으로 직진, 우회전, 좌회전 중 움직일 수 있는 방향을 저장(UpdateCollision에서 값을 조정)
	//CamMoveD[0]=왼쪽, CamMoveD[1]=직진, CamMoveD[2]=오른쪽
	string shape; //AI들의 모양을 저장
	xycoord nowD = { 0,1 }; //각 AI들이 바라보고 있는 방향을 저장. 어떻게?
	xycoord AIxy; //각 AI들의 좌표를 저장
	GameMap* mymap; //AI가 맵의 정보 저장(읽기전용)
	player* gameplayer; //AI가 플레이어의 정보를 저장
	void UpdateCollision(); //갈 수 있는 방향을 저장
public:
	AIMonster(xycoord myxy, string myshape); //gamemanager에서 AI 4마리를 복제하기 위해 필요 
	bool CanSee(); //AI가 보고 있는 방향의 일직선 상에 플레이어가 보이는지 판단
	void Move(); //AI의 움직임을 담당
	xycoord WhereRU(); //AI에게 플레이어의 좌표를 전달
	string getShape(); //gamemanager에서 각 AI들의 모양을 전달
	void SetMyMap(GameMap* map); //GameMap에서 맵의 정보를 전달
	void SetGamePlayerRef(player* gameplayer); //플레이어의 위치를 포인터로 받음
	bool CanUKill(); //각 AI의 좌표와 플레이어의 좌표를 비교하여 사망여부를 판단
};