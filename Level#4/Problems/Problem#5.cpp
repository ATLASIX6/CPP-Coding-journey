#include <iostream>

using namespace std;

enum enMonths { January = 1, February, March, April, May, June, July, August, September, October, November, December };

bool IsLeapYear(short Year)
{
	// if Year id^s divisible by 4 AND not Divisible by 100
	// OR if Year is divisible by 400
	// then it is a Leap Year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DaysInMonth(enMonths Month,short Year)
{
	switch (Month)
	{
	case enMonths::January:
		return 31;
		break;
	case enMonths::February:
		if (IsLeapYear(Year))
			return 29;
		else
			return 28;
		break;
	case enMonths::March:
		return 31;
		break;
	case enMonths::April:
		return 30;
		break;
	case enMonths::May:
		return 31;
		break;
	case enMonths::June:
		return 30;
	case enMonths::July:
		return 31;
		break;
	case enMonths::August:
		return 31;
		break;
	case enMonths::September:
		return 30;
		break;
	case enMonths::October:
		return 31;
		break;
	case enMonths::November:
		return 30;
		break;
	case enMonths::December:
		return 31;
		break;

	}
}

int HoursInMonth(enMonths Month, short Year)
{
	return DaysInMonth(Month, Year) * 24;
}

int MinutsInMonth(enMonths Month, short Year)
{
	return HoursInMonth(Month, Year) * 60;
}

int SecondsInMonth(enMonths Month, short Year)
{
	return MinutsInMonth(Month, Year) * 60;
}

short ReadYear()
{
	short Year = 0;

	cout << "Please Enter Year To check? ";
	cin >> Year;

	return Year;
}

enMonths ReadMonth()
{
	int Month = 0;

	cout << "Please Enter A Mont To Check? ";
	cin >> Month;

	return enMonths(Month);
}

int main()
{
	short Year = ReadYear();
	enMonths Month = ReadMonth();

	cout << "\nNumber Of Days     in Month [" << Month << "] is "
		<< DaysInMonth(Month, Year);
	cout << "\nNumber Of Hours    in Month [" << Month << "] is "
		<< HoursInMonth(Month, Year);
	cout << "\nNumber Of Minutes  in Month [" << Month << "] is "
		<< MinutsInMonth(Month, Year);
	cout << "\nNumber Of Seconds  in Month [" << Month << "] is "
		<< SecondsInMonth(Month, Year);
	system("pause>0");
	return 0;
}
