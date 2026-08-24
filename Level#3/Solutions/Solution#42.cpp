#include <iostream>
#include<string>

using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace); // find Next
	}

	return S1;
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";

	cout << "\nOriginal String : \n" << S1;
	cout << "\n\n String After Replace : \n";
	cout << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);
	
	system("pause>0");
	return 0;
}
