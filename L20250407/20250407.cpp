#include<iostream>
#include<Ctime>
using namespace std;

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


#include<iostream>
#include<Ctime>
using namespace std;

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	//std::rand() % 100 + 1

	 
	int NumberOfArr;
	
	cin >> NumberOfArr;

	int* numarr = new int[NumberOfArr];

	for(int a = 0 ;a< NumberOfArr; a++)
	{
		numarr[a] = a;
	}

	for (int a = 0; a < NumberOfArr; a++)
	{
		int swapnum = rand() % (a + 1);

		swap(numarr[a], numarr[swapnum]);
	}

	for (int a = 0; a < NumberOfArr; a++)
	{
		cout << numarr[a] << " ";
	}



	delete[] numarr;
	return 0;
}





