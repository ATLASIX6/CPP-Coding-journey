#include <iostream>
#include<iomanip>

using namespace std;

string DayName(short DayOfWeakOrder)
{
	string arrDayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	return arrDayName[DayOfWeakOrder];
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

short PrintCalnder(short Year, short Month)
{
	cout << "\t";
	int j = 7;
	for (short i = 0; i < DayOfWeakOrder(Year, Month, 1); i++)
	{
		cout << "      ";
	}
	j = j - DayOfWeakOrder(Year, Month, 1);
	for (short i = 1; i <= NumberDaysInMonth(Month, Year); i++)
	{
		
		cout << setw(2) << i << "    ";
	
		if (i == j)
		{
			j = j + 7;
			cout << "\n";
			cout << "\t";
		}
	}
	
	return 0;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	string arrMonths[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

	cout << "\n\n\t________________ " << arrMonths[Month - 1] << " _______________\n\n";
	cout << "\tSun   Mun   Tue   Wed   Thu   Fri   Set\n";

	PrintCalnder(Year, Month);
	cout << "\n\t_______________________________________\n\n";

	system("pause>0");
	return 0;
}
