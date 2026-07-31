#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReplaceWordsWithMacthCase(string S1, string Word, string Replacement)
{
	int Start;
	int End;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1.find(Word) != S1.npos)
		{
			Start = S1.find(Word);
			End = Word.length();
			S1.erase(Start, End);
			S1.insert(Start, Replacement);
		}
	}



	return S1;
}

string ReplaceWordsWithNoMacthCase(string S1, string Word, string Replacement)
{
	int Start;
	int End;

	string LowerWord = Word;
	string UperWord = Word;


	for (short i = 0; i < Word.length(); i++)
	{
		LowerWord[i] = tolower(Word[i]);
		UperWord[i] = toupper(Word[i]);

		if (S1.find(LowerWord))
		{
			for (short i = 0; i < S1.length(); i++)
			{
				if (S1.find(LowerWord) != S1.npos)
				{
					Start = S1.find(LowerWord);
					End = LowerWord.length();
					S1.erase(Start, End);
					S1.insert(Start, Replacement);
				}
			}
		}
		if (S1.find(UperWord))
		{
			for (short i = 0; i < S1.length(); i++)
			{
				if (S1.find(UperWord) != S1.npos)
				{
					Start = S1.find(UperWord);
					End = UperWord.length();
					S1.erase(Start, End);
					S1.insert(Start, Replacement);
				}
			}
		}

	}

	

	return S1;
}


int main()
{
	string S1 = "Welcome To Jordan, Jordan is a nice country";

	cout << "\n Original String : " << endl;
	cout << S1 << endl;

	cout << "\nReplace with Macth case : " << endl;
	cout << ReplaceWordsWithMacthCase(S1, "Jordan", "USA") << endl;


	cout << "\nReplace with No Macth case : " << endl;
	cout << ReplaceWordsWithNoMacthCase(S1, "Jordan", "USA") << endl;

	system("pause>0");

	return 0;

}
