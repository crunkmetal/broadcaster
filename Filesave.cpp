#include "Filesave.h"
#include <fstream>
#include <iostream>
#include <bitset>
#include <cstdlib>

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
// function to save data collected in program to a file
void Filesave::saveFile(int userID, string name, string userInput, string encryptedMsg, string broadcastMsg)
{
	cout << "\n\t\tSCRAMBLER\n\n";
	
	ofstream userData("gamedata.txt", ios::app);
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

void Filesave::loadFile()
{
	
	string line;
	ifstream infile("gamedata.txt");
	ofstream outfile("gamedata_edit.txt", ios::trunc);
	int x = 0;
	do
	{
		
		cout << "\n  Choose an option:\n";
		cout << "  1) Load message archive\n";
		cout << "  2) Load updated archive\n";
		cout << "  3) Start new message\n";
		cout << "  4) Exit\n";
		cin >> x;

		switch (x)
		{
		case 1:	// load/display a file to the console
			if (infile.is_open())
			{
				if (outfile.is_open())
				{
					while (getline(infile, line))
					{
						cout << line << "\n";				// parse data from a file
						outfile << "[x]  " << line << "\n";		// change that data and write to a new file
						pause_10m();

					}
					infile.close();		// close file
					outfile.close();	// close file
				}	// end of outfile if statement
				else cout << "Unable to open file or file is corrupt.\n";
			}		// end of infile if statement
			else cout << "Unable to open file or file is corrupt.\n";
			system("pause");
			break;

		case 2:	// open updated message archive (showing file has been parsed and changes made)
			updatedFile();
			break;

		case 3:	// continue with game flow
			break;

		case 4:
			cout << "\n  Program terminated... \n";
			exit(0);

		default:  // switch to handle invalid data
			cout << "\n  That is not an option, please try again";
			break;
		}
	}while (x != 3);
	
}

void Filesave::updatedFile()
{
	string line;
	ifstream showFile("gamedata_edit.txt");

	if (showFile.is_open())
	{
		while (getline(showFile, line))
		{
			cout << line << "\n";				// parse data from a file, send to console
			pause_10m();
		}
		showFile.close();		// close file	
	}		// end of infile if statement
	else
	{
		cout << "Unable to open file or file is corrupt.\n";
	}
	system("pause");
}
