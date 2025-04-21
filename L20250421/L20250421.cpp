#include<iostream>
#include<vector>
using namespace std;
// overload 함수이름은 같은데 인자의 타입이 다른경우 
// 자료구조 list vector queue list는 링크형


template<typename T>
class Culculater
{
public:
	T Add(T a, T b);
	T Sub(T a, T b);
	T Mlt(T a, T b);
	T Div(T a, T b);

};

class Data
{

};



int main()
{
	vector<int> a;
	vector<int>::iterator iter;
	iter = a.begin();

	return 0;
}




template<typename T>
T Culculater<T>::Add(T a, T b)
{

	return a + b;
}

template<typename T>
T Culculater<T>::Sub(T a, T b)
{
	return a - b;
}

template<typename T>
T Culculater<T>::Mlt(T a, T b)
{
	return a * b;
}

template<typename T>
T Culculater<T>::Div(T a, T b)
{
	return a / b;
}
















/*
#include <iostream>
#include <vector> //container, C#, java, collection
//STL
//Standard Template Library -> ÀÚ·á »ó°ü ¾øÀÌ µ¿ÀÛ

//C#, java
//Generic

using namespace std;

//Add1, Add2, Add2
//name mangling
//overload
//int Add(int A, int B)
//{
//	return A + B;
//}
//
//float Add(float A, float B, int C)
//{
//	return  A + B;
//}
//
//char Add(char A, char B)
//{
//	return  A + B;
//}


//meta programmingr
//c++ -> complier ->(template)+ make -> object
//template <typename T>
//T Add(T A, T B)
//{
//	return A + B;
//}

class Adder
{
public:
	int Add(int A, int B);
	float Add(float A, float B);
	char Add(char A, char B);
};

//overload
int Adder::Add(int A, int B)
{
	return A + B;
}

float Adder::Add(float A, float B)
{
	return A + B;
}

char Adder::Add(char A, char B)
{
	return A + B;
}


template <typename T>
class TemplateAdder
{
public:
	T Add(T A, T B);
};


template<typename T>
T TemplateAdder<T>::Add(T A, T B)
{
	return A + B;
}


int main()
{
	TemplateAdder<int> A;

	cout << A.Add(1, 2) << endl;

	return 0;
}
*/

