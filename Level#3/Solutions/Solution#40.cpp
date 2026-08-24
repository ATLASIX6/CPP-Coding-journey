#include <iostream>
#include<string>
#include<vector>

using namespace std;

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

string JoinString(string ArrString[], short Length, string Delim)
{
	string S1 = "";

	for (short i = 0; i < Length; i++)
	{
		S1 = S1 + ArrString[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());


	return S1;
}

int main()
{
	vector<string> vString = { "Ahmed","Allam","Reidh" };

	string ArrString[] = { "Ahmed","Allam","Reidh" };

	cout << "\nVector After Join : " << endl;
	cout << JoinString(vString, "&%&");

	cout << "\n\nArray After Join : " << endl;
	cout << JoinString(ArrString, 3, "&%&");


	system("pause>0");
	return 0;
}
