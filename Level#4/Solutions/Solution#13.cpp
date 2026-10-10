#include <iostream>

using namespace std;

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
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

bool IdDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{

	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	if (IdDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less then Date2";
	else
		cout << "\No, Date1 is NOT Less then Date2";


	system("pause>0");
	return 0;
}
