#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;


#include <windows.h>

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//_getch() Ű�޾ƿ���
//_kbhit() Ű�Է��� �����ߴ��� ������ int �����ԷµǸ� 0�̾ƴѼ��� ��ȯ
struct Playerinfo
{
	int x, y;
	string Shape;
};

void PlayerMovement(Playerinfo* a)
{
	int getchnum = _getch();
	switch (getchnum)
	{
	case 72  :
		a->y -= 1;
		break;
	case 75:
		a->x -= 1;
		break;
	case 77:
		a->x += 1;
		break;
	case 80 :
		a->y += 1;
		break;
	}

}


void printSceen(Playerinfo* PlayerData)
{
	
		system("cls");

		gotoxy(PlayerData->x, PlayerData->y);

		cout << PlayerData->Shape << endl;

	
}
// toupper(key) == 'W';
int main()
{


	Playerinfo* PlayerData;
	PlayerData = new Playerinfo;

	//cin >> PlayerData->x >> PlayerData->y >> PlayerData->Shape;

		PlayerData->x = 5;
		PlayerData->y = 5;
		PlayerData->Shape = "K";
	gotoxy(PlayerData->x, PlayerData->y);



	cout << PlayerData->Shape << endl;


	while (1)
	{
		if (_getch() == 27)
		{
			break;
		}

		// ���� ���۸� �̸� �׷����� �������°�( �޸𸮿� �׷����� �����´�) �׸��� ��� ������ ������ 
		// ���� if getch �����־ �׸��� �׷������� ��ҿ��� �׸��� �ӵ��� ����¼ӵ��� ������� ���ϱ� ������ ��� �������� ���� �߻��Ѵ�.
		PlayerMovement(PlayerData);
		printSceen(PlayerData);
	
		
	}



	delete PlayerData;
	PlayerData = nullptr;
	return 0;

}


/*
	int FirstNum = 10, SecondNum = 20;

	int* DYarr = new int[FirstNum];

	for (int i = 0; i < FirstNum; i++)
	{
		DYarr[i] = (i + 1) * 3;
	}

	int * DYarr2 = new int[SecondNum];

	for (int i = 0; i < FirstNum; i++)
	{
		DYarr2[i] = DYarr[i];
	}

	delete[] DYarr;
	DYarr = nullptr;

	for (int i = 0; i < FirstNum; i++)
	{
		DYarr2[i+10] = (i + 1) * 4;
	}

	for (int i = 0; i < FirstNum; i++)
	{
		cout << DYarr2[i] << endl;
	}
*/


/*
int* DYarr = new int[10];

for (int i = 0; i < 10; i++)
{
	DYarr[i] = (i + 1) * 3;
}



for (int i = 0; i < 20; i++)
{
	cout << DYarr[i] << endl;
}

delete[] DYarr;

*/