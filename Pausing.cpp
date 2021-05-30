/*
	Bryan Jeremy
	CSC275 C++ Programming II
	Assignment: File I/O (Input and Output)
	30MAY21
 */

// preprocessor directives
#include "Pausing.h"
#include <chrono>	// library for time stuff
#include <thread>	// library for multithreading
// using standard template library
using namespace std;
// member function to pause execution for 10ms
void Pausing::pause_10m()
{
	chrono::milliseconds dura(10);
	this_thread::sleep_for(chrono::milliseconds(dura));
}
// member function to pause execution for 1sec
void Pausing::pause_1s()
{
	chrono::seconds duration(1);
	this_thread::sleep_for(duration);
}



