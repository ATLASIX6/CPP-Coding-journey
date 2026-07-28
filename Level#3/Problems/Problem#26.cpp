#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReadString()
{
	string S1;

	cout << "Please Enter Your String? " << endl;
	getline(cin, S1);

	return S1;
}

void ToUpperAllString(string &S1)
{
	
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
}

void ToLowerAllString(string &S1)
{

	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
}

int main()
{
	string S1 = ReadString();

	ToUpperAllString(S1);
	cout << "\nString After Upper :\n" << S1 << endl;

	ToLowerAllString(S1);
	cout << "\nString After Lower :\n" << S1 << endl;

	system("pause>0");
	return 0;
}

