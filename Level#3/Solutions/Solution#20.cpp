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

bool IsPalnidromMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
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
	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, 3, 3);

	if (IsPalnidromMatrix(Matrix, 3, 3))
		cout << "\nYES: Matrix is Palindrome\n";
	else
		cout << "\nNO: Matrix is NOT Palindrome\n";


	system("pause>0");
	return 0;
}
