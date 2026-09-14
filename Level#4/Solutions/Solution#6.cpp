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

	cout << "Please Enter Year To check? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	int Month = 0;

	cout << "Please Enter A Mont To Check? ";
	cin >> Month;

	return Month;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber Of Days     in Month [" << Month << "] is "
		<< NumberDaysInMonth(Month, Year);

	system("pause>0");
	return 0;
}
