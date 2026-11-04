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

bool IsLastMonthTheYear(short Month)
{
	return (Month == 12);

}

sDate DecreaseTheDateByOneDay(sDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 32;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberDaysInMonth(Date.Month, Date.Year);

		}
	}
	else
	{
		Date.Day--;
	}

	return Date;

}

sDate DecreaseTheDateByXDays(sDate Date, short Days)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseTheDateByOneDay(Date);
	}

	return Date;
}

sDate DecreaseTheDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseTheDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseTheDateByXWeeks(sDate Date, short Weeks)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseTheDateByOneWeek(Date);
	}

	return Date;
}

sDate DecreaseTheDateByOneMonth(sDate Date)
{

	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	//last check day in the date should not exceed max days in the current month
	// example if date is 31/1/2022 increasing one month should not be 31/2/2022
	//it should be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberDaysInMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

sDate DecreaseTheDateByXMonths(sDate Date, short Months)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseTheDateByOneMonth(Date);
	}

	return Date;
}

sDate DecreaseTheDateByOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}

sDate InceaseTheDateByXYears(sDate Date, short Years)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseTheDateByOneYear(Date);
	}

	return Date;
}

sDate InceaseTheDateByXYearsFaster(sDate Date, short Years)
{
	Date.Year -= Years;

	return Date;
}

sDate DecreaseTheDateByOneDecade(sDate Date)
{
	//Period of 10 years
	Date.Year -= 10;
	return Date;
}

sDate DecreaseTheDateByXDecades(sDate Date, short Decades)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = DecreaseTheDateByOneYear(Date);
	}

	return Date;
}

sDate DecreaseTheDateByXDecadesFaster(sDate Date, short Decades)
{

	Date.Year -= Decades * 10;

	return Date;
}

sDate DecreaseTheDateByOneCentury(sDate Date)
{
	//Period of 100 years
	Date.Year -= 100;

	return Date;
}

sDate DecreaseTheDateByOneMillennium(sDate Date)
{
	//period of 1000 years
	Date.Year -= 1000;
	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	cout << "\nDate After : \n";

	Date = DecreaseTheDateByOneDay(Date);
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
	Date = InceaseTheDateByXYears(Date, NumberOfYearsToAdd);
	cout << "\n08-Subtracting " << NumberOfYearsToAdd << " Years is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = InceaseTheDateByXYearsFaster(Date, NumberOfYearsToAdd);
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
