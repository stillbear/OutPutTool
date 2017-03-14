#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>


using namespace std;
#pragma comment(lib,"libmysql.lib") 

#pragma once
class Connecter
{
public:
	MYSQL_RES *result;
public:
	Connecter();
	Connecter(const char *hostIn, const char *userIn, const char *pswdIn, const char *dbIn, unsigned int portIn);
	~Connecter();
	int connect();
	int select(const char * sql);
private:
	const char *host;
	const char *user;
	const char *pswd;
	const char *db;
	unsigned int port;
	MYSQL myCont;
	MYSQL_ROW sql_row;
};

