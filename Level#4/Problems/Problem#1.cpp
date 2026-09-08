#include <iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>

using namespace std;

int ReadNumber()
{
	int Number = 0;

	cout << "Enter a Number? ";
	cin >> Number;

	return Number;
}

string TwoDigitUner20(int Number)
{
	string tWoDigitArrayUnder20[9] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	
	switch (Number)
	{
	case 11:
	{
		return"Eleven";
	}
	case 12:
	{
		return"Twelve";
	}
	case 13:
	{
		return"Thirteen";
	}
	case 14:
	{
		return"Fourteen";
	}
	case 15:
	{
		return"Fifteen";
	}
	case 16:
	{
		return"Sixteen";
	}
	case 17:
	{
		return"Seventeen";
	}
	case 18:
	{
		return"Eighteen";
	}
	case 19:
	{
		return"Nineteen";
	}
	}
}

string TwoDigit(int Number)
{
	string TwoDigitArray[9] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	switch (Number)
	{
	case 10:
	{
		return"ten";
	}
	case 20:
	{
		return"twenty";
	}
	case 30:
	{
		return"thirty";
	}
	case 40:
	{
		return"forty";
	}
	case 50:
	{
		return"fifty";
	}
	case 60:
	{
		return"sixty";
	}
	case 70:
	{
		return"seventy";
	}
	case 80:
	{
		return"eighty";
	}
	case 90:
	{
		return"ninety";
	}
	}
}

string Digit(int Number)
{
	string DigitArray[9] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

	switch (Number)
	{
	case 1:
	{
		return"One";
	}
	case 2:
	{
		return"Two";
	}
	case 3:
	{
		return"Three";
	}
	case 4:
	{
		return"Four";
	}
	case 5:
	{
		return"Five";
	}
	case 6:
	{
		return"Six";
	}
	case 7:
	{
		return"Seven";
	}
	case 8:
	{
		return"Eight";
	}
	case 9:
	{
		return"Nine";
	}
	}
}

string Letters(int Number, string word)
{
	
	if (Number > 0 && Number < 10)
	{
		word += Digit(Number);
	}
	if (Number > 10 && Number < 20)
	{
		word += TwoDigitUner20(Number);
	}
	if (Number >= 20 && Number <= 90)
	{
		word += TwoDigit(Number);
	}
	return word;
}

string NumberToLetters(int Number, string word, int i)
{
	string stNumber = to_string(Number);
	int PrinTNumber = 0;

	while (i <= stNumber.length());
	{
		int Div = pow(10, i);
		i++;
		PrinTNumber = (Number % Div);
		return Letters(PrinTNumber, word) + NumberToLetters(PrinTNumber, word, i);
	}
}
int main()
{

	int Number = ReadNumber();
	string word = "";
	int i = 1;
	cout << NumberToLetters(Number, word, i);
	system("pause>0");
	return 0;
}
