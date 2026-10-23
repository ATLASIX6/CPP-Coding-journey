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

sDate IncreaseTheDateByOneDay(sDate Date)
{
	if (IsLastDayOfMonth(Date))
	{
		if (IsLastMonthTheYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;

}

sDate IncreaseTheDateByXDays(sDate Date, short Days)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseTheDateByOneDay(Date);
	}

	return Date;
}

sDate IncreaseTheDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseTheDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseTheDateByXWeeks(sDate Date, short Weeks)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseTheDateByOneWeek(Date);
	}

	return Date;
}

sDate IncreaseTheDateByOneMonth(sDate Date)
{

	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
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

sDate IncreaseTheDateByXMonths(sDate Date, short Months)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseTheDateByOneMonth(Date);
	}

	return Date;
}

sDate IncreaseTheDateByOneYear(sDate Date)
{
	Date.Year++;
	return Date;
}

sDate InceaseTheDateByXYears(sDate Date, short Years)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseTheDateByOneYear(Date);
	}

	return Date;
}

sDate InceaseTheDateByXYearsFaster(sDate Date, short Years)
{
	Date.Year += Years;

	return Date;
}

sDate IncreaseTheDateByOneDecade(sDate Date)
{
	//Period of 10 years
	Date.Year += 10;
	return Date;
}

sDate IncreaseTheDateByXDecades(sDate Date, short Decades)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseTheDateByOneYear(Date);
	}

	return Date;
}

sDate IncreaseTheDateByXDecadesFaster(sDate Date, short Decades)
{

	Date.Year += Decades * 10;

	return Date;
}

sDate IncreaseTheDateByOneCentury(sDate Date)
{
	//Period of 100 years
	Date.Year += 100;

	return Date;
}

sDate IncreaseTheDateByOneMillennium(sDate Date)
{
	//period of 1000 years
	Date.Year += 1000;
	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	cout << "\nDate After : \n";

	Date = IncreaseTheDateByOneDay(Date);
	cout << "\n01-Adding one Day is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	short NumberOfDaysToAdd = 10;
	Date = IncreaseTheDateByXDays(Date, NumberOfDaysToAdd);
	cout << "\n02-Adding " << NumberOfDaysToAdd << " Day is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncreaseTheDateByOneWeek(Date);
	cout << "\n03-Adding One Week is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	short NumberOfWeeksToAdd = 10;
	Date = IncreaseTheDateByXWeeks(Date, NumberOfWeeksToAdd);
	cout << "\n04-Adding " << NumberOfWeeksToAdd << " Week is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseTheDateByOneMonth(Date);
	cout << "\n05-Adding One Month is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	short NumberOfMonthsToAdd = 5;
	Date = IncreaseTheDateByXMonths(Date, NumberOfMonthsToAdd);
	cout << "\n06-Adding " << NumberOfMonthsToAdd << " Months is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseTheDateByOneYear(Date);
	cout << "\n07-Adding One Year is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	short NumberOfYearsToAdd = 10;
	Date = InceaseTheDateByXYears(Date, NumberOfYearsToAdd);
	cout << "\n08-Adding " << NumberOfYearsToAdd << " Years is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = InceaseTheDateByXYearsFaster(Date, NumberOfYearsToAdd);
	cout << "\n09-Adding " << NumberOfYearsToAdd << " Years (Faster) is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncreaseTheDateByOneDecade(Date);
	cout << "\n10-Adding One Decade is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	short NumberOfDecadesToAdd = 10;
	Date = IncreaseTheDateByXDecades(Date, NumberOfDecadesToAdd);
	cout << "\n11-Adding " << NumberOfDecadesToAdd << " Decade is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseTheDateByXDecadesFaster(Date, NumberOfDecadesToAdd);
	cout << "\n12-Adding " << NumberOfDecadesToAdd << " Decade (Faster) is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseTheDateByOneCentury(Date);
	cout << "\n13-Adding One Century is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseTheDateByOneMillennium(Date);
	cout << "\n14-Adding One Millenuim is  : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year;


	system("pause>0");
	return 0;
}
