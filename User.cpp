/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#include "User.h"
#include <iostream>
#include <sstream>
// public member to get the user's name
string User::getUserName()
{
	// assigning the value of a private variable to an accessible variable
	string userName = m_userName;
	// return that value for use
	return userName;
}
// function to set a private variables value
void User::setUserName()
{
	cin.ignore();	// ignore or clear values from cin input
	string userID;
	cout << "\n  Enter username:\t";
	getline(cin, userID);	// takes user input and assigns to a variable
	m_userName = userID;	// assigning this value to a private property
}
// member function to retrieve the value of a private property
string User::getUserInput()
{
	// assign the value of a pvt member prop to a usable variable
	string userInput = m_userInput;
	// return that usable variable
	return userInput;
}
// public member function to assign a value to a private property
void User::setUserInput()
{
	string userInput;
	cout << "  " << getUserName() << ", please enter your message:\t";
	getline(cin, userInput);	// get user input...
	m_userInput = userInput;	// ...and assign to a variable
}
// public member function used to assign a value to a private property
void User::setUserId()
{
	stringstream ss;	// open a filestream
	int userID[10];	// initialize an array of ten elements
	// for loop to create a unique user id based on random number shuffle
	for (int i = 0; i < sizeof userID / sizeof userID[0]; i++)
	{
		userID[i] = (rand() % 9 + 0);	// for each element in array, create a random number
		ss << userID[i];	// input that random number into the stringstream
	}
	int result; // initialize a variable
	ss >> result;	// assign the value of the stringstream to the variable
	m_userID = result;	// assign the value of the variable to the private property
}
// public member function to access a private property
int User::getUserId()
{
	int userID = m_userID;	// value of private property assigned to local variable
	// return the value of the private property in an accessible string
	return userID;
}
// public member function to get the value of a private property
string User::getEncryptedMsg()
{
	return m_encryptedMsg;	// returns the value of the private property
}
// public member function to assign the value of input parameter to a private property
void User::setEncryptedMsg(string encryptedMsg)
{
	m_encryptedMsg = encryptedMsg;
}
// public member function to retrieve the value of a private property
string User::getBroadcastMsg()
{
	return m_broadcastMsg;  // returns the value of the private property
}
// public member function to assign the value of an input parameter to a private property
void User::setBroadcastMsg(string encryptedMsg)
{
	m_broadcastMsg = encryptedMsg;
}
