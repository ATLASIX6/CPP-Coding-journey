#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
	// if Year id^s divisible by 4 AND not Divisible by 100
	// OR if Year is divisible by 400
	// then it is a Leap Year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadYear()
{
	short Year = 0;

	cout << "Please Enter Year To check? ";
	cin >> Year;

	return Year;
}

int main()
{

	short Year = ReadYear();

	if (IsLeapYear(Year))
		cout << "\nYes,Year [" << Year << "] Is A Leap Year\n";
	else
		cout << "\nNo,Year [" << Year << "] Is NOT A Leap Year\n";

	system("pause>0");
	return 0;
}