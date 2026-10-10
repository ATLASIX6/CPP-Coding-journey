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

	cout << "\nPlease Enter a Day ?  ";
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
	if (Date.Day == NumberDaysInMonth(Date.Month, Date.Year))
		return true;
	
	return false;
}

bool IsLastMonthTheYear(sDate Date)
{
	if (Date.Month == 12)
		return true;

	return false;
}

void CheckLastDateOfMonth(sDate Date)
{
	if (IsLastDayOfMonth(Date))
		cout << "\nYes, The Day is the last day in the Month";
	else
		cout << "\nNo, The Day is NOT the last day in the Month";

}

void CheckLastMonthOfTheYear(sDate Date)
{
	if (IsLastMonthTheYear(Date))
		cout << "\nYes, The Month is the last Month in the Year";
	else
		cout << "\nNo, The Month is NOT the last Month in the Year";

}


int main()
{
	sDate Date = ReadFullDate();

	CheckLastDateOfMonth(Date);
	CheckLastMonthOfTheYear(Date);

	system("pause>0");
}
