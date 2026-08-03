// Solution#2
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

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j < Cols; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void SumMatrixRowsinArray(int arr[3][3], int arrSum[3], int Rows, int Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		arrSum[i] = RowSum(arr, i, Cols);
	}
}

void PrintRowsSumArray(int arrSum[3], short Rows)
{

	cout << "\nThe Following arr the Sum of Each Row is the Matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << arrSum[i] << endl;
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

	SumMatrixRowsinArray(arr, arrSum, 3, 3);
	PrintRowsSumArray(arrSum, 3);

	system("pause>0");
	return 0;


}
