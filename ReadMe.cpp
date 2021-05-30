#include "ReadMe.h"
#include <iostream>
#include "Pausing.h"

using namespace std;

void ReadMe::info()
{
	Pausing pause;
	
	cout << "\n\t\tSCRAMBLER\n\n";

	cout << "  This application accepts a user message,\n";
	cout << "  encrypts the message, converts the message\n";
	cout << "  to binary (for broadcast) and saves the\n";
	cout << "  encrypted binary message.\n\n";

	cout << "  The user is able to later load this message,\n";
	cout << "  convert the message from binary into it's\n";
	cout << "  encrypted format.  The user is then able to\n";
	cout << "  decrypt and display the message for reading.\n\n";

	pause.pause_10m();
	pause.pause_10m();
	pause.pause_10m();

}
