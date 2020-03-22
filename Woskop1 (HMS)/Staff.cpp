#include"Header.h"

void Header::a_staff(MYSQL* conn, int staffId)
{
	system("cls");

	int adminSChoice = 0;
	while (adminSChoice != 4)
	{
		system("cls");
		SetConsoleTextAttribute(color, 10);
		cout << "\n\t\t\t\t|*****************************|";
		cout << "\n\t\t\t\t|            STAFF            |";
		cout << "\n\t\t\t\t|          | ADMIN |          |";
		cout << "\n\t\t\t\t|*****************************|";

		cout << "\n\t\t\t\t1. Add Staff";
		cout << "\n\t\t\t\t2. Update Staff";
		cout << "\n\t\t\t\t3. Delete Staff";
		cout << "\n\t\t\t\t4. View Staff";
		cout << "\n\t\t\t\t5. Search Staff";
		cout << "\n\t\t\t\t6. Back";

		cout << "\n\n\t\t\t\tEnter Your Choice: ";
		cin >> adminSChoice;

		switch (adminSChoice)
		{
			case 1:
				StaffSignUp(conn);
				break;
			case 2:
				StaffUpdate(conn);
				break;
			case 3:
				StaffDelete(conn);
				break;
			case 4:
				system("cls");

				cout << "\n\t\t\t\t|*****************************|";
				cout << "\n\t\t\t\t|          VIEW STAFF         |";
				cout << "\n\t\t\t\t|          | ADMIN |          |";
				cout << "\n\t\t\t\t|*****************************|\n\n";
				StaffView(conn);
				system("pause");
				a_staff(conn, staffId);
				break;
			case 5:
				StaffSearch(conn);
				break;
			case 6:
				AdminMenu(conn, staffId);
				break;
			default:
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\tINVALID CHOICE.";
				system("pause");
			}
			cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
			_getch();
		}
	}
}

void Header::StaffSignUp(MYSQL* conn)
{
	system("cls"); //Clear terminal

	cout << "\n\n\t\t\t|*******************************|";
	cout << "\n\t\t\t|  HOMESTAY RESERVATION SYSTEM  |";
	cout << "\n\t\t\t|          | Sign up |          |";
	cout << "\n\t\t\t|*******************************|";

	cin.ignore();
	cout << "\n\n\t\t\tFull name: ", getline(cin, staffName);
	cout << "\t\t\tPhone number: ", getline(cin, staffPhoneNo);
	cout << "\t\t\tPassword: ", getline(cin, staffPassword);
	cout << "\t\t\tEmail: ", getline(cin, staffEmail);
	cout << "\t\t\tAddress: ", getline(cin, staffAddress);

	//Staff registration
	string insertSignUpData = "INSERT INTO staff_record (S_Name, S_PhoneNo, S_Password, S_Type, S_Email, S_Address) values ('" + staffName + "','" + staffPhoneNo + "','" + staffPassword + "', 'user','" + staffEmail + "','" + staffAddress + "')";
	const char* isud = insertSignUpData.c_str(); // c_str converts string to constant char and this is required
	qstate = mysql_query(conn, isud);
	if (!qstate)
		cout << endl << "\n\n\t\t\tSuccessfully registered." << endl;
	else
		SetConsoleTextAttribute(color, 4); cout << "Query Execution Problem!" << mysql_errno(conn) << endl; SetConsoleTextAttribute(color, 10);

	//staffName = "";
	//cout << "\n\n\t\t\tPlease enter staff name for Staff ID and password.";
	//cout << "\n\t\t\tStaff fullname: ", 
	//	cin.ignore(), 
	//	getline(cin, staffName);

	//// Retrieve data from database
	//string findStaffIdByName = "SELECT * FROM staff_record WHERE S_Name LIKE '%" + staffName + "%'";
	//const char* fsibe = findStaffIdByName.c_str();
	//qstate = mysql_query(conn, fsibe);
	//if (!qstate)
	//{
	//	result = mysql_store_result(conn);
	//	while ((row = mysql_fetch_row(result)))
	//	{
	//		storeStaffId = row[0];
	//		storeStaffName = row[1];
	//		storeStaffPassword = row[3];

	//		if (storeStaffName == staffName)
	//		{
	//			cout << "\n\n\t\t\tPlease remember your Staff ID and password.";
	//			cout << "\n\t\t\tStaff ID: " << storeStaffId;
	//			cout << "\n\t\t\tPassword: " << storeStaffPassword;

	//			mysql_free_result(result); //Clear result set from memory
	//			break;
	//		}
	//	}
	//}
	//else
	//{
	//	cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	//}
	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::StaffUpdate(MYSQL* conn)
{
	//Database variable
	int qstate;

	system("cls");

	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|         UPDATE STAFF        |";
	cout << "\n\t\t\t\t|          | ADMIN |          |";
	cout << "\n\t\t\t\t|*****************************|\n";

	StaffView(conn);

back:
	cout << "\nStaff ID: ";
	if (!(cin >> staffId))
		SetConsoleTextAttribute(color, 4); cout << "That's not a number; "; SetConsoleTextAttribute(color, 10); goto back;

	cout << "\n\n\t\t\tFull name: ", getline(cin, staffName);
	cout << "\t\t\tPhone number: ", getline(cin, staffPhoneNo);
	cout << "\t\t\tPassword: ", getline(cin, staffPassword);
	cout << "\t\t\tUser type (admin/user): ", getline(cin, staffType);
	cout << "\t\t\tEmail: ", getline(cin, staffEmail);
	cout << "\t\t\tAddress: ", getline(cin, staffAddress);

	string updateStaffData = "UPDATE staff_record SET S_Name = '" + staffName + "', S_PhoneNo = '" + staffPhoneNo + "', S_Password = '" + staffPassword + "', S_Type = '" + staffType + "', S_Email = '" + staffEmail + "', S_Address = '" + staffAddress + "' WHERE StaffID = '" + to_string(staffId) + "'";
	const char* usd = updateStaffData.c_str();
	qstate = mysql_query(conn, usd);
	if (!qstate)
		cout << endl << "\n\n\t\t\tSuccessfully Saved In Database." << endl;
	else
		SetConsoleTextAttribute(color, 4); cout << "Failed To Update! " << mysql_errno(conn) << endl; SetConsoleTextAttribute(color, 10);

	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::StaffDelete(MYSQL* conn)
{
	//Database variable
	int qstate;

	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|        DELETE STAFF         |";
	cout << "\n\t\t\t\t|          | ADMIN |          |";
	cout << "\n\t\t\t\t|*****************************|";

	StaffView(conn);

back:
	cout << "\n\nStaff ID: ";
	while (!(cin >> staffId))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Staff ID: ";
	}

	string deleteStaff = "DELETE FROM staff_record WHERE StaffID = '" + to_string(staffId) + "'";
	const char* ds = deleteStaff.c_str();
	qstate = mysql_query(conn, ds);
	if (!qstate)
		cout << "Successfully Deleted From Database." << endl;
	else
		SetConsoleTextAttribute(color, 4); cout << "Failed To Delete!" << mysql_errno(conn) << endl; SetConsoleTextAttribute(color, 10);

	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::StaffView(MYSQL* conn)
{
	//Database variable
	int qstate;
	MYSQL_ROW row;
	MYSQL_RES* result;

	string displayAllStaff = "SELECT * FROM staff_record";
	const char* das = displayAllStaff.c_str();
	qstate = mysql_query(conn, das);

	if (!qstate)
	{
		result = mysql_store_result(conn);
		cout << endl;

		cout << center(" Staff ID", 10) << "|";
		cout << center("Name", 40) << "|";
		cout << center("Phone number", 15) << "|";
		cout << center("Passwword", 13) << "|";
		cout << center("User type", 12) << "|";
		cout << center("Email", 20) << "|";
		cout << center("Address", 25) << "|";
		cout << "\n ==============================================================================================================================================\n";
		             
		while ((row = mysql_fetch_row(result)))
		{
			cout <<" "<<prd(row[0], 10) << "|";
			cout << prd(row[1], 40) << "|";
			cout << prd(row[2], 15) << "|";
			cout << prd(row[3], 13) << "|";
			cout << prd(row[4], 12) << "|";
			cout << prd(row[5], 20) << "|";
			cout << prd(row[6], 25) << "|";
			cout << "\n";
		}
		cout << "\n\n\n";
		mysql_free_result(result); //Clear result set from memory
	}
	else
	{
		SetConsoleTextAttribute(color, 4); 
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 10);
	}
	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::StaffSearch(MYSQL* conn)
{
	int adminHChoice = 0;

	cout << "\n\t\t\t\tYou want to search staff by ? \n";
	cout << "\t\t\t\t1. ID\n";
	cout << "\t\t\t\t2. Name\n";
	cout << "\t\t\t\t3. Phone No\n";
	cout << "\t\t\t\t4. Email\n";
	cout << "\t\t\t\t5. Address\n";
	cout << "\t\t\t\t6. Back\n";

	cout << "\n\t\t\t\tEnter Your Choice: ";
	cin >> adminHChoice;

	switch (adminHChoice)
	{
		case 1:
			cout << "\t\t\t\tEnter Staff Id : ";
			while (!(cin >> homestayPrice))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "\n\t\t\tPrice: ";
			}
			SearchStaffById(conn, staffId);
			break;

		case 2:
			cout << "\t\t\t\tEnter Staff Name : ";
			cin.ignore();
			getline(cin, staffName);

			SearchStaffByName(conn, staffName);
			break;

		case 3:
			cout << "\t\t\t\tEnter Staff PhoneNo : ";
			cin.ignore();
			getline(cin, staffPhoneNo);
			
			SearchStaffByPhone(conn, staffPhoneNo);
			break;

		case 4:
			cout << "\t\t\t\tEnter Staff Email : ";
			cin.ignore();
			getline(cin, staffEmail);
			
			SearchStaffByEmail(conn, staffEmail);
			break;

		case 5:
			cout << "\t\t\t\tEnter Staff Address : ";
			cin.ignore();
			getline(cin, staffAddress);
			
			SearchStaffByAddress(conn, staffAddress);
			break;

		case 6:
			a_staff(conn, staffId);
			break;

		default:
		{
			SetConsoleTextAttribute(color, 4);
			cout << "\n\n\t\t\tINVALID CHOICE.";
			SetConsoleTextAttribute(color, 10);

			system("pause");
		}
	}
	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}



