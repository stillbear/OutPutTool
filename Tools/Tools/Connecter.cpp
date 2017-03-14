#include "Connecter.h"


Connecter::Connecter()
{
	mysql_init(&myCont);
}

Connecter::Connecter(const char *hostIn, const char *userIn, const char *pswdIn, const char *dbIn, unsigned int portIn)
{
	host = hostIn;
	user = userIn;
	pswd = pswdIn;
	db = dbIn;
	port = portIn;
	mysql_init(&myCont);
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
	int res = mysql_query(&myCont, sql);//≤È—Ø
	if (!res)
	{
		result = mysql_store_result(&myCont);
	}
	else
	{
		cout << "query sql failed!" << endl;
	}
	return res;
}

MYSQL_RES * Connecter::getResult()
{
	return result;
}


Connecter::~Connecter()
{
}
