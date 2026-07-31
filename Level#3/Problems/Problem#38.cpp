#include <iostream>
#include<string>

using namespace std;

string TrimLeft(string S1)
{
	short Pos = 0;
	string Word;
	
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			S1.erase(0, i);
			break;
		}
		
	}

	return S1;


}

string TrimRight(string S1)
{	

	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i]!=' ')
		{
			S1.erase(i, S1.length());
			break;
		}
	}
	
	return S1;

}

string Trim(string S1)
{
	return TrimLeft(TrimRight(S1));
}

int main()
{
	
	string S1 = "       Ahmed Abdelli.         ";
	cout << "String      =" << S1 << endl;
	cout << "Trim Left   = " << TrimLeft(S1) << endl;
	cout << "Trim Right  = " << TrimRight(S1) << endl;
	cout << "Trim        = " << Trim(S1);

	system("pause>0");
	return 0;
}
