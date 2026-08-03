// Solution#4
#include <iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;

}

void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "       ";
		}
		cout << endl;
	}
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}

void SumMatrixColsinArray(int arr[3][3], int arrSum[3], int Rows, int Cols)
{
	for (short j = 0; j < Rows; j++)
	{
		arrSum[j] = ColSum(arr, Rows, j);
	}
}

void PrintColsSumArray(int arrSuum[3], short Length)
{
	cout << "\nThe Following arr the Sum of Each Col is the Matrix:\n";
	for (short i = 0; i < Length; i++)
	{
		cout << " Col " << i + 1 << " Sum = " << arrSuum[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\nThr following is a 3x3 random Matrix: \n";
	PrintMatrix(arr, 3, 3);

	SumMatrixColsinArray(arr, arrSum, 3, 3);
	PrintColsSumArray(arrSum, 3);
	system("pause>0");
	return 0;


}
