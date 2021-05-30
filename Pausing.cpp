// preprocessor directives
#include "Pausing.h"
#include <chrono>	// library for time stuff
#include <thread>	// library for multithreading

using namespace std;
// function to pause execution for 10ms
void Pausing::pause_10m()
{
	chrono::milliseconds dura(10);
	this_thread::sleep_for(chrono::milliseconds(dura));
}
// function to pause execution for 1sec
void Pausing::pause_1s()
{
	chrono::seconds duration(1);
	this_thread::sleep_for(duration);
}



