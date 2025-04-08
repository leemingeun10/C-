#include<iostream>

using namespace std;

struct Canwin
{
	bool win = false;
};

int main()
{
	string Sang = "SK";
	string Chang = "CY";

	int Rocks;
	cin >> Rocks;

	Canwin* WinAlgo = new Canwin[Rocks];
	
	WinAlgo[0].win = true;
	WinAlgo[1].win = false;
	WinAlgo[2].win = true;
	WinAlgo[3].win = true;
	

	


	for (int i = 4; i < Rocks; i++)
	{
		WinAlgo[i].win = !(WinAlgo[i - 1].win && WinAlgo[i - 3].win && WinAlgo[i - 4].win); 
		// 이걸 생각하는게 중요함 sk기준으로 만든것 sk가 처음에 이길수 있는 수들 
		// 그다음에 상대가 이길수있는 수들로 바뀔것임 	
	}


	if (WinAlgo[Rocks-1].win)
	{
		cout << Sang;
	}
	else
	{
		cout << Chang;
	}
	
}
