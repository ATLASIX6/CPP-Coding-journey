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

short CountLettersInString(string S1, char C1)
{
	short Count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == C1)
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

	cout << "Letter '" << C1 << "' Count = " << CountLettersInString(S1, C1);

	system("pause>0");
	return 0;
}
