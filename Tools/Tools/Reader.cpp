#include "Reader.h"


Reader::Reader()
{
}

Reader::Reader(char * fileName)
{
	in = ifstream(fileName);
}

Reader::~Reader()
{
}

