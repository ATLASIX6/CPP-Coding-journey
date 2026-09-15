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

	cout << "\nPlease Enter a Year ?  ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;

	cout << "\nPlease Enter a Month ?  ";
	cin >> Month;

	return Month;
}

short ReadDay()
{
	short Day = 0;

	cout << "\nPlease Enter a Day ?  ";
	cin >> Day;

	return Day;
}

short ReadHowManyDays()
{
	short NumberOfDays = 0;

	cout << "\nHow Many Days To Add : ";
	cin >> NumberOfDays;

	return NumberOfDays;
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

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

sDate GetDateFromDaysOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
	short ReminingDays = DateOrderInYear;
	short MonthDays = 1;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberDaysInMonth(Date.Month, Year);

		if (ReminingDays > MonthDays)
		{
			ReminingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = ReminingDays;
			break;
		}
	}

	return Date;
}

sDate DateAfterAddingDays(sDate Date, short NumberOfDaysToAdd)
{
	short DaysLeft = NumberOfDaysToAdd + Date.Day;
	short MonthDays = 1;
	while (true)
	{
		MonthDays = NumberDaysInMonth(Date.Month, Date.Year);
		if (DaysLeft > MonthDays)
		{
			if (Date.Month == 13)
			{
				Date.Year++;
				Date.Month = 1;
				MonthDays = NumberDaysInMonth(Date.Month, Date.Year);
			}
			DaysLeft -= MonthDays;
			Date.Month++; 
		}
		else
		{
			Date.Day = DaysLeft;
			break;
		}
	}
	return Date;
}

int main()
{
	sDate Date;
	sDate NewDate;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	short NumberOfDaysToAdd = ReadHowManyDays();

	NewDate = DateAfterAddingDays(Date, NumberOfDaysToAdd);

	cout << "\nDate After Adding [" << NumberOfDaysToAdd << "] is : "
		<< NewDate.Day << "/" << NewDate.Month << "/" << NewDate.Year;

	system("pause>0");
	return 0;
}
