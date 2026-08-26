#include <iostream>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
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
	bool MarkForDelete = false;

};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());

	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); // cast string to double

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

vector<sClient>LoadClientsDataFromFile(string FileName)
{

	vector<sClient>vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);//Read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{

			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);

		}

		MyFile.close();
	}

	return vClients;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe Following Are the client Details: ";
	cout << "\nAccoutn Number : " << Client.AccountNumber;
	cout << "\nPin Code       : " << Client.PinCode;
	cout << "\nName           : " << Client.Name;
	cout << "\nPhone          : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumbers(string AccountNumber, vector<sClient>vClients, sClient& Client)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber==AccountNumber)
		{

			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(string FileName, vector<sClient>vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);// OverWrite

	string DataLine;
	if (MyFile.is_open())
	{
		for (sClient& C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				// we only write records that are Not Marked for delete
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumbers(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre You Sure You Want delete This Client? y/n ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientFileName, vClients);

			//Refresh clients
			vClients = LoadClientsDataFromFile(ClientFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number(" << AccountNumber << ") is NOT Found!";
		return false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "Please Enter Account Number ?";
	cin >> AccountNumber;

	return AccountNumber;
}

int main()
{
	vector<sClient>vClient = LoadClientsDataFromFile(ClientFileName);
	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClient);


	system("pause>0");
}
