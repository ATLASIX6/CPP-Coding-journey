#include <iostream>
#include<string>
#include<cctype>
#include<fstream>

using namespace std;

const string ClientFileName = "Clients.txt";

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
	
	// Usage Of std::ws will Extract all White Space Character
	getline(cin >> ws, Client.AccountNumber);

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

void AddDataLineToFile(string FileName, string sDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << sDataLine << endl;

		MyFile.close();
	}

}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientFileName, ConvertRecordToLine(Client));

}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();

		cout << "\nClient Added Successfuly, do You Want to add More Clients?Y/N";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();

	system("pause>0");
}
