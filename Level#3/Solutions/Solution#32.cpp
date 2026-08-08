#include <iostream>
#include<string>
#include<cctype>
#include<iomanip>

using namespace std;

char ReadChar()
{
	char Ch1;

	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;

	return Ch1;
}

bool isVowel(char Ch1)
{
	Ch1 = tolower(Ch1);

	return (Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'o') || (Ch1 == 'i') || (Ch1 == 'u');
}

int main()
{
	char Ch1 = ReadChar();

	if (isVowel(Ch1))
		cout << "\nYES: Letter '" << Ch1 << "' is a Vowel" << endl;
	else
		cout << "\nNo: Letter '" << Ch1 << "' is NOT Vowel" << endl;


	system("pause>0");
	return 0;
}
