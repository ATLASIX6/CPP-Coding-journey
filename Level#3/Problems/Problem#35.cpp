#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReadString()
{
	string S1;

	cout << "\nPlease Enter Your String?" << endl;
	getline(cin, S1);

	return S1;
}

void PrintEveryWordInString(string S1)
{
	cout << "\nYour String Words Are : \n";

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i]!=' ')
			cout << S1[i];
		else
			cout << "\n";
	}
}

int main()
{
	string S1 = ReadString();

	PrintEveryWordInString(S1);

	system("pause>0");
	return 0;
}
