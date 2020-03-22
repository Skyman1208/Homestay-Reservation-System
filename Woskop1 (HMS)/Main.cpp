#include"Header.h"
using namespace std;

int main() 
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	MYSQL* conn;
	Header HS;
	//open connection
	conn = mysql_init(NULL);
	mysql_real_connect(conn, "localhost", "root", "", "hms_db", 3306, NULL, 0);
	
	HS.loading();
	
	if (conn)
	{
		
		cout << "\n\n\t\tDatabase Connected\n\t\t";
		system("pause");
		system("cls");
		
		HS.Login(conn);
	}
	else
		cout << "Failed Connect To Database!" << mysql_errno(conn) << endl;

	//close connection
	mysql_close(conn);


	return 0;
}