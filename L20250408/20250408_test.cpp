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

//_getch() 키받아오기
//_kbhit() 키입력이 존재했는지 에대한 int 무언가입력되면 0이아닌수를 반환
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

		// 더블 버퍼링 미리 그려놓고 가져오는것( 메모리에 그려놓고 가져온다) 그리는 장비가 느리기 때문에 
		// 위에 if getch 문이있어서 그림이 그려지지만 평소에는 그리는 속도가 지우는속도를 따라오지 못하기 때문에 계속 지워지는 일이 발생한다.
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