#pragma once
#include <iostream>
#include "mygameheader.h"
#include "GameMap.h"
#include "player.h"
using namespace std;

class AIMonster
{
private:
	int speed = 11; // AI�� �ӵ�
	bool CanMoveD[3] = { 0 }; //�ٶ󺸰� �ִ� ������ �������� ����, ��ȸ��, ��ȸ�� �� ������ �� �ִ� ������ ����(UpdateCollision���� ���� ����)
	//CamMoveD[0]=����, CamMoveD[1]=����, CamMoveD[2]=������
	string shape; //AI���� ����� ����
	xycoord nowD = { 0,1 }; //�� AI���� �ٶ󺸰� �ִ� ������ ����. ���?
	xycoord AIxy; //�� AI���� ��ǥ�� ����
	GameMap* mymap; //AI�� ���� ���� ����(�б�����)
	player* gameplayer; //AI�� �÷��̾��� ������ ����
	void UpdateCollision(); //�� �� �ִ� ������ ����
public:
	AIMonster(xycoord myxy, string myshape); //gamemanager���� AI 4������ �����ϱ� ���� �ʿ� 
	bool CanSee(); //AI�� ���� �ִ� ������ ������ �� �÷��̾ ���̴��� �Ǵ�
	void Move(); //AI�� �������� ���
	xycoord WhereRU(); //AI���� �÷��̾��� ��ǥ�� ����
	string getShape(); //gamemanager���� �� AI���� ����� ����
	void SetMyMap(GameMap* map); //GameMap���� ���� ������ ����
	void SetGamePlayerRef(player* gameplayer); //�÷��̾��� ��ġ�� �����ͷ� ����
	bool CanUKill(); //�� AI�� ��ǥ�� �÷��̾��� ��ǥ�� ���Ͽ� ������θ� �Ǵ�
};