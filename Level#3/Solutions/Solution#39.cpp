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

int main()
{
	vector<string> vString = { "Ahmed","Allam","Reidh" };

	cout << "\nVector After Join : " << endl;
	cout << JoinString(vString, "&%&");

	system("pause>0");
	return 0;
}
