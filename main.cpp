/*
 TODO: hello
	 - intro
	 - ask user to input msg
	 - ask to encrypt msg
	 - display encrypted msg
	 - convert msg to binary
	 - display binary
	 - send binary (to file)
	 - msg to user stating msg sent
	 - pause, add msg to show msg received
	 - output an encrypted binary msg
	 - ask user to convert binary to text
	 - display msg asking user to decrypt msg
	 - output reply

	 https://youtu.be/V-BFlMrBtqQ

	 // to delete a file
		#include <stdio.h>
	// first make sure the file exists
	int main()
	{
	    if(remove("nameoffile.txt") !=0)
	      perror("This file does not exist");	<-- this text is added to C++ default text
	    else
	    puts("File has been deleted.");
	  return 0;
	  }
  */


#pragma once
#include <iostream>
#include "Pausing.h"
#include "ReadMe.h"
#include "User.h"
#include <bitset>
#include <conio.h>
#include <sstream>
#include "Encryption.h"
#include "Filesave.h"

using namespace std;

// #include <Windows.h>
// 	Sleep(1000);


/*
 * TODO: fix
 * fix objects
 */
// instantiating objects
Pausing pauseNow;
ReadMe intro;
User player;
Encryption crypt;
Filesave savedata;

bool quitApp();

int main()
{
	srand(static_cast<unsigned>(time(nullptr))); // seed random number generator
	
	intro.info();	// about screen
	system("CLS");
	// asking for user inputs
	player.setUserName();
	player.setUserId();
	player.setUserInput();
	pauseNow.pause_10m();
	system("CLS");
	
	// game loop
	do
	{
		// set restart switch to no replay
		crypt.restart = false;
		// get user info
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
		cout << "  " << name << ", would you like to encrypt your message?\n";
		// invoke method from Encryption object member to determine game flow
		// while populating value of msgEncrypted variable
		msgEncrypted = crypt.askToEncrypt(userInput);
		pauseNow.pause_1s();
		system("CLS");

		cout << "\n\t\tSCRAMBLER\n\n";
		cout << "  " << name << ", would you like to broadcast your message?\n\n";
		broadcastMsg = crypt.broadcastMsg(crypt.isEncrypted, userInput, msgEncrypted, broadcastMsg);	// invoke call to broadcast msg
		pauseNow.pause_1s();
		system("CLS");

		cout << "\n\t\tSCRAMBLER\n\n";
		cout << "  " << name << ", would you like to save your message?\n\n";
		savedata.askToSave(userID, name, userInput, msgEncrypted, broadcastMsg);

		quitApp();

	} while (crypt.restart);

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
	if ((ch = _getch()) != 27)
	{
		crypt.restart = true;
		system("CLS");

		return crypt.restart;
	}
	else
	{
		system("CLS");
		
		return crypt.restart;
	}
}