#include <iostream>

using namespace std;

void PrintYearInfo(short Year, short NumberOfDays)
{
	cout << "\nNumber Of Days    in Year [" << Year << "] Is " << NumberOfDays;
	cout << "\nNumber Of Hours   in Year [" << Year << "] Is " << NumberOfDays * 24;
	cout << "\nNumber Of Minutes in Year [" << Year << "] Is " << NumberOfDays * 24 * 60;
	cout << "\nNumber Of Seconds in Year [" << Year << "] Is " << NumberOfDays * 24 * 60 * 60;
}

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
	short NumberOfDayInYear = 0;

	if (IsLeapYear(Year))
	{
		NumberOfDayInYear = 366;
		PrintYearInfo(Year, NumberOfDayInYear);
	}
	else
	{
		NumberOfDayInYear = 365;
		PrintYearInfo(Year, NumberOfDayInYear);
	}

	system("pause>0");
	return 0;
}