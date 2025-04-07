
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



/// black jack game 
// player VS Computer 
// player draws when he want
// Computer Draws when he lose and cardsum <=16 
// A can be 1 and 11 
// Deck is rand


#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

string GetShape(int cardIndex) {
	int shape = cardIndex / 13;
	switch (shape) {
	case 0: return "♠";
	case 1: return "♣";
	case 2: return "♥";
	case 3: return "◆";
	default: return "Unknown";
	}
}

string GetNumber(int cardIndex) {
	int number = cardIndex % 13 + 1;
	if (number == 11) return "J";
	else if (number == 12) return "Q";
	else if (number == 13) return "K";
	else if (number == 1) return "A";
	else return to_string(number);
}

void Shuffle(int* deck, int size) {
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(deck[i], deck[j]);
	}
}

void PrintCards(int* deck, int playerDrawCount, int computerDrawCount) {
	cout << "[Computer]: ";
	cout << GetShape(deck[0]) << " " << GetNumber(deck[0]) << ", ";
	cout << GetShape(deck[1]) << " " << GetNumber(deck[1]);

	for (int i = 0; i < computerDrawCount; i++) {
		cout << ", " << GetShape(deck[4 + playerDrawCount + i]) << " " << GetNumber(deck[4 + playerDrawCount + i]);
	}
	cout << endl;

	cout << "====================" << endl;

	cout << "[Player]: ";
	cout << GetShape(deck[2]) << " " << GetNumber(deck[2]) << ", ";
	cout << GetShape(deck[3]) << " " << GetNumber(deck[3]);

	for (int i = 0; i < playerDrawCount; i++) {
		cout << ", " << GetShape(deck[4 + i]) << " " << GetNumber(deck[4 + i]);
	}
	cout << endl;
}

int CalculateScore(int* deck, int startIndex, int count) {
	int sum = 0;
	int Aceindex = 0;
	for (int i = 0; i < count; i++) {
		int number = deck[startIndex + i] % 13 + 1;
		if (number >= 11) sum += 10;
		else if (number == 1)
		{
			Aceindex++;
		}
		else sum += number;
	}

	sum = sum + 11 * Aceindex;

	while (sum > 21&& Aceindex>0)
	{
		Aceindex--;
		sum -= 10;
	}

	return sum;
}

bool AskMore() {
	int choice;
	cout << "Want more card? (Yes:1 / No:0): ";
	cin >> choice;
	return choice == 1;
}

void DeclareWinner(int playerScore, int computerScore) {
	cout << "====================" << endl;
	cout << "Final Score - Player: " << playerScore << ", Computer: " << computerScore << endl;

	if (playerScore > 21 && computerScore > 21)
		cout << "Both Busted! It's a Draw." << endl;
	else if (playerScore > 21)
		cout << "Player Busted! Computer Wins." << endl;
	else if (computerScore > 21)
		cout << "Computer Busted! Player Wins." << endl;
	else if (playerScore > computerScore)
		cout << "Player Wins!" << endl;
	else if (playerScore < computerScore)
		cout << "Computer Wins!" << endl;
	else
		cout << "It's a Draw!" << endl;
}

void playing() {
	srand(static_cast<unsigned int>(time(NULL)));

	const int CARD_COUNT = 52;
	int* deck = new int[CARD_COUNT];

	for (int i = 0; i < CARD_COUNT; i++) {
		deck[i] = i;
	}

	Shuffle(deck, CARD_COUNT);

	int playerDrawCount = 0;
	int computerDrawCount = 0;

	// 시작 카드 번호

	int playerStartIndex = 2;
	int computerStartIndex = 0;
	int extraCardStartIndex = 4;

	PrintCards(deck, playerDrawCount, computerDrawCount);

	int playerScore = CalculateScore(deck, playerStartIndex, 2);
	while (playerScore <= 21 && AskMore()) {
		playerDrawCount++;
		playerScore = CalculateScore(deck, playerStartIndex, 2 + playerDrawCount);
		PrintCards(deck, playerDrawCount, computerDrawCount);
	}

	int computerScore = CalculateScore(deck, computerStartIndex ,2);
	if (playerScore <=  21&& playerScore > computerScore)
	{
		
		while (computerScore <= 16) {
			computerDrawCount++;
			computerScore = CalculateScore(deck, computerStartIndex, 2);
			computerScore += CalculateScore(deck, extraCardStartIndex + playerDrawCount, computerDrawCount);
			PrintCards(deck, playerDrawCount, computerDrawCount);
		}
	}
	DeclareWinner(playerScore, computerScore);

	delete[] deck;
}



int main() {
	playing();
	return 0;
}





