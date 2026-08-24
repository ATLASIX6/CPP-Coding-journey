#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string RemovePunctuationFromString(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;

}

int main()
{
	string S1 = "Welcom Jordan, Jor%d%a&n i&s( n)ice Country; it's amazing";
	cout << "\nOrignal String : \n" << S1;

	cout << "\n\nPunctuations Removed : \n" << RemovePunctuationFromString(S1);
	
	system("pause>0");
	return 0;
}
