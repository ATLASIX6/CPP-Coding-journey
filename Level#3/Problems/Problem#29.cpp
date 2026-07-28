#include <iostream>
#include<string>
#include<cctype>

using namespace std;

struct stStringInfo
{
	int stringLength = 0;
	short StringSmallLetters = 0;
	short StringCapitalLetters = 0;
};

string ReadString()
{
	string S1;

	cout << "Please Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

stStringInfo FillStringInfo(string S1, stStringInfo S1Info)
{
	S1Info.stringLength = S1.length();

	for (int i = 0; i < S1.length(); i++)
	{
		isupper(S1[i]) ? S1Info.StringCapitalLetters++ : S1Info.StringSmallLetters++;
	}


	return S1Info;
}

int main()
{
	string S1 = ReadString();
	stStringInfo S1Info;

	S1Info = FillStringInfo(S1, S1Info);

	cout << "\nString Lenght = " << S1Info.stringLength << endl;
	cout << "Capital Letters Count = " << S1Info.StringCapitalLetters << endl;
	cout << "Small Letters Count = " << S1Info.StringSmallLetters << endl;


	system("pause>0");
	return 0;
}

