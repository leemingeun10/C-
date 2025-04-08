//#include<iostream>
//using namespace std;
//#include<ctime>
//
//#define LottoBallNum 45
//
//
//
//struct Lotto645
//{
//	bool check =false;
//	bool Bonus = false;
//};
//
//void ShuffleLotto(Lotto645* NewLotto)
//{
//	
//
//	std::srand(static_cast<unsigned int>(std::time(0)));
//	for (int i = 0; i < 6; i++)
//	{
//		NewLotto[i].check = true;
//	}
//
//	for (int i = 0; i < LottoBallNum; i++)
//	{
//		int swapnum = rand() % LottoBallNum;
//
//		
//
//
//
//		if (NewLotto[i].check&&!(NewLotto[swapnum].check))
//		{
//			NewLotto[i].check = false;
//			NewLotto[swapnum].check = true;
//		}
//		
//	}
//
//	while (1)
//	{
//		int swapnum = rand() % LottoBallNum;
//
//		if (!NewLotto[swapnum].check)
//		{
//			NewLotto[swapnum].Bonus = true;
//			break;
//		}
//
//	}
//
//
//}
//
////더 좋은 방법으로 섞는방법 
////int numbers[45];
////for (int i = 0; i < 45; i++) numbers[i] = i;
////
////for (int i = 44; i > 0; i--) {
////	int j = rand() % (i + 1);
////	std::swap(numbers[i], numbers[j]);
////}
////
////for (int i = 0; i < 6; i++) {
////	NewLotto[numbers[i]].check = true;
////}
//
//void play(Lotto645* NewLotto)
//{
//	int LottoNum[6];
//	int CheckLotto=0;
//	int BonusCheck = 0;
//	cout << "Choose 6 numbers 1 to 45" << endl;;
//	for (int i = 0; i < 6; i++)
//	{
//		cin >> LottoNum[i];
//	}
//
//
//	for (int i = 0; i < 6; i++)
//	{
//		
//		if (NewLotto[LottoNum[i]-1].check)
//		{
//			CheckLotto++;
//		}
//		if (NewLotto[LottoNum[i]-1].Bonus)
//		{
//			BonusCheck++;
//		}
//
//	}
//	
//	cout << "Lotto Number : ";
//	for (int i = 0; i < LottoBallNum; i++)
//	{
//		if (NewLotto[i].check)
//		{
//			cout << i+1 <<", ";
//		}
//	}
//	cout << endl;
//
//	if (CheckLotto == 6)
//	{
//		cout << "Congratulation You Won First";
//	}
//	else if (CheckLotto == 5)
//	{
//		if (BonusCheck == 1)
//		{
//			cout << "Congratulation You Won Second";
//		}
//		
//		else
//		{
//			cout << "Congratulation You Won Third";
//		}
//
//	}
//	else if (CheckLotto == 4)
//	{
//		cout << "Congratulation You Won Fourth";
//	}
//	else if (CheckLotto == 3)
//	{
//		cout << "Congratulation You Won Fifth";
//	}
//	else
//	{
//		cout << "Sorry You Lose Try Next Time";
//	}
//}
//
//
//int main()
//{	
//	Lotto645* NewLotto = new Lotto645[LottoBallNum];
//	//std::vector<Lotto645> NewLotto(45); 동적할당은 vector로 사용가능
//
//	ShuffleLotto(NewLotto);
//	play(NewLotto);
//	
//	
//	//둘은 세트여야한다.
//	delete[] NewLotto;
//	NewLotto = nullptr;  // delete한 포인터를 다시 사용하지 않도록 주소값을 초기화 해주는 행동  추가 할 필요 있음 
//
//	// Dangling pointer 허상 포인터  유효하지 않은 포인터를 말함 해결법: 잘지움 
//	return 0;
//}