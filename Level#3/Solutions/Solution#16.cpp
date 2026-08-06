#include <iostream>
#include<iomanip>

using namespace std;

short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short cols)
{
	short NumberCount = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				NumberCount++;
			}
		}
	}

	return NumberCount;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//printf(" %0*d ", 2, arr[i][j]);
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;
	return (CountNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));
}

int main()
{
	int Matrix[3][3] = { {0,0,0},{0,0,2},{2,2,0} };

	cout << "\nMatrix1 :\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsSparseMatrix(Matrix, 3, 3))
		cout << "\nYES: Matrix is Sparse \n";
	else
		cout << "\nNO: Matrix is NOT Sparse \n";


	system("pause>0");
	return 0;
}
