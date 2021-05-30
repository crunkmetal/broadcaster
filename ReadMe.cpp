#include "ReadMe.h"
#include <iostream>
#include "Pausing.h"

using namespace std;

void ReadMe::info()
{
	Pausing pause;
	
	cout << "\n\t\tSCRAMBLER\n\n";

	cout << "  This application collects user information,\n";
	cout << "  encrypts the data, converts the data\n";
	cout << "  to binary (for broadcast) and saves the data.\n\n";
	pause.pause_1s();

	cout << "  The user is able to load and view this data.\n";
	cout << "  This data, once viewed, is changed to reflect this.\n";

	pause.pause_1s();
}
