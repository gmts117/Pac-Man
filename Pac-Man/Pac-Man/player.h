#pragma once
#include "mygameheader.h"
#include "GameMap.h"
using namespace std;
class player
{
private:
	int speed = 11; // 1���� 19���� �ٲ� �� ����.
	xycoord myxy = { 3,3 }; // �÷��̾��� ��ġ�� ����
	xycoord nowDir = { 0,0 }; //���� ������ ����
	xycoord nextDir = { 0,0 }; //���� ������ ����
	string shape = "��"; //����� ����
	GameMap* mymap; //���Ӹ��� ����(�б�����)
	void SetDir(); //������ �����ϴ� �Լ�
public:
	void Move(); //�÷��̾��� �������� ���
	xycoord whereRU(); //�÷��̾��� ��ġ�� ��ȯ
	xycoord getNowDir(); //���� ������ ��ȯ
	xycoord getNextDir(); //�̷������� ��ȯ
	void setNowDir(xycoord Dir); //���� ������ ������
	void setNextDir(xycoord Dir); //�̷� ������ ������
	void SetMyMap(GameMap* mymap); //���� �ҷ���
	string getShape(); //����� �ҷ���
};