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

void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);//Read More

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}

		MyFile.close();
	}
}

void TabelHeader(int NumberOfClients)
{
	cout << "\n                          Clien List (" << NumberOfClients << ") Client(s)";

	cout << "\n _______________________________________________________________________________________\n\n";
	cout << " | " << left<<setw(17) << "Account Numbrt  " << " | " << setw(10) << "Pin Code" << " | " << setw(25) << "Client Name" << " | " << setw(14) << "Phone  " << " | " << setw(14) << "Balnce   ";
	cout << "\n _______________________________________________________________________________________\n\n";
}

void PrintTableOfClients()
{
	sClient Client;
	vector<string> vClientData;
	LoadDataFromFileToVector(ClientFileName, vClientData);

	TabelHeader(vClientData.size());
	for (string& Line : vClientData)
	{
		Client = ConvertLineToRecord(Line);
		cout << " | " <<left<< setw(17) << Client.AccountNumber << " | " << setw(10) << Client.PinCode << " | " << setw(25) << Client.Name << " | " << setw(14) << Client.Phone << " | " << setw(10) << Client.AccountBalance << endl;

	}
	
}

int main()
{

	PrintTableOfClients();
	system("pause>0");
}
