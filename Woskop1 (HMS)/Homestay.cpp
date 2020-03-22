/*
------------------------INFO-------------------------
SetConsoleTextAttribute(color, 4); <--- WARNA MERAH
SetConsoleTextAttribute(color, 10); <--- WARNA HIJAU
*/


#include"Header.h"

void Header::a_homestay(MYSQL *conn, int staffId)
{
	system("cls");

	int adminHChoice = 0;
	while (adminHChoice != 6)
	{
		system("cls");
		SetConsoleTextAttribute(color, 10);
		cout << "\n\t\t\t\t|*****************************|";
		cout << "\n\t\t\t\t|           HOMESTAY          |";
		cout << "\n\t\t\t\t|          | ADMIN |          |";
		cout << "\n\t\t\t\t|*****************************|";

		cout << "\n\n\n\t\t\t\t1. Add Homestay";
		cout << "\n\t\t\t\t2. Update Homestay";
		cout << "\n\t\t\t\t3. Delete Homestay";
		cout << "\n\t\t\t\t4. View Homestay";
		cout << "\n\t\t\t\t5. Search Homestay";
		cout << "\n\t\t\t\t6. Back";

		cout << "\n\n\t\t\t\tEnter Your Choice: ";
		cin >> adminHChoice;

		switch (adminHChoice)
		{
			case 1:
				h_add(conn);
				break;
			case 2:
				h_update(conn, staffId);
				break;
			case 3:
				h_delete(conn);
				break;
			case 4:
				h_view(conn);
				break;
			case 5:
				HomestaySearch(conn, staffId);
				break;
			case 6:
				AdminMenu(conn, staffId);
				break;
			default:
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\tINVALID CHOICE.";
			}
		}
		cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
		_getch();
	}
}

void Header::h_add(MYSQL* conn)
{
	system("cls");

	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|         ADD HOMESTAY        |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|";

	cin.ignore();
	cout << "\n\n\t\t\tHomestay name: ";  getline(cin, homestayName);

	cout << "\t\t\tPrice: ";
	while (!(cin >> homestayPrice))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\tPrice: ";
	}

back2:
	int ShomestayType = 0;
	cout << "\t\t\tType(1=Single, 2=Couple, 3=Family): ", cin.ignore(), cin >> ShomestayType;
		if (ShomestayType == 1)
		{
			homestayType = "Single";
		}
		else if(ShomestayType == 2)
		{
			homestayType = "Couple";
		}
		else if(ShomestayType == 3)
		{
			homestayType = "Couple";
		}
		else
		{
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tInvalid answer. Try again\n";
			SetConsoleTextAttribute(color, 10);
			cin.clear();
			goto back2;
		}


	cout << "\t\t\tNumber of room: ";
	while (!(cin >> homestayNumOfRoom))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\tNumber of room : ";
	}


	cout << "\t\t\tNumber of bed: ";
	while (!(cin >> homestayNumOfBed))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Number of bed: ";
	}


	cout << "\t\t\tNumber of toilet: ";
	while (!(cin >> homestayNumOfToilet))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Number of toilet ";
	}

back6:
	cout << "\t\t\tPool [ Yes / No ] : ", getline(cin, homestayPool);
	if (homestayPool != "Yes" && homestayPool != "No")
	{
		cout << "homestayPool =" << homestayPool << endl;
		SetConsoleTextAttribute(color, 4);
		cout << "\tInvalid answer. Try again\n";
		SetConsoleTextAttribute(color, 10);

		goto back6;
	}

back7:
	cout << "\t\t\tAircond [ Yes / No ] : ", getline(cin, homestayAircond);
	if (homestayAircond != "Yes" && homestayAircond != "No")
	{
		cout << "homestayPool =" << homestayAircond << endl;

		SetConsoleTextAttribute(color, 4);
		cout << "\tInvalid answer. Try again\n";
		SetConsoleTextAttribute(color, 10);

		goto back7;
	}

	//Add homestay into database
	string insertHomestayData = "INSERT INTO homestay_record (H_Name, H_Price, H_Pool, H_Type, H_NumOfRoom, H_NumOfBed, H_NumOfToilet, H_Aircond) values ('" + homestayName + "','" + to_string(homestayPrice) + "','" + homestayPool + "','" + homestayType + "','" + to_string(homestayNumOfRoom) + "','" + to_string(homestayNumOfBed) + "','" + to_string(homestayNumOfToilet) + "','" + homestayAircond + "')";
	const char* ihd = insertHomestayData.c_str(); // c_str converts string to constant char and this is required

	qstate = mysql_query(conn, ihd);
	if (!qstate) {
		cout << endl << "\n\n\t\t\tSuccessfully added.\n\t\t\t";
		h_view(conn);
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tQuery Execution Problem!!! \n\t\t\t" << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 4);
	}
	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::h_update(MYSQL* conn, int staffId)
{
	//Database variable
	int qstate, input;
	char input2;

	int ShomestayType = 0;

AskAgain:
	system("cls");

	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|       UPDATE HOMESTAY       |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|\n";

	h_view(conn);

back:
	cout << "\n\t\t\tHomestay code: ";
	while (!(cin >> homestayId))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Homestay code: ";
	}
	
	AskBack:
		//cin.ignore();
	cout << "\n\t\t\tchoose which one you want to edit\n";
	cout << "\n\t\t\t1. Homestay name: ";
	cout << "\n\t\t\t2. Price: ";
	cout << "\n\t\t\t3. Pool: ";
	cout << "\n\t\t\t4. Type: ";
	cout << "\n\t\t\t5. Number of room: ";
	cout << "\n\t\t\t6. Number of bed: ";
	cout << "\n\t\t\t7. Number of toilet: ";
	cout << "\n\t\t\t8. Aircond: ";
	cout << "\n\t\t\t9. change All: ";
	cout << " \n\t\t\t10. Back: \n\n\t\t\tChoose number : ";
	cin >> input;

	switch (input)
	{
		
	case 1:
		cout << "\n\t\t\tHomestay name: "; cin.ignore(); getline(cin, homestayName);
		HomestayUpdateName(conn, homestayId, homestayName);
		break;

	case 2:
		cout << "\t\t\tPrice: ";
		while (!(cin >> homestayPrice))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Price: ";
		}

		HomestayUpdatePrice(conn, homestayId, homestayPrice);
		break;

	case 3:
		back2:
			cout << "\t\t\tPool [ Yes / No ]: ", cin.ignore(); getline(cin, homestayPool);
			if (homestayPool != "Yes" && homestayPool != "No")
			{
				cout << "homestayPool =" << homestayPool << endl;
				SetConsoleTextAttribute(color, 4);
				cout << "\tInvalid answer. Try again\n";
				SetConsoleTextAttribute(color, 4);
				goto back2;
			}
			
			HomestayUpdatePool(conn, homestayId, homestayPool);
			break;

	case 4:
		back3:
			cout << "\t\t\tType(1=Single, 2=Couple, 3=Family): ", cin >> ShomestayType;
			if (ShomestayType == 1)
			{
				homestayType = "Single";
			}
			else if (ShomestayType == 2)
			{
				homestayType = "Couple";
			}
			else if (ShomestayType == 3)
			{
				homestayType = "Couple";
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tInvalid answer. Try again\n";
				SetConsoleTextAttribute(color, 10);
				cin.clear();
				goto back3;
			}
			
			HomestayUpdateType(conn, homestayId, homestayType);
			break;
	case 5:
		cout << "\t\t\tNumber of room: ";
		while (!(cin >> homestayNumOfRoom))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Number of room: ";
		}

		HomestayUpdateNumOfRoom(conn, homestayId, homestayNumOfRoom);
		break;

	case 6:
		cout << "\t\t\tNumber of bed: ";
		while (!(cin >> homestayNumOfBed))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Number of bed: ";
		}

		HomestayUpdateNumOfBed(conn, homestayId, homestayNumOfBed);
		break;

	case 7:
		cout << "\t\t\tNumber of toilet: ";
		while (!(cin >> homestayNumOfToilet))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Number of toilet ";
		}

		HomestayUpdateNumOfToilet(conn, homestayId, homestayNumOfToilet);
		break;

	case 8:
	back7:
			cout << "\t\t\tAircond[ Yes / No ] : "; cin.ignore(); getline(cin, homestayAircond);
			if (homestayAircond != "Yes" && homestayAircond != "No")
			{
				cout << "homestayPool =" << homestayAircond << endl;
				SetConsoleTextAttribute(color, 4);
				cout << "\tInvalid answer. Try again\n";
				SetConsoleTextAttribute(color, 4);
				goto back7;
			}
			
			HomestayUpdateAircond(conn, homestayId, homestayAircond);
			break;

	case 9:
		HomestayUpdateAll(conn, homestayId);
		break;

	case 10:
		a_homestay(conn, staffId);
		break;

	default:
	{
		SetConsoleTextAttribute(color, 4);
		cout << "Invalid answer. \n";
		SetConsoleTextAttribute(color, 4);
		goto AskBack;
	}
		system("pause");
	}

	cout << "Press 1 to continue with the same item \nPress 2 to update other item or else to exit\n";
	cin >> input2;
	switch (input2) {
	case '1':
		goto AskBack;
		break;
	case '2':
		goto AskAgain;
		break;
	}
	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::h_delete(MYSQL* conn)
{
	int input;
	bool pass = true;
	MYSQL_RES* result2;
	MYSQL_ROW row2;

	system("cls");
	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|       DELETE HOMESTAY       |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|\n";

	h_view(conn);

	cout << "\n\n\t\t\t\tHomestay code: ";
	while (!(cin >> homestayId))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Homestay code: ";
	}

	SetConsoleTextAttribute(color, 4);
	cout << "\n\t\t\t\tAre you sure ? \n\t\t\t\tpress 1 to confirm, 0 to cancel : ";
	SetConsoleTextAttribute(color, 10);
	while (!(cin >> input))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Are you sure ? \n\t\t\t\tpress 1 to confirm, 0 to cancel : ";
	}

	if (input == 1)
	{
		string deleteHomestay = "DELETE FROM homestay_record WHERE HomestayID = '" + to_string(homestayId) + "'";
		const char* dh = deleteHomestay.c_str();
		qstate = mysql_query(conn, dh);

		string checkDeleteHomestay = "SELECT HomestayID FROM reservation_record WHERE HomestayID = '" + to_string(homestayId) + "'";
		const char* cdh = checkDeleteHomestay.c_str();
		int qstate2 = mysql_query(conn, cdh);

		if (!qstate2)
		{
			result2 = mysql_store_result(conn);
			while ((row2 = mysql_fetch_row(result2)))
			{
				if (row2[0] == to_string(homestayId))
				{
					pass = false;
					break;
				}
			}

			if (pass)
			{
				if (!qstate)
				{
					cout << "\n\n\t\t\t\tSuccessfully Deleted From Database.\n\n\t\t\t\t";
					system("pause");
					system("cls");
				}
				else
				{
					SetConsoleTextAttribute(color, 4);
					cout << "\n\n\t\t\t\tFailed To Delete!" << mysql_errno(conn) << endl;
					SetConsoleTextAttribute(color, 10);
				}
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\tCannot delete because customer has reserving the homestay. " << endl;
				SetConsoleTextAttribute(color, 10);
			}
		}
	}
	else
		a_homestay(conn, staffId);

	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
}

void Header::h_view(MYSQL* conn)
{
	system("cls");
	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|        VIEW HOMESTAY        |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|\n\n";

	// Retrieve data from database
	string displayAllHomestay = "SELECT * FROM homestay_record";
	const char* dah = displayAllHomestay.c_str();
	qstate = mysql_query(conn, dah);
	if (!qstate)
	{
		cout << center("\n  Homestay ID ", 12) << "|";
		cout << center("Name", 25) << "|";
		cout << center("Price", 10) << "|";
		cout << center("Pool", 8) << "|";
		cout << center("Type", 8) << "|";
		cout << center("Number of room", 15) << "|";
		cout << center("Number of bed", 14) << "|";
		cout << center("Number of toilet", 17) << "|";
		cout << center("Aircond", 8) << "|";
		cout <<"\n ==============================================================================================================================\n";
		result = mysql_store_result(conn);
		while ((row = mysql_fetch_row(result)))
		{
			cout <<"  "<< prd(row[0] , 12) << "|";
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
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 4);
	}
}

void Header::checkUserType(MYSQL *conn, int staffId)
{
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
				a_homestay(conn, staffId);

				mysql_free_result(result); //Clear result set from memory
				break;
			}
			else if (storeStaffId == to_string(staffId) && storeStaffPassword == staffPassword && storeType == "user")
			{
				r_MainMenu(conn, staffId);

				mysql_free_result(result); //Clear result set from memory
				break;
			}
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 4);
	}
		
}

void Header::HomestaySearch(MYSQL* conn, int staffId)
{
	int adminHChoice = 0;

	int ShomestayType = 0;

	AskBack:
	system("cls");

	cout << "\n\t\t\t\tYou want to search homestay by ? \n";
	cout << "\t\t\t\t1. ID\n";
	cout << "\t\t\t\t2. Name\n";
	cout << "\t\t\t\t3. Price\n";
	cout << "\t\t\t\t4. Pool\n";
	cout << "\t\t\t\t5. Type\n";
	cout << "\t\t\t\t6. Number of room\n";
	cout << "\t\t\t\t7. Number of bed\n";
	cout << "\t\t\t\t8. Number of toilet\n";
	cout << "\t\t\t\t9. Aircond\n";
	cout << "\t\t\t\t10. Back\n";

	cout << "\n\t\t\t\tEnter your choice: ";
	while (!(cin >> adminHChoice))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\t\t\Enter your choice: ";
	}

	switch (adminHChoice)
	{
	case 1:
		cout << "\t\t\t\tEnter Homestay Id : ";
		while (!(cin >> homestayId))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Homestay code: ";
		}

		SearchHomestayById(conn, homestayId);
		break;

	case 2:
		cout << "\t\t\t\tEnter Homestay Name : ";
		while (!(cin >> homestayName))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Homestay Name: ";
		}

		SearchHomestayByName(conn, homestayName);
		break;

	case 3:
		cout << "\t\t\t\tEnter Homestay Price: ";
		while (!(cin >> homestayPrice))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\n\t\t\Enter Homestay Price: ";
		}

		SearchHomestayByPrice(conn, homestayPrice);
		break;

	case 4:
		back4:
		cout << "\t\t\tPool [ Yes / No ]: ", cin.ignore(); getline(cin, homestayPool);
		if (homestayPool != "Yes" && homestayPool != "No")
		{
			cout << "homestayPool =" << homestayPool << endl;
			SetConsoleTextAttribute(color, 4);
			cout << "\tInvalid answer. Try again\n";
			SetConsoleTextAttribute(color, 4);
			goto back4;
		}

		SearchHomestayByPool(conn, homestayPool);
		break;

	case 5:
		back5:
		cout << "\t\t\tType(1=Single, 2=Couple, 3=Family): ", cin.ignore(), cin >> ShomestayType;
		if (ShomestayType == 1)
		{
			homestayType = "Single";
		}
		else if (ShomestayType == 2)
		{
			homestayType = "Couple";
		}
		else if (ShomestayType == 3)
		{
			homestayType = "Couple";
		}
		else
		{
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tInvalid answer. Try again\n";
			SetConsoleTextAttribute(color, 10);
			cin.clear();
			goto back5;
		}

		SearchHomestayByType(conn, homestayType);
		break;

	case 6:
		cout << "\t\t\t\tEnter Homestay Number of room : ";
		while (!(cin >> homestayNumOfRoom))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\t\t\t\tEnter Homestay Number of room : ";
		}

		SearchHomestayByNumOfRoom(conn, homestayNumOfRoom);
		break;

	case 7:
		cout << "\t\t\t\tEnter Homestay Number of bed : ";
		while (!(cin >> homestayNumOfBed))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\t\t\t\tEnter Homestay Number of bed : ";
		}

		SearchHomestayByNumOfBed(conn, homestayNumOfBed);
		break;

	case 8:
		cout << "\t\t\t\tEnter Homestay Number of toilet : ";
		while (!(cin >> homestayNumOfToilet))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\t\t\t\tEnter Homestay Number of toilet : ";
		}

		SearchHomestayByNumOfToilet(conn, homestayNumOfToilet);
		break;

	case 9:
		back9:
		cout << "\t\t\tAircond[ Yes / No ] : "; cin.ignore(); getline(cin, homestayAircond);
		if (homestayAircond != "Yes" && homestayAircond != "No")
		{
			cout << "homestayPool =" << homestayAircond << endl;
			SetConsoleTextAttribute(color, 4);
			cout << "\tInvalid answer. Try again\n";
			SetConsoleTextAttribute(color, 4);
			goto back9;
		}

		SearchHomestayByAircond(conn, staffAddress);
		break;

	case 10:
		checkUserType(conn, staffId);
		break;

	default:
	{
		SetConsoleTextAttribute(color, 4);
		cout << "\n\n\t\t\tINVALID CHOICE.";
		SetConsoleTextAttribute(color, 4);
		system("pause");
	}
	cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
	_getch();
	}
}