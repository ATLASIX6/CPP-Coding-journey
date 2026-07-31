#include <iostream>
#include<string>
#include<vector>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

vector <string> SplitString(string S1, string delim)
{
	vector<string> vString;
	short Pos = 0;
	string sWord;

	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, Pos + delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

string ReversString(string S1, vector<string>vString, string Delim)
{
	for (short i = vString.size() - 1; i >= 0; i--)
	{
		S1 = S1 + vString.at(i) + Delim;
	}

	return  S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector<string> vString = SplitString(ReadString(), " ");

	string S1 = "", Delim = " ";

	cout << "\nStirng After Revesing words : " << endl;
	cout << ReversString(S1, vString, Delim);


	system("pause>0");
	return 0;
}

