/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#include "Filesave.h"
#include <fstream>
#include <iostream>
#include <bitset>
#include <cstdlib>

using namespace std;	// using the standard template library
// function asking user to save data for this session
void Filesave::askToSave(int userID, string name, string userInput, string encryptedMsg, string broadcastMsg)
{
	char saveAnswer = NULL;
	cin >> saveAnswer;	// user char input assigned to variable
	system("CLS");	// clear the console
	// if loop to determine whether or not session data is saved
	if (saveAnswer == 'Y' || saveAnswer == 'y')
	{
		saveFile(userID, name, userInput, encryptedMsg, broadcastMsg);  // invoke function to save session

		cout << "\n  Your message has been saved.\n";
	}
	else { cout << "\n Your message was not saved.\n"; }

}
// function to save data collected in program to a file
void Filesave::saveFile(int userID, string name, string userInput, string encryptedMsg, string broadcastMsg)
{
	cout << "\n\t\tSCRAMBLER\n\n";
	
	ofstream userData("gamedata.txt", ios::app);  // create and open an output file stream (file, append new data to bottom of file)
	if (userData.is_open())	// does file exist/is open
	{
		// file stream from right to left, saved to out file
		userData << "\n\n  Username:\t" << name << "\n";
		userData << "  User ID:\t" << userID << "\n";
		userData << "  Message:\t" << userInput << "\n";
		userData << "  Encrypted:\t" << encryptedMsg << "\n";
		userData << "  Binary:\t" << broadcastMsg << "\n";
		userData.close();	// closing the file - important (file may be corrupted if this not done)
	}
	else  // if unable to open file stream, file missing or corrupt
	{
		cout << "Unable to locate file or file is corrupt.";
	}
}
// function to load files based on user input
void Filesave::loadFile()
{
	string line;	// declaring a variable
	ifstream infile("gamedata.txt");	// creating/opening an input filestream
	ofstream outfile("gamedata_edit.txt", ios::trunc);  // creating/opening an output filestream (ios::trunc ->deletes previous info in txt file before writing to file)
	int x = 0;	// declaring a variable for user options
	do
	{
		cout << "\n\t\tSCRAMBLER\n\n";

		cout << "\n  Choose an option:\n";
		cout << "  1) Load message archive\n";
		cout << "  2) Load updated archive\n";
		cout << "  3) Start new message\n";
		cout << "  4) Exit\n";
		cin >> x;	// user input assigned to variable
		// switch case used to determine program flow
		switch (x)
		{
		case 1:	// load/display a file to the console
			if (infile.is_open()) // make sure input filestream is open
			{
				if (outfile.is_open())  // make sure output filestream is open
				{
					while (getline(infile, line))  // while the open file has content, get it...
					{
						cout << line << "\n";				// parse it
						outfile << "[x]  " << line << "\n";		// change that data and write it to a new file
						pause_10m();	// used to visually enhance data displayed on screen

					}
					infile.close();		// close input filestream
					outfile.close();	// close output filestream
				}	// end of outfile if statement
				else cout << "Unable to open file or file is corrupt.\n";  // msg if outfile cannot be opened
			}		// end of infile if statement
			else cout << "Unable to open file or file is corrupt.\n";  // msg to display if infile cannot be opened
			system("pause");
			system("CLS");
			break;	// means to break out of this case

		case 2:	// open updated message archive (showing file has been parsed and changes made)
			updatedFile();  // invoke function to show updated msg archive
			system("CLS");
			break; // means to break out of this case

		case 3:	// continue with game flow
			system("CLS");
			break; // means to break out of this case

		case 4:  // end program
			system("CLS");
			cout << "\n  Program terminated... \n";
			exit(0); // function to end program

		default:  // switch to handle invalid data
			system("CLS");
			cout << "\n  That is not an option, please try again";
			break; // means to break out of this case
		}
	}while (x != 3); // if value is not three, stay in this options loop
	
}
// function to display the file that has been modified
void Filesave::updatedFile()
{
	string line; // declare a variable 
	ifstream showFile("gamedata_edit.txt");  // create/open an input filestream

	if (showFile.is_open())	// verify file is accessible
	{	// while there is content in filestream file...
		while (getline(showFile, line))
		{
			cout << line << "\n";				// parse data from a file, send it to console
			pause_10m();	// syntactic sugar
		}
		showFile.close();		// close file	
	}		// end of infile if statement
	else
	{
		cout << "Unable to open file or file is corrupt.\n";
	}
	system("pause");
}
