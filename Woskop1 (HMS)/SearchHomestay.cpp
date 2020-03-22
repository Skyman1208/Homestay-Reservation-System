#include"Header.h"

void Header::SearchHomestayById(MYSQL* conn, int homestayId)
{
	string query = "SELECT * FROM homestay_record WHERE HomestayID = '" + to_string(homestayId) + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	if (qstate == 0)
	{
		cout << center("Homestay ID ", 12) << "|";
		cout << center("Name", 25) << "|";
		cout << center("Price", 10) << "|";
		cout << center("Pool", 8) << "|";
		cout << center("Type", 8) << "|";
		cout << center("Number of room", 15) << "|";
		cout << center("Number of bed", 14) << "|";
		cout << center("Number of toilet", 17) << "|";
		cout << center("Aircond", 8) << "|";
		cout << "\n==============================================================================================================================\n";

		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
		cout << "\n\n\n";
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\t\t Sorry the id is not found " << endl;
		system("pause");
		system("cls");
	}
	cout << "\t\t\t\t";
	system("pause");
	system("cls");
}


void Header::SearchHomestayByName(MYSQL* conn, string homestayName)
{
	string query = "SELECT * FROM homestay_record WHERE H_Name LIKE '%" + homestayName + "%'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n"; 
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the name is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByPrice(MYSQL* conn, double homestayPrice)
{
	string query = "SELECT * FROM homestay_record WHERE H_Price = '" + to_string(homestayPrice) + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the price is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByPool(MYSQL* conn, string homestayPool)
{
	string query = "SELECT * FROM homestay_record WHERE H_Pool = '" + homestayPool + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the pool is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByType(MYSQL* conn, string homestayType)
{
	string query = "SELECT * FROM homestay_record WHERE H_Type = '" + homestayType + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the type is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByNumOfRoom(MYSQL* conn, int homestayNumOfRoom)
{
	string query = "SELECT * FROM homestay_record WHERE H_NumOfRoom = '" + to_string(homestayNumOfRoom) + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the number of room is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByNumOfBed(MYSQL* conn, int homestayNumOfBed)
{
	string query = "SELECT * FROM homestay_record WHERE H_NumOfBed = '" + to_string(homestayNumOfBed) + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the number of bed is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByNumOfToilet(MYSQL* conn, int homestayNumOfToilet)
{
	string query = "SELECT * FROM homestay_record WHERE H_NumOfToilet = '" + to_string(homestayNumOfToilet) + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the number of toilet is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}


void Header::SearchHomestayByAircond(MYSQL* conn, string homestayAircond)
{
	string query = "SELECT * FROM homestay_record WHERE H_Aircond = '" + homestayAircond + "'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);

	cout << center("Homestay ID ", 12) << "|";
	cout << center("Name", 25) << "|";
	cout << center("Price", 10) << "|";
	cout << center("Pool", 8) << "|";
	cout << center("Type", 8) << "|";
	cout << center("Number of room", 15) << "|";
	cout << center("Number of bed", 14) << "|";
	cout << center("Number of toilet", 17) << "|";
	cout << center("Aircond", 8) << "|";
	cout << "\n==============================================================================================================================\n";
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			cout << prd(row[0], 12) << "|";
			cout << prd(row[1], 25) << "|";
			cout << prd(row[2], 10) << "|";
			cout << prd(row[3], 8) << "|";
			cout << prd(row[4], 8) << "|";
			cout << prd(row[5], 15) << "|";
			cout << prd(row[6], 14) << "|";
			cout << prd(row[7], 17) << "|";
			cout << prd(row[8], 8) << "|";
			cout << "\n";
		}
	}
	else 
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry the aircond is not found " << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}