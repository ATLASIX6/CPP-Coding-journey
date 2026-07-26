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

void PrintMinAndMaxInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Max = Matrix[0][0];
	int Min = Matrix[0][0];

	//Max
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Max < Matrix[i][i])
			{
				Max = Matrix[i][j];
			}
		}
	}
	//Min
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Min > Matrix[i][i])
			{
				Min = Matrix[i][j];
			}
		}
	}

	cout << "\nMinimum Number is : " << Min << endl;
	cout << "\nMaximum Number is : " << Max << endl;

}

int main()
{
	int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	PrintMinAndMaxInMatrix(Matrix1, 3, 3);

	system("pause>0");
	return 0;
}
