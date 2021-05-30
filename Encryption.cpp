/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#pragma
#include "Encryption.h"
#include <bitset>
#include <iostream>
#include <vector>
#include <sstream>
#include "User.h"
#include "Pausing.h"
// using the standard template library
using namespace std;
// member function asking user to encrypt their message
string Encryption::askToEncrypt(string userInput)
{
	char encryptAnswer = NULL;
	cin >> encryptAnswer;	// assign value of user input to a variable
	// if user input is yes...
	if (encryptAnswer == 'Y' || encryptAnswer == 'y')
	{
		cout << "  Your message is encrypting...\n";
		pause_10m();
		pause_10m();
		encrypt(userInput);		// invoke function to encrypt user msg
		// assigning value to local variable for later use
		string msgEncrypted = getEncryptedMsg();
		isEncrypted = true;	// set switch for the encrypted value

		return msgEncrypted;
	}
	else
	{
		cout << "\n  Your message will not be encrypted.";
		isEncrypted = false;	// set switch for the encrypted value

		return userInput;
	}
}
// member function to actually encrypt string
string Encryption::encrypt(string userInput)
{	// for each character in user input message, encrypt
	for (int i = 0; i < userInput.length(); i++)
	{
		//the key for encryption is 3 that is added to ASCII value
		userInput[i] = userInput[i] + 2;
	}
	string encryptedMsg = userInput;	// assign the value of encrypted chars to a string variable
	setEncryptedMsg(encryptedMsg);	// invoke function to assign this new value to a private property
	system("CLS");
	cout << "\n\t\tSCRAMBLER\n\n";
	cout << "  Your message has been encrypted.\n\n";
	cout << "  Encrypted string: " << getEncryptedMsg() << "\n\n\n";
	cout << "  ";
	system("pause");
	
	return encryptedMsg;
}
// public member function to transmit user message
string Encryption::broadcastMsg(bool isEncrypted, string userInput, string encryptedMsg, string broadcastMsg)
{
	char bcMsgAnswer = NULL;
	cin >> bcMsgAnswer;	// user input assigned to local variable
	if ((bcMsgAnswer == 'Y' || bcMsgAnswer == 'y') && isEncrypted == false)	// do this if Yes and userInput remains unencrypted
	{
		system("CLS");
		cout << "\n\n  Message:\t" << userInput << "\n";
		broadcastMsg = convertToBinary(userInput, encryptedMsg);	// invoke transmission conversion function
		setBroadcastMsg(broadcastMsg);	// invoke member function to set value of conversion to a private property
		pause_10m();
		cout << "\n\n  Message has been sent successfully!\n";
		cout << "  ";
		system("pause");
		
		return broadcastMsg;
	}
	else if ((bcMsgAnswer == 'Y' || bcMsgAnswer == 'y') && isEncrypted == true)	// do this if Yes and userInput is encrypted
	{
		cout << "\n\n  Message:\t" << encryptedMsg << "\n";
		broadcastMsg = convertToBinary(userInput, encryptedMsg);	// invoke transmission conversion function
		pause_10m();
		pause_10m();
		cout << "\n\n  Message has been sent successfully!\n";
		cout << "  ";
		system("pause");
		
		return broadcastMsg;
	}
	else
	{	// do this if user choice is not to encrypt message
		cout << "\n  Message will be archived for sending at a later time.";

		return broadcastMsg;

	}
}
// member function to convert user msg (encrypted/unencrypted) to a binary format for transmission
string Encryption::convertToBinary(string userInput, string encryptedMsg)
{
	stringstream bs;	// initializing a stringstream
	vector<string> bitstring{};	// initializing a string vector
	bitset<8> mybits;	// represents a fixed-size sequence <set of 8>
	// if statement determines game flow based on status of user encryption
	if (encryptedMsg.empty())	// if the string value of parameter is null...
	{	// convert the original user input
		for (size_t i = 0; i < userInput.size(); ++i)
		{
			mybits = bitset<8>(userInput.c_str()[i]);
			string mystring = mybits.to_string<char, string::traits_type, string::allocator_type>();
			bitstring.push_back(mystring);
		}
	}
	else  // convert the encrypted message
	{
		for (size_t i = 0; i < encryptedMsg.size(); ++i)
		{
			mybits = bitset<8>(encryptedMsg.c_str()[i]);
			string mystring = mybits.to_string<char, string::traits_type, string::allocator_type>();
			bitstring.push_back(mystring);
		}
	}

	// print results of broadcasted msg to display
	cout << "\n  Broadcasting encrypted message...\n";
	for (size_t i = 0; i < bitstring.size(); ++i)
	{
		cout << bitstring[i];
		pause_10m();	// syntactic sugar
		pause_10m();
	}
	cout << "\n";
	
	// convert vector to string
	stringstream ss;	// initialize a stringstream
	for (size_t i = 0; i < bitstring.size(); ++i)
	{
		if (i != 0)	// while bitstring value is not equal to 0
			ss << " ";	// insert a space
		ss << bitstring[i];	// insert the value into the stringstream
	}
	string broadcastMsg = ss.str();	// the value of the string assigned to a local variable
	
	setBroadcastMsg(broadcastMsg);	// set the value of the local variable to a private property
	
	return broadcastMsg;
}
// this functionality not yet incorporated
void Encryption::decrypt(string encryptedMsg)
{
	string msgToDecrypt = encryptedMsg;
	cout << "\n  Message to be decrypted:\t" << msgToDecrypt << "\n";

	for (int i = 0; i < msgToDecrypt.length(); i++)
	{
		msgToDecrypt[i] = msgToDecrypt[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
	}
	string decryptedMsg = msgToDecrypt;

	cout << "\n  Your message has been decrypted.\n";
	cout << "  Decrypted string: " << decryptedMsg << "\n\n";
}

