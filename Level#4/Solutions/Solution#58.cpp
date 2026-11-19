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

int main()
{
	cout << "Enter Period 1:";
	sPeriod Period1 = ReadFullPeriod();

	cout << "\n\nEnter Period 2:";
	sPeriod Period2 = ReadFullPeriod();

	if (IsOverLapPeriods(Period1, Period2))
		cout << "Yes, Period OverLap";
	else
		cout << "No, Periods Don't OverLap";


	system("pause>0");
	return 0;
}