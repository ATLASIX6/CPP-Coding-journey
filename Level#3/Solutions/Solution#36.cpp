#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReadString()
{
	string S1;

	cout << "\nPlease Enter Your String ?\n";
	getline(cin, S1);

	return S1;
}

short CountWords(string S1)
{
	short Counter = 0;

	string delim = " "; // delimiter

	short Pos = 0; // Position
	string sWord; // define a string variable

	// use find() function to get the Position of the delimiters
	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos); // store the word
		if (sWord != "")
		{
			Counter++;
		}

		S1.erase(0, Pos + delim.length()); // earse() until Position and Move to the Next Word
	}
	if (S1 != "")
	{
		Counter++; // it Print Last Word of the string
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nThe Number Of words in your String : ";
	cout << CountWords(S1) << endl;

	system("pause>0");
	return 0;
}
