/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#pragma once
#include <string>
#include "Encryption.h"
// using standard template library
using namespace std;

class Filesave : public Encryption	// class Filesave is derived from base class Encryption
{

public:	// access modifier
	// function prototypes
	void askToSave(int, string, string, string, string);
	void saveFile(int, string, string, string, string);
	void loadFile();
	void updatedFile();

private:
	
};

