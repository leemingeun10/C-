//
//#include <iostream>
//#include<sstream>
//using namespace std;
//
//// ,로 분할된 string을 처리하는방법
////stringstream ss(s);
////string token;
////
////while (getline(ss, token, ',')) {
////	arr.push_back(stoi(token)); // 문자열 → 정수 변환
////}
//
//// 분할되지 않은 문자열을 순서대로 처리하는 방법
////string input = "RDD";
////for (char c : input) {
////	if (c == 'R') {
////		// R 처리
////	}
////	else if (c == 'D') {
////		// D 처리
////	}
////}
//
//
//int main()
//{
//	int TestCase;
//
//	cin >> TestCase;
//
//	string* ToDoList= new string[TestCase];
//	int* NumArr = new int[TestCase];
//	string* Variable= new string[TestCase];
//
//	
//
//	//입력받는값들 저장
//	for (int i = 0; i < TestCase; i++)
//	{
//		cin >> ToDoList[i]>> NumArr[i]>>Variable[i];
//	}
//
//
//	//알고리즘
//	for (int i = 0; i < TestCase; i++)
//	{
//		int* FreshNum = new int[NumArr[i]];
//		string SubedStr = Variable[i].substr(1, Variable[i].length() - 2);
//		
//		//empty subedstr
//		if (SubedStr.empty()) {
//			if (ToDoList[i].empty())
//			{
//				cout << "[]" << endl;
//			}
//			else
//			{
//				cout << "error" << endl;
//			}
//			
//		}
//		else {
//
//			stringstream string_Var(SubedStr);
//			string token;
//
//			int j = 0;
//			while (getline(string_Var, token, ','))
//			{
//
//				FreshNum[j] = stoi(token);
//				j++;
//			}
//
//			for (char c : ToDoList[i])
//			{
//				if (c == 'R')
//				{
//					for (int j = 0; j < NumArr[i]/2; j++)
//					{
//						swap(FreshNum[j], FreshNum[NumArr[i]-1-j]);
//					}
//
//				}
//				else if (c == 'D')
//				{
//					if (NumArr != 0)
//					{
//						
//					}
//
//
//				}
//
//			}
//		}
//		delete[] FreshNum;
//
//	}
//	
//
//
//
//
//	delete[] ToDoList;
//	delete[] NumArr;
//	delete[] Variable;
//	return 0;
//}