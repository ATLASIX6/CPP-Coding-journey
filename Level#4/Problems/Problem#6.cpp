#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
	// if Year id^s divisible by 4 AND not Divisible by 100
	// OR if Year is divisible by 400
	// then it is a Leap Year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsIt31DaysMonth(short Month)
{
	short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

	for (short i = 1; i < 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return true;
	}

	return false;

}

short NumberDaysInMonth(short Month, short Year)
{

	if (Month < 1 || Month > 12)
		return 0;

	return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : (IsIt31DaysMonth(Month) ? 31 : 30);

}

int NumberHoursInMonth(short Month, short Year)
{
	return NumberDaysInMonth(Month, Year) * 24;
}

int NumberMinutsInMonth(short Month, short Year)
{
	return NumberHoursInMonth(Month, Year) * 60;
}

int NumberSecondsInMonth(short Month, short Year)
{
	return NumberMinutsInMonth(Month, Year) * 60;
}

short ReadYear()
{
	short Year = 0;

	cout << "Please Enter Year To check? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	int Month = 0;

	cout << "Please Enter A Mont To Check? ";
	cin >> Month;

	return Month;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber Of Days     in Month [" << Month << "] is "
		<< NumberDaysInMonth(Month, Year);
	cout << "\nNumber Of Hours    in Month [" << Month << "] is "
		<< NumberHoursInMonth(Month, Year);
	cout << "\nNumber Of Minutes  in Month [" << Month << "] is "
		<< NumberMinutsInMonth(Month, Year);
	cout << "\nNumber Of Seconds  in Month [" << Month << "] is "
		<< NumberSecondsInMonth(Month, Year);
	system("pause>0");
	return 0;
}
