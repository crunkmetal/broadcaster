/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#pragma once
#include <string>
#include <vector>
#include "Pausing.h"
#include "User.h"
// using standard template library
using namespace std;

class Encryption : public Pausing, User	// Encryption class derived from both Pausing and User classes
{
public:	// public access modifier
	// member function prototypes
	bool isEncrypted = false;
	bool restart = false;
	
	vector<string> bitstring{};
	string encrypt(string);
	void decrypt(string);
	string convertToBinary(string, string);
	string askToEncrypt(string);
	string broadcastMsg(bool, string, string, string);

};

