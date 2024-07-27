#include "player.h"

void player::SetDir()
{
	if (nextDir.x != 0 || nextDir.y != 0) //�̷������� ���� ��
	{
		if (mymap->map[myxy.y + nextDir.y][myxy.x + nextDir.x] != 1)// �̷��������� ���°��� ������ ��
		{
			nowDir = nextDir; //�� �� �ִ� �̷������� ����������� ����
			nextDir = { 0,0 }; //�̷����� �ʱ�ȭ
		}
	}

	if (mymap->map[myxy.y + nowDir.y][myxy.x + nowDir.x] == 1) //����������� ���� ���� ���� �� 
	{
		nowDir = { 0,0 }; //���� ���� �ʱ�ȭ
	}
}

void player::Move() //�÷��̾��� �������� ���
{
	static int count = 0; //ó�� �� ���� ����Ǵ� �ڵ�
	SetDir(); //������ ������ ����
	count++;
	if (count == 20 - speed)
	{
		count = 0;
		//������ �������� ������
		myxy.x += nowDir.x;
		myxy.y += nowDir.y;
	}

}

xycoord player::whereRU()
{
	return myxy; //�� ��ġ�� ��ȯ
}


xycoord player::getNowDir()
{
	return nowDir; //��������� ��ȯ
}

xycoord player::getNextDir()
{
	return nextDir; //�̷� ������ ��ȯ
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
	this->mymap = mymap; //���Ӹ��� mymap�̶� ��Ī
}


string player::getShape()
{
	return shape; //����� ��ȯ
}


