#include<iostream>
#include<Ctime>
using namespace std;

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
