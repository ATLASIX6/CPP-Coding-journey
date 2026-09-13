#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
	// if Year id^s divisible by 4 AND not Divisible by 100
	// OR if Year is divisible by 400
	// then it is a Leap Year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
	return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
	return NumberOfMinutesInAYear(Year) * 60;
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

	cout << "\nNumber Of Days     in Year [" << Year << "] is "
		<< NumberOfDaysInAYear(Year);
	cout << "\nNumber Of Hours    in Year [" << Year << "] is "
		<< NumberOfHoursInAYear(Year);
	cout << "\nNumber Of Minutes  in Year [" << Year << "] is "
		<< NumberOfMinutesInAYear(Year);
	cout << "\nNumber Of Seconds  in Year [" << Year << "] is "
		<< NumberOfSecondsInAYear(Year);

	system("pause>0");
	return 0;
}
