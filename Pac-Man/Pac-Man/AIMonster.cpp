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


void AIMonster::Move() //AI의 움직임 담당
{
    static int count = 0;//처음 한 번만 실행되는 코드
    count++;
    if (count == 20 - speed) //Move 함수가 
    {
        UpdateCollision();
        count = 0;
        if (CanMoveD[0] + CanMoveD[1] + CanMoveD[2] != 0) //CanMoveD가 초기화 되어 있을 때
        {
            int num;
            do
            {
                num = rand() % 3;
            } while (CanMoveD[num] == false); //3가지 방향 중 갈 수 있는 방향을 num으로 설정
            if (num == 0)
            {
                nowD.rotateCCW(); //현재방향을 왼쪽으로
            }
            else if (num == 2)
            {
                nowD.rotateCW(); //현재방향을 오른쪽으로
            }
        }
        else
        {
            nowD.rotateCCW();
            nowD.rotateCCW();
        }
        AIxy.x += nowD.x; //nowD로 이동
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

    if (AIxy == gameplayer->whereRU())//AI의 위치와 플레이어의 좌표가 같다면 true반환
    {
        return true;
    }
    return false;
}


void AIMonster::UpdateCollision()
{
    // 벽체크, 갈 수 있는 방향체크
    // 사용해야 하는 데이터 : mymap, nowD
    // 업데이트해야 하는 데이터 : CanMoveD[3]
    for (int i = 0; i < 3; i++)
    {
        CanMoveD[i] = false; //CanMoveD[]배열 초기화
    }
    xycoord temp = nowD; //temp에 nowD를 저장
    temp.rotateCW(); //temp(nowD)를 시계방향만큼 바꿈
    if (mymap->map[AIxy.y + temp.y][AIxy.x + temp.x] != 1) //오른쪽으로 갈 수 있는가
    {
        CanMoveD[2] = true;
    }
    if (mymap->map[AIxy.y + nowD.y][AIxy.x + nowD.x] != 1) //직진할 수 있는가
    {
        CanMoveD[1] = true;
    }
    temp.rotateCCW(); //rotateCCW를 2번 하여 뒤돌아보게함
    temp.rotateCCW(); //temp가 nowD를 기준으로 오른쪽을 가리키고 있었으므로 rotateCCW를 2번 하면 nowD를 기준으로 왼쪽
    if (mymap->map[AIxy.y + temp.y][AIxy.x + temp.x] != 1) //왼쪽으로 갈 수 있는가
    {
        CanMoveD[0] = true;
    }
}