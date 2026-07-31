#include <iostream>
#include<string>

using namespace std;

string ReplaceWords(string S1,string Word, string Replacement)
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

int main()
{
	string S1 = "Welcome To Jordan, Jordan is a nice country";

	cout << "\n Original String : " << endl;
	cout << S1 << endl;
	
	cout << "\nString After Replace : " << endl;
	cout << ReplaceWords(S1, "Jordan", "USA") << endl;

	system("pause>0");

	return 0;

}
