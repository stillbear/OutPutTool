#include <Windows.h>
#include <mysql.h>
#include <string>
#include <iostream>


using namespace std;
#pragma comment(lib,"libmysql.lib") 
int main()
{
	const char user[] = "root";
	const char pswd[] = "bear4515";
	const char host[] = "localhost";
	const char db[] = "sakila";
	unsigned int port = 3306;

	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int res;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, db, port, NULL, 0))
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式
		res = mysql_query(&myCont, "select * from city");//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);
			if (result)
			{
				cout << "CITY_ID	"<< "CITY_NAME	"<< "COUNTRY_ID	" << "LAST_UPDATE	"<< endl;
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					
					cout << sql_row[0] << " " << sql_row[1] << " " << sql_row[2] << " " << sql_row[3]  << " " << endl;
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
		system("pause");
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&myCont);
	system("pause");
	return 0;

}