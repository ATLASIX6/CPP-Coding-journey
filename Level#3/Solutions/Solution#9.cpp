// problem#9
#include <iostream>
#include<cstdlib>

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

void PrintMidlleRowOfMatrix(int arr[3][3], int Rows, int Cols)
{
	short MidlleRow = Rows / 2;

	for (int i = 0; i < Cols; i++)
	{
		printf(" %0*d   ", 2, arr[MidlleRow][i]);

	}

	cout << "\n";
}

void PrintMidlleColOfMatrix(int arr[3][3], int Rows, int Cols)
{
	short MidlleRow = Cols / 2;

	for (int i = 0; i < Rows; i++)
	{
		printf(" %0*d   ", 2, arr[i][MidlleRow]);

	}

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nMatrix1 :\n";
	PrintMatrix(arr, 3, 3);

	cout << "\nMidlle Row of Matrix 1 is :\n";
	PrintMidlleRowOfMatrix(arr, 3, 3);

	cout << "\nMidlle col of Matrix 1 is :\n";
	PrintMidlleColOfMatrix(arr, 3, 3);

	system("pause>0");

	return 0;
}
