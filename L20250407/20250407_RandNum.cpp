
/* first
int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	//std::rand() % 100 + 1

	int numarr[52];


	for (int a = 0; a < 52; )
	{
		int RandomNum = rand() % 52 + 1;
		bool Isexist=0;

		for (int i = 0; i < a; i++)
		{
			if (numarr[i] == RandomNum)
			{
				Isexist = 1;
				break;
			}
		}

		if (!Isexist)
		{
			numarr[a] = RandomNum;
			a++;
		}


	}


	for (int a = 0; a < 52; a++)
	{
		cout << numarr[a] << " ";
	}

	return 0;

}



*/
//Fisher-Yates Shuffle 알고리즘
//동적할당 ++ 

// 줄맞춤 cntr K+D
// 코드 주석 cntr K+C 
// 주석코드 돌리기 cntrK+U

// 3항연산자 (false) ? A : B  false가 참이면 A 틀리면 B
// inline 컴파일러가 빠른 속도를 평가해서 사용

//int main()
//{
//	std::srand(static_cast<unsigned int>(std::time(0)));
//	//srand((unsigned int)time(NULL));
//	// 
//	//std::rand() % 100 + 1
//
//
//	int NumberOfArr;
//
//	cin >> NumberOfArr;
//
//	int* numarr = new int[NumberOfArr];
//
//	for (int a = 0; a < NumberOfArr; a++)
//	{
//		numarr[a] = a;
//	}
//
//	for (int a = 0; a < NumberOfArr; a++)
//	{
//		int swapnum = rand() % (a + 1);
//
//		swap(numarr[a], numarr[swapnum]);
//	}
//
//	for (int a = 0; a < NumberOfArr; a++)
//	{
//		cout << numarr[a] << " ";
//	}
//
//
//
//	delete[] numarr;
//	return 0;
//}
//
//
//int Sub(int a , int b)
//{
//	return a - b;
//}



#include <iostream>
#include <algorithm>
#include<ctime>

#define CARD_COUNT		52

using namespace std;

//global variable
int Deck[CARD_COUNT] = { 0, };

void Initialize()
{
	srand((unsigned int)time(NULL));

	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index + 1;
	}
}

void Shuffle()
{
	int Temp = 0;
	for (int Count = 0; Count < CARD_COUNT * 1000; Count++)
	{
		int First = rand() % CARD_COUNT;
		int Second = rand() % CARD_COUNT;
		Temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = Temp;
	}
}

string Shape(int Decknum)
{
	if (Decknum / 13 == 0)
	{
		return "Spade";
	}
	else if (Decknum / 13 == 1)
	{
		return "Clover";
	}
	else if (Decknum / 13 == 2)
	{
		return "Heart";
	}
	else if (Decknum / 13 == 3)
	{
		return "Diamond";
	}
	return "Diamond";
}

void Print()
{
	//Computer
	
	cout << Shape(Deck[0]) << Deck[0] % 13 +1 << ", ";
	cout << Shape(Deck[1]) << Deck[1] % 13 + 1 << endl;

	cout << "================" << endl;
	//Player
	cout << Shape(Deck[2]) << Deck[2] % 13 + 1 << ", ";
	cout << Shape(Deck[3]) << Deck[3] % 13 + 1 << endl;

}

void PrintWinner()
{
	int PlayerNum, ComputerNum;
	ComputerNum = (Deck[0] % 13 + 1) + (Deck[1] % 13 + 1);
	PlayerNum = (Deck[2] % 13 + 1) + (Deck[3] % 13 + 1);
	if (PlayerNum > 21 && ComputerNum <=21)
	{
		cout << "Player Bust Computer Win";
	}
	else if (ComputerNum > 21 && PlayerNum <= 21)
	{
		cout << "Computer Bust Player Win";
	}
	else if (ComputerNum > 21 && PlayerNum > 21)
	{
		cout << "Both Player Bust Draw";
	}
	else if (PlayerNum >= ComputerNum)
	{
		cout << "Player Win";
	}
	else
	{
		cout << "Computer win";
	}
}

int main()
{
	Initialize();
	Shuffle();
	Print();
	PrintWinner();

	return 0;
}



