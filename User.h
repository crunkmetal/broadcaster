#pragma once
#include <string>

using namespace std;

class User
{
public:
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

private:
	string m_userName;
	string m_userInput;
	int m_userID = 0;
	string m_encryptedMsg;
	string m_broadcastMsg;
};

