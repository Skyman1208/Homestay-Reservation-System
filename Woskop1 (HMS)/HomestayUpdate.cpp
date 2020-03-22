#include"Header.h"

void Header::HomestayUpdateName(MYSQL* conn, int homestayId, string homestayName)
{
	int qstate;
	string updateHomestayData = "UPDATE homestay_record SET H_Name = '" + homestayName + "' WHERE HomestayID = '" + to_string(homestayId) + "'";
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdatePrice(MYSQL* conn, int homestayId, double homestayPrice)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_Price` = '" + to_string(homestayPrice) + "' WHERE `HomestayID` = " + to_string(homestayId) + "'";
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdatePool(MYSQL* conn, int homestayId, string homestayPool)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_Pool` = '" + homestayPool + "' WHERE `HomestayID` = " + to_string(homestayId) + "'" ;
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdateType(MYSQL* conn, int homestayId, string homestayType)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_Type` = '" + homestayType + "' WHERE `HomestayID` = " + to_string(homestayId) + "'" ;
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdateNumOfRoom(MYSQL* conn, int homestayId, int homestayNumOfRoom)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_NumOfRoom` = '" + to_string(homestayNumOfRoom) + "' WHERE `HomestayID` = " + to_string(homestayId) + "'";
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdateNumOfBed(MYSQL* conn, int homestayId, int homestayNumOfBed)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_NumOfBed` = '" + to_string(homestayNumOfBed) + "' WHERE `HomestayID` = " + to_string(homestayId) + "'";
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdateNumOfToilet(MYSQL* conn, int homestayId, int homestayNumOfToilet)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_NumOfToilet` = '" + to_string(homestayNumOfToilet) + "' WHERE HomestayID = '" + to_string(homestayId) + "'";
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdateAircond(MYSQL* conn, int homestayId, string homestayAircond)
{
	int qstate;
	string updateHomestayData = "UPDATE `homestay_record` SET `H_Aircond` = '" + homestayAircond + "' WHERE `HomestayID` = '" + to_string(homestayId) + "'" ;
	const char* uhd = updateHomestayData.c_str();
	/*cout << "uhd = " << uhd;*/
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);
		system("pause");
	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

void Header::HomestayUpdateAll(MYSQL* conn, int homestayId)
{

	cout << "\n\n\t\t\tHomestay name: "; cin.ignore();  getline(cin, homestayName);

back:
	cout << "\t\t\tPrice: ";
	if (!(cin >> homestayPrice))
		SetConsoleTextAttribute(color, 4); cout << "That's not a number; "; SetConsoleTextAttribute(color, 10); goto back;

back1:
	cout << "\t\t\tType(1=Single, 2=Couple, 3=Family): ", getline(cin, homestayType);
	if (homestayType == "1")
	{
		homestayType = "Single";
	}
	else if (homestayType == "2")
	{
		homestayType = "Couple";
	}
	else if (homestayType == "3")
	{
		homestayType = "Couple";
	}
	else
	{
		cout << "\tInvalid answer. Try again\n";
		goto back1;
	}

back2:
	cout << "\t\t\tNumber of room: ";
	if (!(cin >> homestayNumOfRoom))
		SetConsoleTextAttribute(color, 4); cout << "That's not a number; "; SetConsoleTextAttribute(color, 10); goto back2;

back3:
	cout << "\t\t\tNumber of bed: ";
	if (!(cin >> homestayNumOfBed))
		SetConsoleTextAttribute(color, 4); cout << "That's not a number; "; SetConsoleTextAttribute(color, 10); goto back3;

back4:
	cout << "\t\t\tNumber of toilet: ";
	if (!(cin >> homestayNumOfToilet))
		SetConsoleTextAttribute(color, 4); cout << "That's not a number; "; SetConsoleTextAttribute(color, 10); goto back4;

back5:
	cout << "\t\t\tPool(1=Yes,0=No): ", getline(cin, homestayPool);
	if (homestayPool == "1")
	{
		homestayPool == "Yes";
	}
	else if (homestayPool == "0")
	{
		homestayPool = "No";
	}
	else
	{
		cout << "\tInvalid answer. Try again\n";
		goto back5;
	}

back6:
	cout << "\t\t\tAircond(1=yes,0=no): ", getline(cin, homestayAircond);
	if (homestayAircond == "1")
	{
		homestayAircond == "Yes";
	}
	else if (homestayAircond == "0")
	{
		homestayAircond = "No";
	}
	else
	{
		cout << "\tInvalid answer. Try again\n";
		goto back6;
	}

	string updateHomestayData = "UPDATE homestay_record SET H_Name = '" + homestayName + "', H_Price = '" + to_string(homestayPrice) + "', H_Pool = '" + homestayPool + "', H_Type = '" + homestayType + "', H_NumOfRoom = '" + to_string(homestayNumOfRoom) + "', H_NumOfBed = '" + to_string(homestayNumOfBed) + "', H_NumOfToilet = '" + to_string(homestayNumOfToilet) + "', H_Aircond = '" + homestayAircond + "' WHERE HomestayID = '" + to_string(homestayId) + "'";
	const char* uhd = updateHomestayData.c_str();
	qstate = mysql_query(conn, uhd);
	if (!qstate)
	{
		cout << endl << "\n\t\t\tSuccessfully Saved In Database.\n\t\t\t" << endl;
		system("pause");
		system("cls");
		h_view(conn);

	}
	else {
		cout << "Failed To Update! " << mysql_errno(conn) << endl;
		system("pause");
	}
}

//UPDATE 'homestay_record' SET 'H_Aircond' = 'no' WHERE 'HomestayID' = 8
//UPDATE `homestay_record` SET `H_Aircond` = 'yes' WHERE `HomestayID` = 8
//UPDATE homestay_record SET H_Name = 'LESTARI TUAH ', H_Price = '2000', H_Pool = 'no', H_Type = 'single', H_NumOfRoom = '2 ', H_NumOfBed = '2', H_NumOfToilet = '2', H_Aircond = 'yes' WHERE HomestayID = 12