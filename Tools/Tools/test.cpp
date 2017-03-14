#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
#include "Connecter.h"


using namespace std;
#pragma comment(lib,"libmysql.lib") 
int main()
{
	const char user[] = "root";
	const char pswd[] = "bear4515";
	const char host[] = "localhost";
	const char db[] = "sakila";
	unsigned int port = 3306;

	Connecter con = Connecter(host, user, pswd, db, port);

	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int res;
	if (con.connect())
	{
		res=con.select("select * from city");
		if (!res)
		{
			result = con.getResult();
			if (result)
			{
				cout << "CITY_ID	" << "CITY_NAME	" << "COUNTRY_ID	" << "LAST_UPDATE	" << endl;
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					cout << sql_row[0] << " " << sql_row[1] << " " << sql_row[2] << " " << sql_row[3] << " " << endl;
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	system("pause");
	return 0;

}