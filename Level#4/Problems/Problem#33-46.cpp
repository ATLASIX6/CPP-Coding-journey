#include <iostream>

using namespace std;
struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

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

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31 ,30,31 };

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

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsLastDayOfMonth(sDate Date)
{
	return Date.Day == NumberDaysInMonth(Date.Month, Date.Year);
}

bool IsTheFirstDayOfTheMonth(sDate Date)
{
	return Date.Day == 1;
}

bool IsLastMonthTheYear(short Month)
{
	return (Month == 12);

}

bool IsFirstMonthOfTheYear(short Month)
{
	return Month == 1;
}

sDate DecearseTheDateByOneDay(sDate Date)
{
	if (IsTheFirstDayOfTheMonth(Date))
	{
		if (IsFirstMonthOfTheYear(Date.Month))
		{
			Date.Month = 12;
			Date.Year--;
			Date.Day = NumberDaysInMonth(Date.Month, Date.Year);

		}
		else
		{
			Date.Month--;
			Date.Day = NumberDaysInMonth(Date.Month,Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;

}

sDate DecreaseTheDateByXDays(sDate Date, short NumberOfDaysToAdd)
{
	for (short i = 0; i < NumberOfDaysToAdd; i++)
	{
		Date = DecearseTheDateByOneDay(Date);
	}

	return Date;
}

sDate DecreaseTheDateByOneWeek(sDate Date)
{
	Date = DecreaseTheDateByXDays(Date, 7);

	return Date;
}

sDate DecreaseTheDateByXWeeks(sDate Date, short NumberOfWeeksToAdd)
{
	for (short i = 0; i < NumberOfWeeksToAdd; i++)
	{
		Date = DecreaseTheDateByOneWeek(Date);
	}

	return Date;
}

sDate DecreaseTheDateByOneMonth(sDate Date)
{
	//Date = DecreaseTheDateByXDays(Date, 31);

	Date.Month = Date.Month - 1;

	if (Date.Month < 1)
	{
		Date.Month = 12;
		Date.Year--;
	}

	return Date;
}

sDate DecreaseTheDateByXMonths(sDate Date, short NumberOfMonthsToAdd)
{
	for (short i = 0; i < NumberOfMonthsToAdd; i++)
	{
		Date = DecreaseTheDateByOneMonth(Date);
	}

	return Date;
}

sDate DecreaseTheDateByOneYear(sDate Date)
{
	Date = DecreaseTheDateByXMonths(Date, 12);

	return Date;
}

sDate DecreaseTheDateByXYears(sDate Date, short NumberOfYearsToAdd)
{
	for (short i = 0; i < NumberOfYearsToAdd; i++)
	{
		Date = DecreaseTheDateByOneYear(Date);
	}

	return Date;
}

sDate DecreaseTheDateByXYearsFaster(sDate Date, short NumberOfYearsToSub)
{
	Date.Year = Date.Year - NumberOfYearsToSub;

	return Date;
}

sDate DecreaseTheDateByOneDecade(sDate Date)
{
	Date = DecreaseTheDateByXYears(Date, 10);

	return Date;
}

sDate DecreaseTheDateByXDecades(sDate Date, short NumberOfDecadesToSub)
{
	for (short i = 0; i < NumberOfDecadesToSub; i++)
	{
		Date = DecreaseTheDateByOneDecade(Date);
	}

	return Date;
}

sDate DecreaseTheDateByXDecadesFaster(sDate Date, short NumberOfDecadesToAdd)
{

	Date.Year = Date.Year - (NumberOfDecadesToAdd * 10);

	return Date;
}

sDate DecreaseTheDateByOneCentury(sDate Date)
{
	Date = DecreaseTheDateByXDecadesFaster(Date, 10);

	return Date;
}

sDate DecreaseTheDateByOneMillennium(sDate Date)
{
	Date = DecreaseTheDateByXDecades(Date, 100);

	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	cout << "\nDate After : \n";

	Date = DecearseTheDateByOneDay(Date);
	cout << "\n01-Subtracting one Day is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	short NumberOfDaysToAdd = 10;
	Date = DecreaseTheDateByXDays(Date, NumberOfDaysToAdd);
	cout << "\n02-Subtracting " << NumberOfDaysToAdd << " Day is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecreaseTheDateByOneWeek(Date);
	cout << "\n03-Subtracting One Week is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	short NumberOfWeeksToAdd = 10;
	Date = DecreaseTheDateByXWeeks(Date, NumberOfWeeksToAdd);
	cout << "\n04-Subtracting " << NumberOfWeeksToAdd << " Week is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseTheDateByOneMonth(Date);
	cout << "\n05-Subtracting One Month is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	short NumberOfMonthsToAdd = 5;
	Date = DecreaseTheDateByXMonths(Date, NumberOfMonthsToAdd);
	cout << "\n06-Subtracting " << NumberOfMonthsToAdd << " Months is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseTheDateByOneYear(Date);
	cout << "\n07-Subtracting One Year is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	short NumberOfYearsToAdd = 10;
	Date = DecreaseTheDateByXYears(Date, NumberOfYearsToAdd);
	cout << "\n08-Subtracting " << NumberOfYearsToAdd << " Years is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseTheDateByXYearsFaster(Date, NumberOfYearsToAdd);
	cout << "\n09-Subtracting " << NumberOfYearsToAdd << " Years (Faster) is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecreaseTheDateByOneDecade(Date);
	cout << "\n10-Subtracting One Decade is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	short NumberOfDecadesToAdd = 10;
	Date = DecreaseTheDateByXDecades(Date, NumberOfDecadesToAdd);
	cout << "\n11-Subtracting " << NumberOfDecadesToAdd << " Decade is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseTheDateByXDecadesFaster(Date, NumberOfDecadesToAdd);
	cout << "\n12-Subtracting " << NumberOfDecadesToAdd << " Decade (Faster) is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseTheDateByOneCentury(Date);
	cout << "\n13-Subtracting One Century is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseTheDateByOneMillennium(Date);
	cout << "\n14-Subtracting One Millenuim is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	system("pause>0");
	return 0;
}
