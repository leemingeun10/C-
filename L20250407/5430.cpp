//
//#include <iostream>
//#include<sstream>
//using namespace std;
//
//// ,�� ���ҵ� string�� ó���ϴ¹��
////stringstream ss(s);
////string token;
////
////while (getline(ss, token, ',')) {
////	arr.push_back(stoi(token)); // ���ڿ� �� ���� ��ȯ
////}
//
//// ���ҵ��� ���� ���ڿ��� ������� ó���ϴ� ���
////string input = "RDD";
////for (char c : input) {
////	if (c == 'R') {
////		// R ó��
////	}
////	else if (c == 'D') {
////		// D ó��
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
//	//�Է¹޴°��� ����
//	for (int i = 0; i < TestCase; i++)
//	{
//		cin >> ToDoList[i]>> NumArr[i]>>Variable[i];
//	}
//
//
//	//�˰���
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