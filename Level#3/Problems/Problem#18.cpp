// Problem#18
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

bool IsNumberInMatrix(int Matrix[3][3], int Numeber, short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Numeber)
			{
				return true;
			}
		}
	}
	return false;
}

void IntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	cout << "\nIntersected Numbers are : \n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (IsNumberInMatrix(Matrix2,Matrix1[i][j],Rows,Cols))
			{
				cout << Matrix1[i][j] << "    ";
			}
		}
	}
}
int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	IntersectedNumbers(Matrix1, Matrix2, 3, 3);


	system("pause>0");
	return 0;
}
