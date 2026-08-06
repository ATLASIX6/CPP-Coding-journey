// Problem#19
#include <iostream>
#include<iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//printf(" %0*d ", 2, arr[i][j]);
			cout << setw(3) << arr[i][j] << "    ";
		}
		cout << "\n";
	}
}

int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Min = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][i] < Min)
			{
				Min = Matrix[i][j];
			}
		}
	}

	return Min;
}

int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Max = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][i] > Max)
			{
				Max = Matrix[i][j];
			}
		}
	}

	return Max;
}

int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum Number is : ";
	cout << MinNumberInMatrix(Matrix1, 3, 3);

	cout << "\nMaximum Number is : ";
	cout << MaxNumberInMatrix(Matrix1, 3, 3);
	
	system("pause>0");
	return 0;
}
