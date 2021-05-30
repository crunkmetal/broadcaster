/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */
// preprocessor directives
#include "ReadMe.h"
#include <iostream>
#include "Pausing.h"
// incorporating standard template library
using namespace std;

void ReadMe::info()
{
	Pausing pause;	// instantiate an object of Pausing class
	
	cout << "\n\t\tSCRAMBLER\n\n";

	cout << "  This application collects user information,\n";
	cout << "  encrypts the data, converts the data\n";
	cout << "  to binary (for broadcast) and saves the data.\n\n";
	// invoke pause function
	pause.pause_1s();

	cout << "  The user is able to load and view this data.\n";
	cout << "  This data, once viewed, is changed to reflect this.\n";
	// invoke pause function
	pause.pause_1s();
	pause.pause_1s();
}
