#include<iostream>
using namespace std;
#include<ctime>






struct Lotto645
{
	bool check =false;

};

void ShuffleLotto(Lotto645* NewLotto)
{
	

	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 6; i++)
	{
		NewLotto[i].check = true;
	}

	for (int i = 0; i < 45; i++)
	{
		int swapnum = rand() % 45  ;

		if (NewLotto[i].check&&!(NewLotto[swapnum].check))
		{
			NewLotto[i].check = false;
			NewLotto[swapnum].check = true;
		}
		
	}

}

void play(Lotto645* NewLotto)
{
	int LottoNum[6];
	int CheckLotto=0;
	cout << "Choose 6 numbers 1 to 45" << endl;;
	for (int i = 0; i < 6; i++)
	{
		cin >> LottoNum[i];
	}


	for (int i = 0; i < 6; i++)
	{
		
		if (NewLotto[LottoNum[i]].check)
		{
			CheckLotto++;
		}

	}
	
	cout << "Lotto Number : ";
	for (int i = 0; i < 45; i++)
	{
		if (NewLotto[i].check)
		{
			cout << i <<", ";
		}
	}
	cout << endl;

	if (CheckLotto == 6)
	{
		cout << "Congratulation You Won First";
	}
	if (CheckLotto == 5)
	{
		cout << "Congratulation You Won Second";
	}
	if (CheckLotto == 4)
	{
		cout << "Congratulation You Won Third";
	}
	if (CheckLotto == 3)
	{
		cout << "Congratulation You Won Fourth";
	}
	else
	{
		cout << "Sorry You Lose Try Next Time";
	}
}


int main()
{
	
	Lotto645* NewLotto = new Lotto645[45];


	ShuffleLotto(NewLotto);
	play(NewLotto);
	
	
	delete[] NewLotto;
	return 0;
}