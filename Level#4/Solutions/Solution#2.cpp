#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{

	// leap Year if Pefrectly divisible by 400
	if (Year % 400 == 0)
	{
		return true;
	}

	// not a leap Year if divisible by 100
	// but divisible by 400
	else if (Year % 100 == 0)
	{
		return false;
	}
	// leap Year if not divisible by 100
	// but divisible by 4
	else if (Year % 4 == 0)
	{
		return true;
	}
	// all other years are not leap years
	else
	{
		return false;
	}

}

short ReadYear()
{
	short Year = 0;

	cout << "Please enter year to check? ";
	cin >> Year;

	return Year;
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
		cout << "\nYes, Year [" << Year << "] is a Leap Year\n";
	else
		cout << "\nNO, Year [" << Year << "] is NOT a Leap Year\n";

	system("pause>0");
	return 0;
}
