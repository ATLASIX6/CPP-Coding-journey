// Problem#6
#include <iostream>
#include<iomanip>

using namespace std;

void FillMAtrixWithOrderedNumbers(int arr[3][3], int Rows, int Cols)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "      ";
		}
		cout << endl;
	}
}

void TransPoseMatrix(int arr[3][3], int arrTransPose[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arrTransPose[i][j] = arr[j][i];
		}
	}


}

int main()
{

	int arr[3][3];
	int arrTransPose[3][3];
	
	FillMAtrixWithOrderedNumbers(arr, 3, 3);

	cout << "\nthe Follwing is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	TransPoseMatrix(arr, arrTransPose, 3, 3);

	cout << "\n\nthe Follwing is a 3x3 TransPose Matrix :\n";
	PrintMatrix(arrTransPose, 3, 3);

	return 0;
}