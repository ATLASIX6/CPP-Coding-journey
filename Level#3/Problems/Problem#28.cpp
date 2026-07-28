#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReadString()
{
	string S1;

	cout << "Please Enter You String?\n";
	getline(cin, S1);

	return S1;
}

string InvertStringCase(string S1)
{

	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = isupper(S1[i]) ? tolower(S1[i]) : toupper(S1[i]);
	}

	return S1;
}

int main()
{
	string S1 = ReadString();

	S1 = InvertStringCase(S1);

	cout << "\nString after inverting All Letters case : \n";
	cout << S1 << endl;

	system("pause>0");
	return 0;
}
