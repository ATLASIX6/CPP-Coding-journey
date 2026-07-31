#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string RemovePunctuation(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (ispunct(S1[i]))
		{
			S1.erase(i, 1);
		}
	}
	return S1;
}

int main()
{
	string S1 = "Welcom Jordan, Jor&d%a&n i&s( n)ice Country; it's amazing";
	cout << "\nOrignal String : \n" << S1;
	
	cout << "\n\nPunctuations Removed : " << endl;;
	cout << RemovePunctuation(S1);

	system("pause>0");
	return 0;
}
