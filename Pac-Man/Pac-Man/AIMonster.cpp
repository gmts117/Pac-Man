#include "AIMonster.h"

AIMonster::AIMonster(xycoord myxy, string myshape)
{
    AIxy = myxy;
    shape = myshape;
}

bool AIMonster::CanSee()
{
    return false;
}


void AIMonster::Move() //AI�� ������ ���
{
    static int count = 0;//ó�� �� ���� ����Ǵ� �ڵ�
    count++;
    if (count == 20 - speed) //Move �Լ��� 
    {
        UpdateCollision();
        count = 0;
        if (CanMoveD[0] + CanMoveD[1] + CanMoveD[2] != 0) //CanMoveD�� �ʱ�ȭ �Ǿ� ���� ��
        {
            int num;
            do
            {
                num = rand() % 3;
            } while (CanMoveD[num] == false); //3���� ���� �� �� �� �ִ� ������ num���� ����
            if (num == 0)
            {
                nowD.rotateCCW(); //��������� ��������
            }
            else if (num == 2)
            {
                nowD.rotateCW(); //��������� ����������
            }
        }
        else
        {
            nowD.rotateCCW();
            nowD.rotateCCW();
        }
        AIxy.x += nowD.x; //nowD�� �̵�
        AIxy.y += nowD.y;
    }
}

xycoord AIMonster::WhereRU()
{
    return AIxy;
}

string AIMonster::getShape()
{
    return shape;
}

void AIMonster::SetMyMap(GameMap* map)
{
    mymap = map;
}

void AIMonster::SetGamePlayerRef(player* gameplayer)
{
    this->gameplayer = gameplayer;
}

bool AIMonster::CanUKill()
{
    if (gameplayer == NULL)
    {
        return false;
    }

    if (AIxy == gameplayer->whereRU())//AI�� ��ġ�� �÷��̾��� ��ǥ�� ���ٸ� true��ȯ
    {
        return true;
    }
    return false;
}


void AIMonster::UpdateCollision()
{
    // ��üũ, �� �� �ִ� ����üũ
    // ����ؾ� �ϴ� ������ : mymap, nowD
    // ������Ʈ�ؾ� �ϴ� ������ : CanMoveD[3]
    for (int i = 0; i < 3; i++)
    {
        CanMoveD[i] = false; //CanMoveD[]�迭 �ʱ�ȭ
    }
    xycoord temp = nowD; //temp�� nowD�� ����
    temp.rotateCW(); //temp(nowD)�� �ð���⸸ŭ �ٲ�
    if (mymap->map[AIxy.y + temp.y][AIxy.x + temp.x] != 1) //���������� �� �� �ִ°�
    {
        CanMoveD[2] = true;
    }
    if (mymap->map[AIxy.y + nowD.y][AIxy.x + nowD.x] != 1) //������ �� �ִ°�
    {
        CanMoveD[1] = true;
    }
    temp.rotateCCW(); //rotateCCW�� 2�� �Ͽ� �ڵ��ƺ�����
    temp.rotateCCW(); //temp�� nowD�� �������� �������� ����Ű�� �־����Ƿ� rotateCCW�� 2�� �ϸ� nowD�� �������� ����
    if (mymap->map[AIxy.y + temp.y][AIxy.x + temp.x] != 1) //�������� �� �� �ִ°�
    {
        CanMoveD[0] = true;
    }
}