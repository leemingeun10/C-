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
//	//�� ������ �� ���̼� ���� ��մ� �����̴�.
//
//	//	Ź�� ���� �� N���� �ִ�.����̿� â���̴� ���� �����ư��鼭 ���� ��������, ���� 1��, 3�� �Ǵ� 4�� ������ �� �ִ�.������ ���� �������� ����� ������ ���� �ȴ�.
//
//	//	�� ����� �Ϻ��ϰ� ������ ���� ��, �̱�� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.������ ����̰� ���� �����Ѵ�.
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
//		// �̰� �����ϴ°� �߿��� sk�������� ����� sk�� ó���� �̱�� �ִ� ���� 
//		// �״����� ��밡 �̱���ִ� ����� �ٲ���� 	
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
