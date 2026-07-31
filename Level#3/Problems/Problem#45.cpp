#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct ClientData
{
	string AccountNumber = "";
	int PinCode = 0;
	string Name = "";
	int PhoneNumber = 0;
	int AccountBalance = 0;
};

string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());


	return S1;
}

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

ClientData FillClientData(ClientData Client)
{
	cout << "\nPlease Enter Client Data : \n\n";
	cout << "Enter Accout Number? ";
	cin >> Client.AccountNumber;
	cout << "Enter PinCode? ";
	cin >> Client.PinCode;
	cout << "Enter Name? ";
	cin >> Client.Name;
	cout << "Enter Phone? ";
	cin >> Client.PhoneNumber;
	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string FillClientDataInString(ClientData Client)
{
	string S1 = "";
	S1 = Client.AccountNumber + " " + to_string(Client.PinCode) + " " + Client.Name + " " + to_string(Client.PhoneNumber) + " " + (to_string(Client.AccountBalance) + ".000000");

	return S1;
}

void ClientRecord(string sClinetR)
{
	vector<string>vClientR = SplitString(sClinetR, " ");
	sClinetR = JoinString(vClientR, "#//#");

	cout << "\n\nClient Record For Saving is : " << endl;
	cout << sClinetR;
}
int main()
{
	ClientData Client;
	Client = FillClientData(Client);
	
	ClientRecord(FillClientDataInString(Client));


	system("pause>0");
	return 0;
}
