// Problem#15
#include <iostream>
#include<iomanip>

using namespace std;

int ReadNumber(string Massege)
{
	int Number = 0;

	cout << Massege  ;
	cin >> Number;

	return Number;
}

int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols, short NumberToCount)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix[i][j]==NumberToCount)
			{
				Counter++;
			}
		}
	}

	return Counter;
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << Matrix[i][j] << "     ";
		}
		cout << endl;
	}
}

void PrintResults(int Matrix[3][3], short Rows, short Cols)
{
	int NumberToCount = ReadNumber("Enter The Number To Count in Matrix? ");
	int NumberCount = 0;
	NumberCount = CountNumberInMatrix(Matrix, Rows, Cols, NumberToCount);

	cout << "\nNumber " << NumberToCount << " Count in Matrix is : " << NumberCount << endl;
}

int main()
{
	int Matrix[3][3] = { {1,9,1},{1,1,9},{9,1,1} };

	cout << "Matrix1 : " << endl;
	PrintMatrix(Matrix, 3, 3);
	cout << endl;
	PrintResults(Matrix, 3, 3);
	

	return 0;
}
