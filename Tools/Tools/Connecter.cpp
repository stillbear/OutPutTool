#include "Connecter.h"


Connecter::Connecter()
{
	
}

Connecter::Connecter(const char *hostIn, const char *userIn, const char *pswdIn, const char *dbIn, unsigned int portIn)
{
	host = hostIn;
	user = userIn;
	pswd = pswdIn;
	db = dbIn;
	port = portIn;
}

int Connecter::connect()
{
	if (mysql_real_connect(&myCont, host, user, pswd, db, port, NULL, 0)){
		return 1;
	}
	else
	{
		return 0;
	}
}

int Connecter::select(const char * sql)
{
	mysql_query(&myCont, "SET NAMES GBK");
	if (mysql_query(&myCont, sql)){
		result = mysql_store_result(&myCont);
		return 1;
	}
	else
	{
		return 0;
	}
}


Connecter::~Connecter()
{
}
