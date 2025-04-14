//#include<iostream>
//
//using namespace std;
//
//struct Canwin
//{
//	bool win = false;
//};
//
//int main()
//{
//	string Sang = "SK";
//	string Chang = "CY";
//
//	int Rocks;
//	cin >> Rocks;
//
//	Canwin* WinAlgo = new Canwin[Rocks];
//
//	//돌 게임은 두 명이서 즐기는 재밌는 게임이다.
//
//	//	탁자 위에 돌 N개가 있다.상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 돌은 1개, 3개 또는 4개 가져갈 수 있다.마지막 돌을 가져가는 사람이 게임을 지게 된다.
//
//	//	두 사람이 완벽하게 게임을 했을 때, 이기는 사람을 구하는 프로그램을 작성하시오.게임은 상근이가 먼저 시작한다.
//
//
//	WinAlgo[0].win = false;
//	WinAlgo[1].win = true;
//	WinAlgo[2].win = false;
//	WinAlgo[3].win = true;
//
//
//
//
//
//	for (int i = 4; i < Rocks; i++)
//	{
//		WinAlgo[i].win = !(WinAlgo[i - 1].win && WinAlgo[i - 3].win && WinAlgo[i - 4].win);
//		// 이걸 생각하는게 중요함 sk기준으로 만든것 sk가 처음에 이길수 있는 수들 
//		// 그다음에 상대가 이길수있는 수들로 바뀔것임 	
//	}
//
//
//	if (WinAlgo[Rocks - 1].win)
//	{
//		cout << Sang;
//	}
//	else
//	{
//		cout << Chang;
//	}
//
//
//
//}
