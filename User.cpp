#include "User.h"
#include <iostream>
#include <sstream>

string User::getUserName()
{
	string userName = m_userName;

	return userName;
}

void User::setUserName()
{
	cin.ignore();
	string userID;
	cout << "\n  Enter username:\t";
	getline(cin, userID);
	m_userName = userID;
}

string User::getUserInput()
{
	string userInput = m_userInput;

	return userInput;
}

void User::setUserInput()
{
	string userInput;
	cout << "  " << getUserName() << ", please enter your message:\t";
	getline(cin, userInput);
	m_userInput = userInput;
}

void User::setUserId()
{
	stringstream ss;
	int userID[10];
	// for loop to create a unique user id based on random number shuffle
	for (int i = 0; i < sizeof userID / sizeof userID[0]; i++)
	{
		userID[i] = (rand() % 9 + 0);
		ss << userID[i];
	}

	int result;
	ss >> result;
	m_userID = result;
}

int User::getUserId()
{
	int userID = m_userID;

	return userID;
}

string User::getEncryptedMsg()
{
	return m_encryptedMsg;
}

void User::setEncryptedMsg(string encryptedMsg)
{
	m_encryptedMsg = encryptedMsg;
}

string User::getBroadcastMsg()
{
	return m_broadcastMsg;
}

void User::setBroadcastMsg(string encryptedMsg)
{
	m_broadcastMsg = encryptedMsg;
}
