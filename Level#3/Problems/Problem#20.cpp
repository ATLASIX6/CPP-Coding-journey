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
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void ReversMatrix(int Matrix[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix2[i][Cols - j - 1] = Matrix[i][j];
		}
	}

}

bool IsPalnidromMatrix(int Matrix[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	ReversMatrix(Matrix, Matrix2, 3, 3);
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] != Matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int Matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
	int Matrix2[3][3];
	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, 3, 3);

	if (IsPalnidromMatrix(Matrix, Matrix2, 3, 3))
		cout << "\nYES: Matrix is Palindrome\n";
	else
		cout << "\nNO: Matrix is NOT Palindrome\n";
	

	system("pause>0");
	return 0;
}
