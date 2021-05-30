#pragma once
#include <string>
#include <vector>
#include "Pausing.h"
#include "User.h"

using namespace std;

class Encryption : public Pausing, User
{
public:
	bool isEncrypted = false;
	bool restart = false;
	
	vector<string> bitstring{};
	string encrypt(string);
	void decrypt(string);
	string convertToBinary(string, string);
	string askToEncrypt(string);
	string broadcastMsg(bool, string, string, string);

};

