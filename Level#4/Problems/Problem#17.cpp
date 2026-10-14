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

short DiffrentbetwinDates(sDate Date1, sDate Date2)
{
	short Year = 365;
	short NumberOfDays = 0;
	if (Date1.Year == Date2.Year)
	{
		NumberOfDays = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);	
		return NumberOfDays;
	}
	else
	{
		if (IsLeapYear(Date1.Year))
		{
			Year = 366;
		}
		NumberOfDays = Year - NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);

		for (int i = Date1.Year + 1; i < Date2.Year; i++)
		{
			if (IsLeapYear(i))
			{
				Year = 366;
			}
			NumberOfDays += Year;
			Year = 365;
		}
		NumberOfDays += NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);
		return NumberOfDays;
	}
}

int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	while (!IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\nDate1 is Noy Befor Date 2 Please Enter the dates agian";
		sDate Date1 = ReadFullDate();
		sDate Date2 = ReadFullDate();
	}

	cout << "\nDiffrence: " << DiffrentbetwinDates(Date1, Date2) << " Days";
	cout << "\nDiffrence(including End day): " << DiffrentbetwinDates(Date1, Date2) + 1 << " Days";

	return 0;
}
