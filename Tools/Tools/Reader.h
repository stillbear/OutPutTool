#pragma once
#include <fstream>
#include <stdlib.h>
using namespace std;
class Reader
{
public:
	
	Reader();
	Reader(char * fileName);
	~Reader();

private:
	ifstream in;
};

