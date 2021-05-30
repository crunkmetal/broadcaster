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

/*
https://youtu.be/V-BFlMrBtqQ


 alternate pausing solution
 #include <Windows.h>
 	Sleep(1000);

to delete a file
	#include <stdio.h>
	
	int main()
	{
		// first make sure the file exists
	    if(remove("nameoffile.txt") !=0)
	      perror("This file does not exist");	<-- this text is added to C++ default text
	    else
	    puts("File has been deleted.");
	  return 0;
	 }
 */