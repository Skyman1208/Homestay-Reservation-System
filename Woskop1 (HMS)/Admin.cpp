#include"Header.h"

void Header::AdminMenu(MYSQL* conn, int staffId)
{
	system("cls");

	// Retrieve data from database
	string findStaffIdById = "SELECT * FROM staff_record WHERE StaffID LIKE '" + to_string(staffId) + "%'";
	const char* fsibi = findStaffIdById.c_str(); //!@#$ apa itu c_str = STRING to CHAR Data type
	qstate = mysql_query(conn, fsibi);
	if (!qstate)
	{
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);
		cout << "\n\t\t\t\t Welcome " << row[1] << endl;
	}

	int adminChoice = 0;
	while (adminChoice != 4)
	{
		system("cls");
		SetConsoleTextAttribute(color, 10);
		cout << "\n\t\t\t\t|*****************************|";
		cout << "\n\t\t\t\t| HOMESTAY RESERVATION SYSTEM |";
		cout << "\n\t\t\t\t|           | ADMIN |         |";
		cout << "\n\t\t\t\t|*****************************|";


		cout << "\n\n\n\t\t\t\t1. Homestay";
		cout << "\n\t\t\t\t2. Staff";
		cout << "\n\t\t\t\t3. Report";
		cout << "\n\t\t\t\t4. Logout";

		cout << "\n\n\t\t\t\tEnter Your Choice: ";
		cin >> adminChoice;

			switch (adminChoice)
			{
			case 1:
				a_homestay(conn, staffId);
				break;
			case 2:
				a_staff(conn, staffId);
				break;
			case 3:
				a_report(conn, staffId);
				break;
			case 4:
				Login(conn);
				break;

			default:
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\tInvalid choice!";
				system("pause");
			}
			cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
			_getch();
		}
	}
}