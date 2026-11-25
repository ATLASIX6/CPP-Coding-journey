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

string ReadStringDate(string Massege)
{
	string DateString;

	cout << Massege;
	getline(cin >> ws, DateString);

	return DateString;
}

sDate StringToDate(string StringDate)
{
	sDate Date;
	vector<string> vDate;

	vDate = SplitString(StringDate, "/");
	
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string DateToString(sDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
	string StringDate = ReadStringDate("\nPlease Enter a Date dd/mm/yyyy? ");
	sDate Date = StringToDate(StringDate);

	cout << "\nDay   : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear  : " << Date.Year;

	cout << "\n\nYou Entered : " << DateToString(Date);

	system("pause>0");
	return 0;
}