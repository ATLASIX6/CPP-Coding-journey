#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
	// if Year id^s divisible by 4 AND not Divisible by 100
	// OR if Year is divisible by 400
	// then it is a Leap Year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberDaysInMonth(short Month, short Year)
{

	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

short ReadYear()
{
	short Year = 0;

	cout << "Please Enter a Year ?  ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;

	cout << "Please Enter a Month ?  ";
	cin >> Month;

	return Month;
}

short ReadDay()
{
	short Day = 0;

	cout << "Please Enter a Day ?  ";
	cin >> Day;

	return Day;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;
	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberDaysInMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

void NumberOfDaysToDate(short NumberOfDays, short Year)
{
	short DaysLeft = NumberOfDays;
	short i;
	for ( i = 1; i <= 12; i++)
	{
		DaysLeft = DaysLeft - NumberDaysInMonth(i, Year);
		if (DaysLeft <= 0)
		{
			break;
		}
	}
	cout << "\nDate for [" << NumberOfDays << "] is :";
	cout << DaysLeft + NumberDaysInMonth(i, Year) << "/" << i << "/" << Year;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short NumberOfDays = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);


	cout << "\nNumber Of Days from the Begining of the year is "
		<< NumberOfDays << endl;

	NumberOfDaysToDate(NumberOfDays, Year);

	system("pause>0");
	return 0;
}
