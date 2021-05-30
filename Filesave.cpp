#include "Filesave.h"
#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

void Filesave::askToSave(int userID, string name, string userInput, string encryptedMsg, string broadcastMsg)
{
	char saveAnswer = NULL;
	cin >> saveAnswer;
	system("CLS");
	
	if (saveAnswer == 'Y' || saveAnswer == 'y')
	{
		saveFile(userID, name, userInput, encryptedMsg, broadcastMsg);

		cout << "\n  Your message has been saved.\n";
	}
	else { cout << "\n Your message was not saved.\n"; }

}

void Filesave::saveFile(int userID, string name, string userInput, string encryptedMsg, string broadcastMsg)
{
	cout << "\n\t\tSCRAMBLER\n\n";
	
	ofstream userData("gamedata.txt", ios::trunc);
	if (userData.is_open())
	{
		userData << "\n\n  Username:\t" << name << "\n";
		userData << "  User ID:\t" << userID << "\n";
		userData << "  Message:\t" << userInput << "\n";
		userData << "  Encrypted:\t" << encryptedMsg << "\n";
		userData << "  Binary:\t" << broadcastMsg << "\n";
		userData.close();
	}
	else
	{
		cout << "Unable to locate file or file is corrupt.";
	}
	
}
