#pragma once
#include "Encryption.h"
#include <bitset>
#include <iostream>
#include <vector>
#include <sstream>
#include "User.h"
#include "Pausing.h"

using namespace std;

string Encryption::askToEncrypt(string userInput)
{
	char encryptAnswer = NULL;
	cin >> encryptAnswer;

	if (encryptAnswer == 'Y' || encryptAnswer == 'y')
	{
		cout << "  Your message is encrypting...\n";
		pause_10m();
		pause_10m();
		encrypt(userInput);		// invoke function to encrypt user msg
		// assigning value to temp variable for later use
		string msgEncrypted = getEncryptedMsg();
		isEncrypted = true;

		return msgEncrypted;
	}
	else
	{
		cout << "\n  Your message will not be encrypted.";
		isEncrypted = false;

		return userInput;
	}
}

string Encryption::encrypt(string userInput)
{
	for (int i = 0; i < userInput.length(); i++)
	{
		//the key for encryption is 3 that is added to ASCII value
		userInput[i] = userInput[i] + 2;
	}
	string encryptedMsg = userInput;
	setEncryptedMsg(encryptedMsg);
	system("CLS");
	cout << "\n\t\tSCRAMBLER\n\n";
	cout << "  Your message has been encrypted.\n\n";
	cout << "  Encrypted string: " << getEncryptedMsg() << "\n\n\n";
	cout << "  ";
	system("pause");
	
	return encryptedMsg;
}

string Encryption::broadcastMsg(bool isEncrypted, string userInput, string encryptedMsg, string broadcastMsg)
{
	char bcMsgAnswer = NULL;
	cin >> bcMsgAnswer;
	if ((bcMsgAnswer == 'Y' || bcMsgAnswer == 'y') && isEncrypted == false)
	{
		system("CLS");
		cout << "\n\n  Message:\t" << userInput << "\n";
		broadcastMsg = convertToBinary(userInput, encryptedMsg);
		setBroadcastMsg(broadcastMsg);
		pause_10m();
		cout << "\n\n  Message has been sent successfully!\n";
		cout << "  ";
		system("pause");
		
		return broadcastMsg;
	}
	else if ((bcMsgAnswer == 'Y' || bcMsgAnswer == 'y') && isEncrypted == true)
	{
		cout << "\n\n  Message:\t" << encryptedMsg << "\n";
		broadcastMsg = convertToBinary(userInput, encryptedMsg);
		pause_10m();
		pause_10m();
		cout << "\n\n  Message has been sent successfully!\n";
		cout << "  ";
		system("pause");
		
		return broadcastMsg;
	}
	else
	{
		cout << "\n  Message will be archived for sending at a later time.";

		return broadcastMsg;

	}

	
}

string Encryption::convertToBinary(string userInput, string encryptedMsg)
{
	stringstream bs;
	vector<string> bitstring{};
	bitset<8> mybits;
	// if statement determines game flow based on status of user encryption
	if (encryptedMsg.empty())
	{
		for (size_t i = 0; i < userInput.size(); ++i)
		{
			mybits = bitset<8>(userInput.c_str()[i]);
			string mystring = mybits.to_string<char, string::traits_type, string::allocator_type>();
			bitstring.push_back(mystring);
		}
	}
	else
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
		pause_10m();
		pause_10m();
	}
	cout << "\n";
	
	// convert vector to string
	stringstream ss;
	for (size_t i = 0; i < bitstring.size(); ++i)
	{
		if (i != 0)
			ss << " ";
		ss << bitstring[i];
	}
	string broadcastMsg = ss.str();
	
	setBroadcastMsg(broadcastMsg);
	
	return broadcastMsg;
}

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

