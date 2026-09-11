#include <iostream>

using namespace std;

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

short CalculateTheDay(short Year, short Month, short Day)
{
	int A = ((14 - Month) / 12);
	int Y = Year - A;
	int M = Month + (12 * A) - 2;

	int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	return D;
}

int main()			 
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	short DayOrder = CalculateTheDay(Year, Month, Day);

	string DaysOfTheWeak[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	cout << "Date       :  " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order  :  " << DayOrder << endl;
	cout << "Day Name   :  " << DaysOfTheWeak[DayOrder];

	system("pause>0");
	return 0;
}
