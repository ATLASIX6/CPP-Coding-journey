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

bool CompaireDates(sDate Date1, sDate Date2)
{
	if (Date1.Year < Date2.Year)
	{
		return true;
	}
	else
	{
		if (Date1.Year == Date2.Year)
		{
			if (Date1.Month < Date2.Month)
			{
				return true;
			}
			else
			{
				if (Date1.Month == Date2.Month)
				{
					if (Date1.Day < Date2.Day)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				return false;
			}
		}
		return false;
	}
}

int main()
{

	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	if (CompaireDates(Date1, Date2))
		cout << "\nYes,Date 1 is Less then Date 2";
	else
		cout << "\No,Date 1 is NOT Less then Date 2";


    system("pause>0");
    return 0;
}
