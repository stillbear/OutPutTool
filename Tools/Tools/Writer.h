#pragma once
#include <fstream>
#include <stdlib.h>
using namespace std;
class Writer
{
public:
	Writer(); 
	Writer(char * fileName);
	~Writer();
	void output(char * content);
	void close();
	bool isOpen();

private:
	ofstream fout;
	char buffer[256];
};

