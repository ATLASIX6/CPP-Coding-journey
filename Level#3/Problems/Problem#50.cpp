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

vector<string> LoadDataFromFileToVector(string FileName, vector <string> vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);//Read Mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}

		MyFile.close();

	}
	return vFileContent;
}

void SaveVectorToFile(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//write Mode

	if (MyFile.is_open())
	{
		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
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

bool FindClientByAccountNumbers(string AccountNumber, sClient& Client)
{
	vector<sClient>vClients = LoadClientsDataFromFile(ClientFileName);

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

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nPlease Enter Account Number ?";
	cin >> AccountNumber;

	return AccountNumber;
}

string IsDelate()
{
	string Delate = "Y";

	cout << "\nAre You Sure You wanna delate this Account ?";
	cin >> Delate;

	return Delate;
}

void DelatClientRecord(sClient& Client)
{
	string ClientLine = ConvertRecordToLine(Client);

	vector<string>vFileCountent = LoadDataFromFileToVector(ClientFileName, vFileCountent);

	for (string &Line : vFileCountent)
	{
		if (Line == ClientLine)
		{
			Line = "";
		}
	}
	SaveVectorToFile(ClientFileName, vFileCountent);
}

int main()
{
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	string DelateOrNo;
	if (FindClientByAccountNumbers(AccountNumber, Client))
	{
		PrintClientCard(Client);
		DelateOrNo = IsDelate();
		if (DelateOrNo=="Y"|| DelateOrNo == "y")
		{
			DelatClientRecord(Client);
			cout << "\nClient Delated Successfully\n";
		}

	}
	else
	{
		cout << "\nClient with the Account number (" << AccountNumber << ") Not Found!\n";

	}


	system("pause>0");
 }
