// Solution#15
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

int main()
{ 
	int Matrix[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

	cout << "\nMatrix1 :\n";
	PrintMatrix(Matrix, 3, 3);

	int Number = 0;
	cout << "\nEnter the Number to count in Matrix? ";
	cin >> Number;

	cout << "\nNumber " << Number << " Count in Matrix is "
		<< CountNumberInMatrix(Matrix, Number, 3, 3) << endl;

	system("pause>0");
	return 0;
}
