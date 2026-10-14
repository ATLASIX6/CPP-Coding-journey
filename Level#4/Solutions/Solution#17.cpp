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

	cout << "\nPlease Enter a Day ?  ";
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

int GetDiffernceInDates(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseTheDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}

int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	cout << "\nDiffrence is : " 
		<< GetDiffernceInDates(Date1, Date2) << " Days";
	cout << "\nDiffrence(including End day) is : "
		<< GetDiffernceInDates(Date1, Date2, true) << " Days";


	return 0;
}
