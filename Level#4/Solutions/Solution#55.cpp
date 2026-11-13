#pragma warning(disable:4996)
#include <iostream>

using namespace std;

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

bool IsDate1EquelDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

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

string DayName(short DayOfWeakOrder)
{
	string arrDayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	return arrDayName[DayOfWeakOrder];
}

short DayOfWeakOrder(short Year, short Month, short Day)
{
	int A = ((14 - Month) / 12);
	int Y = Year - A;
	int M = Month + (12 * A) - 2;

	//Gregorion
	// 0:Sun,1:Mon,2:Tue....etc
	int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	return D;
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

short DayOfWeakOrder(sDate Date)
{
	return DayOfWeakOrder(Date.Year, Date.Month, Date.Day);
}

sDate GetSystemDate()
{
	sDate Date;
	sDate Date2;

	// - new way -
	time_t t2 = time(0);
	tm now2;
	localtime_s(&now2, &t2);
	Date2.Year = now2.tm_year + 1900;
	Date2.Month = now2.tm_mon + 1;
	Date2.Day = now2.tm_mday;

	// - old way -
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date2;
}

bool IsEndOfWeek(sDate Date)
{
	return  DayOfWeakOrder(Date) == 6;
}

bool IsWeekEnd(sDate Date)
{
	//Weekend are Fri and Sat
	short DayInDex = DayOfWeakOrder(Date);
	return (DayInDex == 5 || DayInDex == 6);
}

bool IsBusinessDay(sDate Date)
{
	//Business days are Sun, Mon, Tue, Wed and 
	/*
	short DayInDex = DayOfWeakOrder(Date);
	return (DayInDex >= 5 && DayInDex <= 4);
	*/

	return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeakOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date)
{
	sDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberDaysInMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDiffernceInDates(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate Date)
{

	sDate EndOfYearDate;
	EndOfYearDate.Day = 32;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDiffernceInDates(Date, EndOfYearDate, true);
}

short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
	short NumberOfVacationDays = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			NumberOfVacationDays++;

		DateFrom = IncreaseTheDateByOneDay(DateFrom);
	}
	return NumberOfVacationDays;
}

short ReadVecationDays()
{
	short VecationDays = 0;

	cout << "\nPlease enter Vecation Days? ";
	cin >> VecationDays;

	return VecationDays;
}

sDate CalcukateVacationReturnDate(sDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;

	//in case the date is weekend keep adding one day until you reach businees day
	//we get rid of all weekend befor the first businees day 
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseTheDateByOneDay(DateFrom);
	}

	//here we increase the vacation dates to add all weekends to it 
	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{
		if (IsWeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseTheDateByOneDay(DateFrom);
	}

	//in case the return date is week end keep adding one day until you reacha businees day
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseTheDateByOneDay(DateFrom);

	}

	return DateFrom;
}

int main()
{
	cout << "Vacation Starts : " << endl;
	sDate Date = ReadFullDate();

	short VecationDays = ReadVecationDays();

	sDate ReturnDate = CalcukateVacationReturnDate(Date, VecationDays);

	cout << "\n\n\nReturn Date is " << DayName(DayOfWeakOrder(ReturnDate)) << ", ";
	cout << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year;
	system("pause>0");
	return 0;
}
