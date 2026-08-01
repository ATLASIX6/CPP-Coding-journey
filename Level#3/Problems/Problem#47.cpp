#include <iostream>
#include<string>
#include<fstream>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

};

sClient ReadNewClient()
{
	sClient Client;

	cout << "\nEnter Account Number? ";
	getline(cin, Client.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{
	sClient Client;
	fstream MyFile;
	char AddMoreClient = 'Y';
	string clientRecord = "";

	MyFile.open("MyFile.txt", ios::out | ios::app);
	while (AddMoreClient == 'Y'|| AddMoreClient == 'y')
	{
		if (MyFile.is_open())
		{
			cout << "\nAdding New Client : " << endl;
			clientRecord.clear();

			Client = ReadNewClient();
			
			clientRecord = ConvertRecordToLine(Client);

			MyFile << clientRecord << endl;
			cout << "\nClient Added Successfully do you want to add More clients?(Y/N)" << endl;
			cin >> AddMoreClient;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		
	}
	
	MyFile.close();


	system("pause>0");
	return 0;
}
