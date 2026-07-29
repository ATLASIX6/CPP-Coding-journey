#include <iostream>
#include<string>
#include<cctype>
#include<iomanip>

using namespace std;

char ReadChar()
{
	char Ch1 ;
	
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;

	return Ch1;
}

bool isVowel(char Letter)
{
	switch (tolower(Letter))
	{
	case 'a':
		return true;
		break;

	case 'e':
		return true;
		break;

	case 'i':
		return true;
		break;

	case 'o':
		return true;
		break;

	case 'u':
		return true;
		break;
	default:
		return false;
	}
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
