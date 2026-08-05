// Problem#10
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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d   ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int SumOfMatrix(int Matrix[3][3], int Row, int Cols)
{
	int SumOfMatrix = 0;

	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			SumOfMatrix += Matrix[i][j];
		}
	}

	return SumOfMatrix;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum Of Matrixe = " << SumOfMatrix(Matrix1, 3, 3) << endl;

	system("pause>0");
	return 0;
}
