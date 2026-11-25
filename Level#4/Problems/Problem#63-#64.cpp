#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());

	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());


	return S1;
}

string ReadStringDate()
{
	string DateString;

	cout << "\nPlease Enter a Date dd/mm/yyyy? ";
	cin >> DateString;

	return DateString;
}

sDate StringToDate(string stringDate, vector<string> vDate)
{
	sDate Date;

	Date.Day = stoi(vDate.at(0));
	Date.Month = stoi(vDate.at(1));
	Date.Year= stoi(vDate.at(2));

	return Date;
}

string DateToString(sDate Date)
{
	vector<string> vDate;
	string StringDate;
	
	vDate.push_back(to_string(Date.Day));
	vDate.push_back(to_string(Date.Month));
	vDate.push_back(to_string(Date.Year));

	StringDate = JoinString(vDate, "/");

	return StringDate;
}

void PrintDate(sDate Date)
{
	cout << "\nDay   : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear  : " << Date.Year;
}

int main()
{
	string StringDate = ReadStringDate();
	vector<string> vDate = SplitString(StringDate, "/");
	sDate Date = StringToDate(StringDate,vDate);

	PrintDate(Date);

	cout << "\n\nYou Entered : " << DateToString(Date);

	system("pause>0");
	return 0;
}