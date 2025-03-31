
#include <iostream>
using namespace std;


int main()
{
	int RowNum, ColNum, ItemNum;
	int CountTime = 0 ;

	cin >> RowNum >> ColNum>> ItemNum ;

	short int** Arr = new short int* [RowNum];


	for (int i = 0; i < RowNum; i++)
	{
		Arr[i] = new short int[ColNum];
	}
	
	for (int i = 0; i < RowNum; i++)
	{
		for (int j = 0; j < ColNum; j++)
		{
			cin >> Arr[i][j];
		}
	}



}




void DigGround(short int** arr, int Rownum, int Colnum, int Itemnum,int counttime)
{
	counttime++;
	counttime++;
	arr[Rownum][Colnum]--;
	Itemnum++;
}

void AddGround(short int** arr, int Rownum, int Colnum, int Itemnum, int counttime)
{
	if (Itemnum != 0)
	{
		counttime++;
		arr[Rownum][Colnum]++;
		Itemnum--;
	}
	else return;
}

int SumNums(short int** arr, int Rownum, int Colnum)
{
	int sum = 0;
	for (int i = 0; i < Rownum; i++)
	{
		for (int j = 0; j < Colnum; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum / (Rownum * Colnum);
}

void CountMinTime(short int** arr, int Rownum, int Colnum, int Itemnum, int counttime)
{
	int sum = SumNums(arr, Rownum, Colnum);
	int countPlus = 0;

		for (int i = 0; i < Rownum; i++)
		{
			for (int j = 0; j < Colnum; j++)
			{
				
				while (arr[i][j] < sum)
				{
					countPlus++;
					
				}
			}
		}
	
}