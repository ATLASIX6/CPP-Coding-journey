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

void PrintEachWordInString(string S1)
{
	string delim = " "; // delimiter

	cout << "\nYour String Words are : \n\n";
	short Pos = 0; // Position
	string sWord; // define a string variable

	// use find() function to get the Position of the delimiters
	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos); // store the word
		if (sWord != "")
		{
			cout << sWord << endl;
		}

		S1.erase(0, Pos + delim.length()); // earse() until Position and Move to the Next Word
	}
	if (S1 != "")
	{
		cout << S1 << endl; // it Print Last Word of the string
	}
}

int main()
{

	PrintEachWordInString(ReadString());

	system("pause>0");
	return 0;
}
