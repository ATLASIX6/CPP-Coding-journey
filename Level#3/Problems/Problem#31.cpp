#include <iostream>
#include<string>
#include<cctype>
#include<iomanip>

using namespace std;

string ReadString()
{
	string S1;

	cout << "Please Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

char ReadChar()
{
	char C1;

	cout << "\nPlease Enter a Character?\n";
	cin >> C1;

	return C1;
}

short CountLetter(string S1, char Letter)
{
	short Count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
		{
			Count++;
		}
	}
	return Count;
}

short CountLetterMatchCase(string S1, char Letter,char UpperLetter)
{
	short Count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter || S1[i] == UpperLetter)
		{
			Count++;
		}
	}
	return Count;
}


int main()
{
	string S1 = ReadString();

	char C1 = ReadChar();
	char C2 = toupper(C1);

	cout << "\nLetter '" << C1 << "' Count = " << CountLetter(S1, C1);
	cout << "\nLetter '" << C1 << "' or '" << C2 << "' Count = " << CountLetterMatchCase(S1, C1, C2);

	system("pause>0");
	return 0;
}
