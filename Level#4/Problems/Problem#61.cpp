#include <iostream>

using namespace std;

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

struct sPeriod
{
	sDate StartDate;
	sDate EndDate;
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

sPeriod ReadFullPeriod()
{
	sPeriod Period;

	cout << "\nEnter Start Date:\n" << endl;
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();

	return Period;
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EquelDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EquelDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDate(sDate Date1, sDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EquelDate2(Date1, Date2))
		return enDateCompare::Equal;

	//if (IsDate1AfterDate2(Date1, Date2))
	//	return enDateCompare::Equal;

	return enDateCompare::After;
}

short GetDiffernceInDates(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	short Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseTheDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}

short PeriodLengthInDays(sPeriod Period, bool InculidngEndDate = false)
{
	return GetDiffernceInDates(Period.StartDate, Period.EndDate, InculidngEndDate);
}

bool IsOverLapPeriods(sPeriod Period1, sPeriod Period2)
{
	if (
		CompareDate(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
		||
		CompareDate(Period2.StartDate, Period1.EndDate) == enDateCompare::After
		)
		return false;
	else
		return true;
}

bool IsDateWithinPeriod(sPeriod Period, sDate Date)
{
	return !(
		CompareDate(Date, Period.StartDate) == enDateCompare::Before
		||
		CompareDate(Date, Period.EndDate) == enDateCompare::After
		);
}

short CountOverLapDays(sPeriod Period1, sPeriod Period2)
{
	short PeriodLenght= PeriodLengthInDays(Period2);
	short OverLapDays = 0;
	if (IsDateWithinPeriod(Period1, Period2.StartDate))
	{
		while (IsDateWithinPeriod(Period1, Period2.StartDate))
		{
			OverLapDays++;
			Period2.StartDate = IncreaseTheDateByOneDay(Period2.StartDate);
		}
		if (OverLapDays > PeriodLenght)
		{
			return PeriodLenght;
		}
		return OverLapDays;
	}
	else
	{
		PeriodLenght = PeriodLengthInDays(Period1);
		while (IsDateWithinPeriod(Period2, Period1.StartDate))
		{
			OverLapDays++;
			Period1.StartDate = IncreaseTheDateByOneDay(Period1.StartDate);
		}
		if (OverLapDays > PeriodLenght)
		{
			return PeriodLenght;
		}
		return OverLapDays;
	}
}

int main()
{
	cout << "Enter Period 1:";
	sPeriod Period1 = ReadFullPeriod();

	cout << "\n\nEnter Period 2:";
	sPeriod Period2 = ReadFullPeriod();

	cout <<"\nOverLap Days is : " << CountOverLapDays(Period1, Period2);

	system("pause>0");
	return 0;
}