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
	GameMap mymap; //���Ӹ��� ����(�б� �� ���� ����)
	bool gamestate = false; //������ ��������� �����ϴ� ����
	AIMonster monsters[4] = { //AI���� ������
		AIMonster({ 8,5 }, "��"),
		AIMonster({ 9,5 }, "��"),
		AIMonster({ 10,5 }, "��"),
		AIMonster({ 11,5 }, "��")
	};
	player babo; //�÷��̾ ����
	int point = 0; //����Ʈ�� ��
	void render(); //��, �÷��̾�, AI�� �׸���
	void init(); //���� ���� �� �⺻ ������ ��
	void maprender(); //���� �׸��� �Լ�
	void AIrender(); //AI�� �׸��� �Լ�
	void Charrender(); //ĳ���͸� �׸��� �Լ�
	void release(); //�������� �� ���� �Ǵ� �Լ�
	void update();
	/*
	1. ����Ʈ�� �ٸ�Ҵ��� Ȯ���Ѵ�.
	2. �÷��̾ �״��� Ȯ���Ѵ�.
	3. Ű�Է��� �޴´�
	4. �÷��̾ �����̰��Ѵ�
	5. �÷��̾ ����Ʈ�� Ȯ���ϴ��� Ȯ���Ѵ�
	6. ������ AI�� �����̰� �Ѵ�.
	*/
	void CalculatePoint(); //�Ѹ� ��Դ� �Լ�
public:
	void Play();
};

