/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#include <iostream>
#include "Pausing.h"
#include "ReadMe.h"
#include "User.h"
#include <bitset>
#include <conio.h>
#include <sstream>
#include "Encryption.h"
#include "Filesave.h"
// using standard template library
using namespace std;

// instantiating objects
Pausing pauseNow;
ReadMe intro;
User player;
Encryption crypt;
Filesave savedata;
		
bool quitApp();	// function prototype
// one and only main function 
int main()
{
	srand(static_cast<unsigned>(time(nullptr))); // seed random number generator
	intro.info();	// invoke function to display program info
	// game loop using a do/while loop
	do
	{
		savedata.loadFile();	// invoke function for user options
		system("CLS");	// after leaving previous function, clear console of content
		
		cout << "\n\t\tSCRAMBLER\n\n";
		player.setUserName();	// invoke function to get user name
		player.setUserId();	// invoke function to create a user ID
		player.setUserInput();	// invoke function to get a user message
		pauseNow.pause_10m();	// invoke function to pause
		system("CLS");	// after leaving previous function, clear console of content
	
	
		
		crypt.restart = false;	// set restart switch to false (no replay)
		// get user info using member functions instead of variables
		cout << "\n\t\tSCRAMBLER\n\n";
		cout << "  User ID:\t" << player.getUserId() << "\n";
		cout << "  User Name:\t" << player.getUserName() << "\n";
		cout << "  Message:\t" << player.getUserInput() << "\n\n";
		pauseNow.pause_1s();
		pauseNow.pause_1s();

		// setting values from private members to local variables 
		string name = player.getUserName();
		string userInput = player.getUserInput();
		int userID = player.getUserId();
		string msgEncrypted;
		string broadcastMsg = player.getBroadcastMsg();
		system("CLS");

		cout << "\n\t\tSCRAMBLER\n\n";
		cout << "  " << name << ", would you like to encrypt your message? ( Y or N )\n";
		// invoke method from Encryption object member to determine game flow
		// while populating value of msgEncrypted variable
		msgEncrypted = crypt.askToEncrypt(userInput);
		pauseNow.pause_1s();
		system("CLS");

		cout << "\n\t\tSCRAMBLER\n\n";
		cout << "  " << name << ", would you like to broadcast your message? ( Y or N )\n";
		// return value of invoked function assigned to local variable
		broadcastMsg = crypt.broadcastMsg(crypt.isEncrypted, userInput, msgEncrypted, broadcastMsg);
		pauseNow.pause_1s();
		system("CLS");

		cout << "\n\t\tSCRAMBLER\n\n";
		cout << "  " << name << ", would you like to save your message? ( Y or N )\n";
		savedata.askToSave(userID, name, userInput, msgEncrypted, broadcastMsg);	// invoke function for save functionality

		quitApp();	// invoke function to continue/end game loop

	} while (crypt.restart);	// game loop determined by boolean value of function property

	return 0;
}	// end of main



// function to continue/end play
bool quitApp()
{
	cout << "\n\n\tPress any key to continue...";
	cout << "\n\tPress 'ESC' to quit.\n";

	char ch = 0;
	ch = _getch(); // assigning user input to variable 'ch'
	// if user does not press ESC key, program continues
	if ((ch = _getch()) != 27)	// '27' is the 'ESC' key 
	{
		crypt.restart = true;	// any user input that is NOT 'ESC' sets switch to a replay position
		system("CLS");

		return crypt.restart;	// return boolean value 
	}
	else
	{
		cout << "\n  Program terminated...";
		exit(0);	// exit the program
		
	}
}