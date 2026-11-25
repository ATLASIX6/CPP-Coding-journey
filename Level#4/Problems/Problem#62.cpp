
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

bool ValidateDay(short Day)
{
	return (Day > 31 || Day < 1) ? false : true;
		
}

bool ValidateMonth(short Month, short Day,short Year)
{
	return (Month > 12 || Month < 1) ? false : (Day > NumberDaysInMonth(Month, Year) ? false : true);
	
}

bool ValidateYear(short Year)
{
	return Year > 0 ? true : false;
}

bool ValidateDate(sDate Date)
{
	return ValidateDay(Date.Day) ? (ValidateMonth(Date.Month, Date.Day, Date.Year) ? (ValidateYear(Date.Year) ? true : false) : false) : false;
}

int main()
{

	sDate Date = ReadFullDate();

	if (ValidateDate(Date))
		cout << "\nYes, Date is Valide Date.";
	else
		cout << "\nNo, Date is Not Valide Date.";

	system("pause>0");
	return 0;
}
