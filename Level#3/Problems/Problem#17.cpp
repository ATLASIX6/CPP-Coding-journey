// Problem#17
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

int main()
{
	int Matrix[3][3] = { {77,5,12},{22,20,1},{1,0,9} };

	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, 3, 3);

	int Number = 0;
	cout << "Please Enter the Number To Look for in Matirx ? ";
	cin >> Number;
	//Using Count is a slower method
	if (CountNumberInMatrix(Matrix, Number, 3, 3) != 0)
		cout << "\nYES it is there.\n";
	else
		cout << "\nNO it is NOT there.\n";

	if (IsNumberInMatrix(Matrix, Number, 3, 3))
		cout << "\nYES it is there.\n";
	else
		cout << "\nNO it is NOT there.\n";


	return 0;
}
