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

short DayOfWeakOrder(sDate Date)
{
	int Day = DayOfWeakOrder(Date.Year, Date.Month, Date.Day);
	return Day;
}

bool IsEndOfWeek(int Day)
{
	return Day == 6;
}

bool IsWeekEnd(int Day)
{
	return Day == 5 || Day == 6;
}

bool IsBusinessDay(int Day)
{
	return !IsWeekEnd(Day);
}

short DaysUntilTheEndOfWeek(int Day)
{
	short NumberOfDays = 0;
	for (short i = Day + 1; i < 7; i++)
	{
		NumberOfDays++;
	}
	return NumberOfDays;
}

short DaysUntilTheEndOfMonth(sDate Date)
{
	short NumberOfDays = 0;
	for (short i = Date.Day; i <= NumberDaysInMonth(Date.Month, Date.Month); i++)
	{
		NumberOfDays++;
	}

	return NumberOfDays;
}

short DaysUntilTheEndOfYear(sDate Date)
{
	short NumberOfDays = DaysUntilTheEndOfMonth(Date);
	Date.Month++;

	for (short i = Date.Month; i <=12 ; i++)
	{
		NumberOfDays += NumberDaysInMonth(i, Date.Year);
	}

	return NumberOfDays;
}

int main()
{
	sDate Date = ReadFullDate();
	int Day = DayOfWeakOrder(Date);

	cout << "\n\nToday is " << DayName(Day) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	cout << "\nIs it End of Week?" << endl;
	if (IsEndOfWeek(Day))
		cout << "Yes is End Of Week\n";
	else
		cout << "No is NOT End Of Week\n";

	cout << "\nIs it Weekend?" << endl;
	if (IsWeekEnd(Day))
		cout << "Yes is a Week end\n";
	else
		cout << "No is NOT  a Week end\n";

	cout << "\nIs it Business Day?" << endl;
	if (IsBusinessDay(Day))
		cout << "Yes is a Business Day\n";
	else
		cout << "No is NOT a Busniess Day\n";

	cout << "\nDays until end of week  : " << DaysUntilTheEndOfWeek(Day) << " Day(s)." << endl;
	cout << "Days until end of month : " << DaysUntilTheEndOfMonth(Date) << " Day(s)." << endl;
	cout << "Days until end of year : " << DaysUntilTheEndOfYear(Date) << " Day(s)." << endl;


	system("pause>0");
	return 0;
}
