#include <iostream>

using namespace std;

bool ChekIfLeapYear(int Year)
{
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	{
		return true;
	}

	return false;
}

int ReadYear()
{
	int Year = 0;

	cout << "Please enter a Year? ";
	cin >> Year;

	return Year;
}

int main()
{
	int year = ReadYear();

	if (ChekIfLeapYear(year))
		cout << year << " its a Leap Year ";
	else
		cout << year << " its NOT Leap Year ";

	system("pause>0");
	return 0;
}
