/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#pragma once
#include <string>
// using the standard template library
using namespace std;

class User
{
public:	// access modifier
	// function prototypes
	string getUserName();
	void setUserName();
	string getUserInput();
	void setUserInput();
	void setUserId();
	int getUserId();
	string getEncryptedMsg();
	void setEncryptedMsg(string);

	string getBroadcastMsg();
	void setBroadcastMsg(string);

private:	// access modifier
	// class properties
	string m_userName;
	string m_userInput;
	int m_userID = 0;
	string m_encryptedMsg;
	string m_broadcastMsg;
};

