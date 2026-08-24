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

string ReversWordsInString(string S1)
{
	vector<string>vSting;
	string S2 = "";

	vSting = SplitString(S1, " ");


	// delclare iterator
	vector<string>::iterator iter = vSting.end();
	while (iter != vSting.begin())
	{
		--iter;
		S2 += *iter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1);// Remove last Space

	return S2;
}

int main()
{
	string S1 = ReadString();

	cout << "\nString After reversing Words : " << endl;
	cout << ReversWordsInString(S1);
	system("pause>0");
	return 0;
}
