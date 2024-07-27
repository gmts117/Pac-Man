#include "gameManager.h"

void gameManager::render()
{
	maprender();//맵을 출력
	AIrender(); //AI를 출력
	Charrender(); //플레이어를 출력
}

void gameManager::init()
{
	SetCursor(false); //커서를 안보이게 함
	gotoxy(0, 0);
	cout << "  ■              ■  " << endl;
	cout << " ■■              ■■ " << endl;
	cout << "■■■ ■■■■■■■■■■■■ ■■■" << endl;
	cout << "■■ ■■■■■■■■■■■■■■ ■■" << endl;
	cout << "■ ■■■ ■■ ■ ■■■ ■■■ ■" << endl;
	cout << "■ ■■ ■■■   ■■ ■ ■■ ■" << endl;
	cout << "■ ■■■ ■■ ■ ■■■ ■■■ ■" << endl;
	cout << "■■ ■■■■■■■■■■■■■■ ■■" << endl;
	cout << "■■■ ■■■■■■■■■■■■ ■■■" << endl;
	cout << " ■■              ■■ " << endl;
	cout << "  ■              ■  " << endl;
	gotoxy(5, 12);
	cout << "press space";
	int space;
	while (true)
	{
		space = _getch();
		if (space == 32)
		{
			break;
		}
		else
		{
			system("exit");
		}
	}
	system("cls");
	gotoxy(8, 6);
	cout << "3s";
	Sleep(1000);
	gotoxy(8, 6);
	cout << "2s";
	Sleep(1000);
	gotoxy(8, 6);
	cout << "1s";
	Sleep(1000);
	system("cls");
	gotoxy(8, 6);
	cout << "start!";
	Sleep(500);
	srand(time(NULL)); //난수를 활용하기 위한 함수
	maprender(); // 맵 출력
	gamestate = true; //게임을 시작하기 위해 gamestate를 true로 변경

	babo.SetMyMap(&mymap);// player에게 맵 정보 전달

	for (int i = 0; i < 4; i++)
	{
		monsters[i].SetMyMap(&mymap); //AI에게 맵 정보 전달
		monsters[i].SetGamePlayerRef(&babo); //AI에게 플레이어 정보를 전달
	}
}


void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gameManager::maprender() //맵을 출력
{
	for (int i = 0; i < 11; i++)
	{
		gotoxy(0, i); //매 반복시 커서의 x좌표를 0으로 Y좌표를 0~11까지 수선대로 지정
		for (int j = 0; j < 20; j++)
		{
			if (mymap.map[i][j] == 1) //맵에서 벽으로 이루어진 곳을 출력
			{
				cout << "■";
			}
			else if (mymap.map[i][j] == 2) //맵에서 먹이 부분을 출력
			{
				cout << "º";
			}
			else if (mymap.map[i][j] == 0) //맵에서 비어있는 부분을 출력
			{
				cout << " ";
			}
		}
	}
}

void gameManager::AIrender()
{
	for (int i = 0; i < 4; i++) //AI는 4마리이므로 AI각각을 그리기 위해 4번 반복
	{
		//몬스터의 좌표를 받아와서 gotoxy를 이용해 커서를 각각의 몬스터의 위치로 이동한 다음에 getshape으로 AI의 모양을 가져와서 출력
		gotoxy(monsters[i].WhereRU().x * 1, monsters[i].WhereRU().y);
		cout << monsters[i].getShape();
	}
}

void gameManager::Charrender()
{
	//플레이어의 좌표를 받아와서 gotoxy를 이용하여 커서를 플레이어 위치로 이동한 후 출력
	gotoxy(babo.whereRU().x * 1, babo.whereRU().y);
	cout << babo.getShape();
}

void gameManager::release() //게임종료 시 
{
	if (point >= 97)
	{
		system("cls");
		gotoxy(8, 6);
		cout << "CLEAR" << endl;
		Sleep(2000);
		system("exit");
	}
	else
	{
		system("cls");
		gotoxy(8, 6);
		cout << "FAIL" << endl;
		Sleep(2000);
		gameManager GM;
		GM.Play();
	}
}

void gameManager::update()
{
	int keyin;
	bool keyPush = false;
	if (point == 97) //모든 포인트 획득 시 게임종료
	{
		release();
	}
	else
	{
		// AI가 player와 같은 위치에 있는지 검사하기
		for (int i = 0; i < 4; i++)
		{
			if (monsters[i].CanUKill()) //kill이 가능하다면 gamestate를 false로 바꿈 -> release 함수를 실행하여 게임결과를 통보
			{
				gamestate = false;
				return;
			}
		}

		while (!isrendertime())
		{
			if (_kbhit() && keyPush == false) //keypush가 false일 때 
			{
				keyPush = true;
				keyin = _getch(); //키입력을 받음
				if (keyin == 224)
				{
					keyin = _getch();
					switch (keyin)
					{
					case 72:
						babo.setNextDir({ 0, -1 });
						break;
					case 75:
						babo.setNextDir({ -1, 0 });
						break;
					case 77:
						babo.setNextDir({ 1, 0 });
						break;
					case 80:
						babo.setNextDir({ 0, 1 });
						break;
					}
					/*입력 감지 / 처리 */
					/*계산 수행        */
					//오른쪽 화살표가 눌리면
					// 오른쪽으로 갈 수 있는지 검사하고 (맵에 있는 벽 정보와, 캐릭터의 현재 좌표 정보를 가지고
					// 이동이 가능한지 불가능한지 판단한다.
					// 그럴 수 있으면 오른쪽으로 간다. (chg.myxy.x++)
				}
			}
			/* 입력과 상관없는 계산 */
		}
		//프레임마다 한번 실행해야 하는 코드를 넣으시오
		babo.Move(); //플레이어의 클래스에 있는 Move를 실행
		CalculatePoint(); //팩맨 밥먹는 코드
		for (int i = 0; i < 4; i++)
		{
			monsters[i].Move();
		}
	}

}



// 맵에 데이터가 2인 부분이 밥인데, 밥이 있으면 밥을 먹고 포인트를 올리면서 그 부분을 '0' 즉 빈맵으로 처리하는 코드
void gameManager::CalculatePoint()// 팩맨 밥먹는 코드
{
	if (mymap.map[babo.whereRU().y][babo.whereRU().x] == 2)
	{
		mymap.map[babo.whereRU().y][babo.whereRU().x] = 0;
		point++;
	}
}

void gameManager::Play()
{
	init();

	while (gamestate) //update에서 gamestate를 false로 바꾸면 게임 종료
	{
		update();
		render();
	}

	release(); //게임 결과 출력
}
