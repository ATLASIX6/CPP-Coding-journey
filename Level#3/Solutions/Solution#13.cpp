// Solution#13
#include <iostream>

using namespace std;

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d   ", 1, arr[i][j]);
		}
		cout << endl;
	}
}

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
	//Check Diagonal elements are 1 and rest elements are 0

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			//Check for Diagonals element
			if (i == j && Matrix[i][j] != 1)
			{
				return false;
			}
			//Check for rest of element
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	//int Matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	cout << "\nMatrix:\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsIdentityMatrix(Matrix,3,3))
		cout << "\nYES: Matrix is identity.";
	else
		cout << "\nNO: Matrix is NOT identity.";

	system("pause>0");

	return 0;
}
