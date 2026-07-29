#include <iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

string ReadString()
{
	string S1;

	cout << "\nPlease Enter Your String ?\n";
	getline(cin, S1);

	return S1;
}

vector <string> Split(string S1, string delim)
{
	vector<string> vTokens;
	short Pos = 0;
	string sWord; 

	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos); 
		if (sWord != "")
		{
			vTokens.push_back(sWord);
		}

		S1.erase(0, Pos + delim.length()); 
	}
	if (S1 != "")
	{
		vTokens.push_back(sWord);
	}
	return vTokens;
}

int main()
{

	string Delim = " ";
	string S1 = ReadString();
	vector <string> vWords = Split(S1, Delim);

	cout << "tokens = " << vWords.size() << endl;
	for (string &Word : vWords)
	{
		cout << Word << endl;
	}

	system("pause>0");
	return 0;
}
