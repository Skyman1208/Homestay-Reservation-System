#include"Header.h"

void Header::Login(MYSQL* conn) 
{
	//Variable
	bool userLogin = true;

	while (userLogin)
	{
		system("cls");
		SetConsoleTextAttribute(color, 10);
		cout << "\n\n\t\t\t|*******************************|";
		cout << "\n\t\t\t|  HOMESTAY RESERVATION SYSTEM  |";
		cout << "\n\t\t\t|            | Login |          |";
		cout << "\n\t\t\t|*******************************|";

		cout << "\n\n\t\t\t   Enter '0' to Close.";
		cout << "\n\t\t\t   StaffID: ", cin >> staffId;

		if (staffId != 0)
		{
			cout << "\t\t\t   Password: ", cin >> staffPassword;

			// Retrieve data from database
			string findStaffIdById = "SELECT * FROM staff_record WHERE StaffID LIKE '" + to_string(staffId) + "%'";
			const char* fsibi = findStaffIdById.c_str(); //!@#$ apa itu c_str
			qstate = mysql_query(conn, fsibi);
			if (!qstate)
			{
				result = mysql_store_result(conn);
				while ((row = mysql_fetch_row(result)))
				{

					//!@#$
					storeStaffId = row[0];
					storeStaffPassword = row[3];
					storeType = row[4];

					if (storeStaffId == to_string(staffId) && storeStaffPassword == staffPassword && storeType == "admin")
					{
						AdminMenu(conn, staffId);
						userLogin = false;

						mysql_free_result(result); //Clear result set from memory
						break;
					}
					else if (storeStaffId == to_string(staffId) && storeStaffPassword == staffPassword && storeType == "user")
					{
						r_MainMenu(conn, staffId);
						userLogin = false;

						mysql_free_result(result); //Clear result set from memory
						break;
					}
				}
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
				SetConsoleTextAttribute(color, 10);
			}
			SetConsoleTextAttribute(color, 4);
			cout << "\n\n\t\t\tWrong 'StaffID' or 'Password'. Please try again!\n\n";
			system("pause");
		}
		else
			exit(0);
	}

}