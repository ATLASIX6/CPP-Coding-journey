#include <iostream>
#include<cctype>
#include<string>
#include<iomanip>

using namespace std;

string ReadString()
{
	string S1;

	cout << "\nPlease Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

bool isVowel(char Ch1)
{
	Ch1 = tolower(Ch1);

	return (Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'o') || (Ch1 == 'i') || (Ch1 == 'u');
}

void PrintVowels(string S1)
{

	cout << "\nVowels in String are :  ";

	for (short i = 0; i < S1.length(); i++)
	{
		if (isVowel(S1[i]))
			cout << S1[i] << "      ";
	}

}

int main()
{
	string S1 = ReadString();

	PrintVowels(S1);

	system("pause>0");
	return 0;
}
