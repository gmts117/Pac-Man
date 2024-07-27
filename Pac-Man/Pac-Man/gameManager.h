#pragma once
#include <iostream>
#include <conio.h>
#include "mygameheader.h"
#include "player.h"
#include "AIMonster.h"
#include "GameMap.h"
using namespace std;

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

class gameManager
{
private:
	GameMap mymap; //게임맵을 소유(읽기 및 편집 가능)
	bool gamestate = false; //게임을 계속할지를 저장하는 변수
	AIMonster monsters[4] = { //AI들의 생성자
		AIMonster({ 8,5 }, "♠"),
		AIMonster({ 9,5 }, "◆"),
		AIMonster({ 10,5 }, "♥"),
		AIMonster({ 11,5 }, "♣")
	};
	player babo; //플레이어를 소유
	int point = 0; //포인트를 셈
	void render(); //맵, 플레이어, AI를 그린다
	void init(); //게임 시작 전 기본 설정을 함
	void maprender(); //맵을 그리는 함수
	void AIrender(); //AI를 그리는 함수
	void Charrender(); //캐릭터를 그리는 함수
	void release(); //게임종료 시 실행 되는 함수
	void update();
	/*
	1. 포인트를 다모았는지 확인한다.
	2. 플레이어가 죽는지 확인한다.
	3. 키입력을 받는다
	4. 플레이어를 움직이게한다
	5. 플레이어가 포인트를 확득하는지 확인한다
	6. 각각의 AI를 움직이게 한다.
	*/
	void CalculatePoint(); //팩맨 밥먹는 함수
public:
	void Play();
};

