#include <iostream>
#include<string>
#include<cctype>

using namespace std;

char ReadCahrachter()
{
	char C1 = ' ';

	cout << "Please Enter Your Charactre? \n";
	cin >> C1;

	return C1;
}

void InvertNumber(char &C1)
{
	if (isupper(C1) == 0)
		C1 = toupper(C1);
	else
		C1 = tolower(C1);
}


int main()
{
	char C1 = ReadCahrachter();

	InvertNumber(C1);

	cout << "\nChar After inverting case : \n";
	cout << C1 << endl;

	system("pause>0");
}
