#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReadString()
{
	string S1;

	cout << "Please Enter Your String? \n";
	getline(cin, S1);

	return S1;
}

void UperCaseFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true; 

	for (short i = 0; i < S1.length(); i++)
	{

		if (S1[i] != ' ' && isFirstLetter)
		{

			S1[i] = toupper(S1[i]);

		}

		isFirstLetter = (S1[i] == ' ' ? true : false);

	}

	cout << "\nString After Converstion: \n";
	cout << S1 << endl;
}

int main()
{
	UperCaseFirstLetterOfEachWord(ReadString());

	system("pause>0");
	return 0;
}
