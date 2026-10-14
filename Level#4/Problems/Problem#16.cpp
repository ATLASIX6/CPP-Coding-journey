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

void IncreaseTheDateByOneDay(sDate &Date)
{
	Date.Day++;
	if (Date.Day > NumberDaysInMonth(Date.Month, Date.Year))
	{
		Date.Day = 1;
		Date.Month++;
		
		if (Date.Month > 12)
		{
			Date.Month = 1;
			Date.Year++;
		}

	}

}

int main()
{
	sDate Date = ReadFullDate();

	IncreaseTheDateByOneDay(Date);

	cout << "\nDate after adding one date : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}
