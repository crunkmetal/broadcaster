#pragma once
#include <string>
#include "Encryption.h"

using namespace std;

class Filesave : public Encryption
{
public:
	void askToSave(int, string, string, string, string);
	void saveFile(int, string, string, string, string);
	void loadFile();
	void updatedFile();

private:
	
};

