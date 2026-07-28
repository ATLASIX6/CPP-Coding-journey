#include <iostream>
#include<string>

using namespace std;


int main()
{
	string phraze = "";
	cout << "Please Enter Your string : \n";
	getline(cin, phraze);
	
	cout << phraze.at(0) << endl;

	for (int i = 0; i < phraze.length(); i++)
	{
		if (phraze[i] == ' ')
		{
			cout << phraze.at(i + 1) << endl;
		}
	}

	system("pause>0");
	return 0;
}
