#include "gameManager.h"

void gameManager::render()
{
	maprender();//���� ���
	AIrender(); //AI�� ���
	Charrender(); //�÷��̾ ���
}

void gameManager::init()
{
	SetCursor(false); //Ŀ���� �Ⱥ��̰� ��
	gotoxy(0, 0);
	cout << "  ��              ��  " << endl;
	cout << " ���              ��� " << endl;
	cout << "���� ������������� ����" << endl;
	cout << "��� ��������������� ���" << endl;
	cout << "�� ���� ��� �� ���� ���� ��" << endl;
	cout << "�� ��� ����   ��� �� ��� ��" << endl;
	cout << "�� ���� ��� �� ���� ���� ��" << endl;
	cout << "��� ��������������� ���" << endl;
	cout << "���� ������������� ����" << endl;
	cout << " ���              ��� " << endl;
	cout << "  ��              ��  " << endl;
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
	srand(time(NULL)); //������ Ȱ���ϱ� ���� �Լ�
	maprender(); // �� ���
	gamestate = true; //������ �����ϱ� ���� gamestate�� true�� ����

	babo.SetMyMap(&mymap);// player���� �� ���� ����

	for (int i = 0; i < 4; i++)
	{
		monsters[i].SetMyMap(&mymap); //AI���� �� ���� ����
		monsters[i].SetGamePlayerRef(&babo); //AI���� �÷��̾� ������ ����
	}
}


void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gameManager::maprender() //���� ���
{
	for (int i = 0; i < 11; i++)
	{
		gotoxy(0, i); //�� �ݺ��� Ŀ���� x��ǥ�� 0���� Y��ǥ�� 0~11���� ������� ����
		for (int j = 0; j < 20; j++)
		{
			if (mymap.map[i][j] == 1) //�ʿ��� ������ �̷���� ���� ���
			{
				cout << "��";
			}
			else if (mymap.map[i][j] == 2) //�ʿ��� ���� �κ��� ���
			{
				cout << "��";
			}
			else if (mymap.map[i][j] == 0) //�ʿ��� ����ִ� �κ��� ���
			{
				cout << " ";
			}
		}
	}
}

void gameManager::AIrender()
{
	for (int i = 0; i < 4; i++) //AI�� 4�����̹Ƿ� AI������ �׸��� ���� 4�� �ݺ�
	{
		//������ ��ǥ�� �޾ƿͼ� gotoxy�� �̿��� Ŀ���� ������ ������ ��ġ�� �̵��� ������ getshape���� AI�� ����� �����ͼ� ���
		gotoxy(monsters[i].WhereRU().x * 1, monsters[i].WhereRU().y);
		cout << monsters[i].getShape();
	}
}

void gameManager::Charrender()
{
	//�÷��̾��� ��ǥ�� �޾ƿͼ� gotoxy�� �̿��Ͽ� Ŀ���� �÷��̾� ��ġ�� �̵��� �� ���
	gotoxy(babo.whereRU().x * 1, babo.whereRU().y);
	cout << babo.getShape();
}

void gameManager::release() //�������� �� 
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
	if (point == 97) //��� ����Ʈ ȹ�� �� ��������
	{
		release();
	}
	else
	{
		// AI�� player�� ���� ��ġ�� �ִ��� �˻��ϱ�
		for (int i = 0; i < 4; i++)
		{
			if (monsters[i].CanUKill()) //kill�� �����ϴٸ� gamestate�� false�� �ٲ� -> release �Լ��� �����Ͽ� ���Ӱ���� �뺸
			{
				gamestate = false;
				return;
			}
		}

		while (!isrendertime())
		{
			if (_kbhit() && keyPush == false) //keypush�� false�� �� 
			{
				keyPush = true;
				keyin = _getch(); //Ű�Է��� ����
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
					/*�Է� ���� / ó�� */
					/*��� ����        */
					//������ ȭ��ǥ�� ������
					// ���������� �� �� �ִ��� �˻��ϰ� (�ʿ� �ִ� �� ������, ĳ������ ���� ��ǥ ������ ������
					// �̵��� �������� �Ұ������� �Ǵ��Ѵ�.
					// �׷� �� ������ ���������� ����. (chg.myxy.x++)
				}
			}
			/* �Է°� ������� ��� */
		}
		//�����Ӹ��� �ѹ� �����ؾ� �ϴ� �ڵ带 �����ÿ�
		babo.Move(); //�÷��̾��� Ŭ������ �ִ� Move�� ����
		CalculatePoint(); //�Ѹ� ��Դ� �ڵ�
		for (int i = 0; i < 4; i++)
		{
			monsters[i].Move();
		}
	}

}



// �ʿ� �����Ͱ� 2�� �κ��� ���ε�, ���� ������ ���� �԰� ����Ʈ�� �ø��鼭 �� �κ��� '0' �� ������� ó���ϴ� �ڵ�
void gameManager::CalculatePoint()// �Ѹ� ��Դ� �ڵ�
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

	while (gamestate) //update���� gamestate�� false�� �ٲٸ� ���� ����
	{
		update();
		render();
	}

	release(); //���� ��� ���
}
