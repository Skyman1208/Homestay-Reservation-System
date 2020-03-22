#include"Header.h"

void Header::SearchStaffById(MYSQL* conn, int staffId)
{
	string query = "SELECT * FROM staff_record WHERE StaffID = '" + to_string(staffId) + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << "check qstate = " << qstate << endl;
	
	if (qstate==0)
	{	
		cout << center("Staff ID", 10) << "|";
		cout << center("Name", 40) << "|";
		cout << center("Phone number", 15) << "|";
		cout << center("Passwword", 13) << "|";
		cout << center("User type", 12) << "|";
		cout << center("Email", 20) << "|";
		cout << center("Address", 25) << "|";
		cout << "\n==============================================================================================================================================\n";
		
		while ((row = mysql_fetch_row(result)))
		{
				cout << prd(row[0], 10) << "|";
				cout << prd(row[1], 40) << "|";
				cout << prd(row[2], 15) << "|";
				cout << prd(row[3], 13) << "|";
				cout << prd(row[4], 12) << "|";
				cout << prd(row[5], 20) << "|";
				cout << prd(row[6], 25) << "|";
				cout << "\n";
		}
	}
	else
	{
		cout << " Sorry the id is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

void Header::SearchStaffByName(MYSQL* conn, string staffName)
{
	string query = "SELECT * FROM staff_record WHERE S_Name LIKE '%" + staffName + "%'";
	const char* check = query.c_str();
	qstate=mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Staff ID", 10) << "|";
	cout << center("Name", 40) << "|";
	cout << center("Phone number", 15) << "|";
	cout << center("Passwword", 13) << "|";
	cout << center("User type", 12) << "|";
	cout << center("Email", 20) << "|";
	cout << center("Address", 25) << "|";
	cout << "\n==============================================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 10) << "|";
			cout << prd(row[1], 40) << "|";
			cout << prd(row[2], 15) << "|";
			cout << prd(row[3], 13) << "|";
			cout << prd(row[4], 12) << "|";
			cout << prd(row[5], 20) << "|";
			cout << prd(row[6], 25) << "|";
			cout << "\n";
		}
	}
	else {
		cout << " Sorry the name is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

void Header::SearchStaffByPhone(MYSQL* conn, string staffPhoneNo)
{
	string query = "SELECT * FROM staff_record WHERE S_PhoneNo= '" + staffPhoneNo + "'";
	const char* check = query.c_str();
	qstate=mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Staff ID", 10) << "|";
	cout << center("Name", 40) << "|";
	cout << center("Phone number", 15) << "|";
	cout << center("Passwword", 13) << "|";
	cout << center("User type", 12) << "|";
	cout << center("Email", 20) << "|";
	cout << center("Address", 25) << "|";
	cout << "\n==============================================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
		cout << prd(row[0], 10) << "|";
		cout << prd(row[1], 40) << "|";
		cout << prd(row[2], 15) << "|";
		cout << prd(row[3], 13) << "|";
		cout << prd(row[4], 12) << "|";
		cout << prd(row[5], 20) << "|";
		cout << prd(row[6], 25) << "|";
		cout << "\n";
		}
	}
	else {
		cout << " Sorry the phone no is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

void Header::SearchStaffByEmail(MYSQL* conn, string staffEmail)
{
	string query = "SELECT * FROM staff_record WHERE S_Email = '%" + staffEmail + "%'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Staff ID", 10) << "|";
	cout << center("Name", 40) << "|";
	cout << center("Phone number", 15) << "|";
	cout << center("Passwword", 13) << "|";
	cout << center("User type", 12) << "|";
	cout << center("Email", 20) << "|";
	cout << center("Address", 25) << "|";
	cout << "\n==============================================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 10) << "|";
			cout << prd(row[1], 40) << "|";
			cout << prd(row[2], 15) << "|";
			cout << prd(row[3], 13) << "|";
			cout << prd(row[4], 12) << "|";
			cout << prd(row[5], 20) << "|";
			cout << prd(row[6], 25) << "|";
			cout << "\n";
		}
		system("pause");
		system("cls");
	}
	else {
		cout << " Sorry the email is not found " << endl;
		system("pause");
		system("cls");
	}
}

void Header::SearchStaffByAddress(MYSQL* conn, string staffAddress)
{
	string query = "SELECT * FROM staff_record WHERE S_Address = '%" + staffAddress + "$'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Staff ID", 10) << "|";
	cout << center("Name", 40) << "|";
	cout << center("Phone number", 15) << "|";
	cout << center("Passwword", 13) << "|";
	cout << center("User type", 12) << "|";
	cout << center("Email", 20) << "|";
	cout << center("Address", 25) << "|";
	cout << "\n==============================================================================================================================================\n";
	cout << "qstate = " << qstate;
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 10) << "|";
			cout << prd(row[1], 40) << "|";
			cout << prd(row[2], 15) << "|";
			cout << prd(row[3], 13) << "|";
			cout << prd(row[4], 12) << "|";
			cout << prd(row[5], 20) << "|";
			cout << prd(row[6], 25) << "|";
			cout << "\n";
		}
		system("pause");
		system("cls");
	}
	else {
		cout << " Sorry the address is not found " << endl;
		system("pause");
		system("cls");
	}
}


