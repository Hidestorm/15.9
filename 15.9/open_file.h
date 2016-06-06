#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close(); // close in case it was already open
	in.clear(); // clear any existing errors
				// if the open fails, the stream will be in an invalid state
	in.open(file.c_str()); // open the file we were given
	return in; // condition state is good if open succeeded
}