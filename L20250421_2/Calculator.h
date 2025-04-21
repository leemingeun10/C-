#pragma once

namespace ¹ÎÇü
{
	//main, int, float, char, long long
	template <typename T>
	class Calculator
	{
	public:
		T Add(T A, T B)
		{
			return A + B;
		}

		T Sub(T A, T B)
		{
			return A - B;
		}


		T Mul(T A, T B)
		{
			return A * B;
		}

		T Div(T A, T B)
		{
			return A / B;
		}
	};
}


//class CalculatorInt
//{
//public:
//	int Add(int A, int B)
//	{
//		return A + B;
//	}
//
//	int Sub(int A, int B)
//	{
//		return A - B;
//	}
//
//
//	int Mul(int A, int B)
//	{
//		return A * B;
//	}
//
//	int Div(int A, int B)
//	{
//		return A / B;
//	}
//};
//
//
//class CalculatorFloat
//{
//public:
//	float Add(float A, float B)
//	{
//		return A + B;
//	}
//
//	float Sub(float A, float B)
//	{
//		return A - B;
//	}
//
//
//	float Mul(float A, float B)
//	{
//		return A * B;
//	}
//
//	float Div(float A, float B)
//	{
//		return A / B;
//	}
//};
