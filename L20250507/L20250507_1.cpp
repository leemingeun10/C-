#include<iostream>
#include<vector>
using namespace std;


uint64_t FindNOPT(uint64_t num)
{
	uint64_t NPOT =1 ;
	while (num >= NPOT)
	{
		NPOT *= 2;
	}

	return NPOT;
}



int main()
{

	uint64_t testcase;
	vector<uint64_t> Test;

	cin >> testcase;

	for (uint64_t i = 0; i < testcase; i++)
	{
		int voidnum;
		cin >> voidnum;
		Test.push_back(voidnum);
	}

	uint64_t answer=0 ;

	for (auto testnum : Test)
	{
		if (answer == 0)
		{
			answer = FindNOPT(testnum);
		}
		else
		{
			answer ^= FindNOPT(testnum);
		}
	}

	cout << answer; 



	return 0;

}