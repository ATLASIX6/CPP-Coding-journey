#include <iostream>

using namespace std;

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

short DayOfWeakOrder(short Day, short Month, short Year)
{
	int A = ((14 - Month) / 12);
	int Y = Year - A;
	int M = Month + (12 * A) - 2;

	//Gregorion
	// 0:Sun,1:Mon,2:Tue....etc
	int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	return D;
}

string MonthShortName(short MonthNumber)
{
	string arrMonths[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	return (arrMonths[MonthNumber - 1]);
}

void PrintCalnder(short Month, short Year)
{
	int NumberOfDays;

	//Index of the day from 0 to 6
	int current = DayOfWeakOrder(1, Month, Year);

	NumberOfDays = NumberDaysInMonth(Month, Year);

	// Print the current month Name 
	printf("\n ________________%s________________\n\n",
		MonthShortName(Month).c_str());

	// Print the Day Colums
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");


	// Print appropriate spaces
	int i;
	for ( i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n ___________________________________\n");
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintCalnder(Month, Year);

	
	system("pause>0");
	return 0;
}
