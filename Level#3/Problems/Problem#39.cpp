#include <iostream>
#include<string>
#include<vector>

using namespace std;

string JoinString(vector<string> vString, string S1, string Delim)
{
	
	for (short i = 0; i < vString.size(); i++)
	{
		S1 = S1 + vString.at(i) + Delim;
	}

	return S1;
}

int main()
{
	vector<string> vString = { "Ahmed","Allam","Reidh" };
	string S1, Delimi = "@##";

	cout << "\nVector After Join : " << endl;
	cout << JoinString(vString, S1, Delimi);

	system("pause>0");
	return 0;
}
