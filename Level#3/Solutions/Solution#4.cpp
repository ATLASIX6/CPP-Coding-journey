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

int ColSum(int arr[3][3], short Rows, short ColsNumber)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColsNumber];
	}
	return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe Following arr the Sum of Each Col is the Matrix:\n";
	for (short j = 0; j < Cols; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\nThr following is a 3x3 random Matrix: \n";
	PrintMatrix(arr, 3, 3);

	PrintEachColSum(arr, 3, 3);

	system("pause>0");
	return 0;


}
