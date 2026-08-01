#include <iostream>
#include<string>
#include<vector>

using namespace std;

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

sClient FillClientData(vector<string> vClient)
{
	sClient Client;

	Client.AccountNumber = vClient.at(0);
	Client.PinCode = vClient.at(1);
	Client.Name = vClient.at(2);
	Client.Phone = vClient.at(3);
	Client.AccountBalance = stod(vClient.at(4));

	return Client;
}

void PrintclientData(sClient Client)
{
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

int main()
{
	string ClientRecord = "A150#//#1234#//#Ahmed Abdelli#//#0776685877#//#90000.000000";
	sClient Client;

	vector<string> vClient = SplitString(ClientRecord, "#//#");

	cout << "\nLine Record is:\n";
	cout << ClientRecord;

	Client = FillClientData(vClient);

	cout << "\n\n the following is the extracted client record : \n\n";
	PrintclientData(Client);

	system("pause>0");
	return 0;
}
