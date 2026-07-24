// Problem#13
#include <iostream>
#include<iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 1, Matrix[i][j]);
		}
		cout << endl;
	}
}

bool checkOtherThenDaignel(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i!=j)
			{
				if (Matrix[i][j] != 0)
				{
					return false;
				}
					
			}
		}
	}
	return true;
}

bool CheckDaignel(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j)
			{				
				if (Matrix[i][j] != 1)
				{
					return false;
				}

			}
		}
	}
	return true;
}

int main()
{
	int Matrix[3][3] = {
		{1 ,0 ,0 },
		{0 ,1 ,0 },
		{0 ,0 ,1 }
	};
	cout << "\nMatrix1 :\n";
	PrintMatrix(Matrix, 3, 3);

	if (CheckDaignel(Matrix,3,3)&&checkOtherThenDaignel(Matrix,3,3))
	{
		cout << "YES: it is identity Matrix" << endl;
	}
	else
	{
		cout << "NO: is Not identity Matrix" << endl;

	}

	return 0;
}
