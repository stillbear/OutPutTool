#include "Writer.h"


Writer::Writer()
{
}


Writer::~Writer()
{
}

Writer::Writer(char * fileName)
{
	fout = ofstream(fileName);
}

void Writer::output(char * content)
{
	fout << content;
}

void Writer::close()
{
	fout.close();
	
}

bool Writer::isOpen()
{
	return fout.is_open();
}
