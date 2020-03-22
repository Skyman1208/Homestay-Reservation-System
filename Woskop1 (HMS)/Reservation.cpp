#include"Header.h"

void Header::r_MainMenu(MYSQL* conn, int staffId)
{
	int userChoice = 0;
	while (userChoice != 5)
	{
		system("cls");
		SetConsoleTextAttribute(color, 10);
		cout << "\n\t\t\t\t|*****************************|";
		cout << "\n\t\t\t\t| HOMESTAY RESERVATION SYSTEM |";
		cout << "\n\t\t\t\t|       | MAIN MENU |         |";
		cout << "\n\t\t\t\t|*****************************|";

		cout << "\n\n\n\t\t\t1. Reserve Homestay";
		cout << "\n\t\t\t2. Payment receipt";
		cout << "\n\t\t\t3. Reservation Record";
		cout << "\n\t\t\t4. Edit reservation";
		cout << "\n\t\t\t5. Search";
		cout << "\n\t\t\t6. Logout";

		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			r_checkIn(conn, staffId);
			break;
		case 2:
			r_receiptPayment(conn);
			break;
		case 3:
			r_view(conn);
			break;
		case 4:
			r_edit(conn, staffId);
			break;
		case 5:
			HomestaySearch(conn, staffId);
			break;
		case 6:
			Login(conn);
			break;

		default:
		{
			SetConsoleTextAttribute(color, 4);
			cout << "\n\n\t\t\tInvalid choice!";
			system("pause");
		}
		}

		cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
		_getch();
	}
}


void Header::r_checkIn(MYSQL* conn, int staffId)
{
	//Store variable
	bool isEmpty;

	SetConsoleTextAttribute(color, 10);
	system("cls");
	h_view(conn);
	
	cout << "Homestay ID: ";
	while (!(cin >> homestayId))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "Homestay ID: ";
	}

	cout << "\n\nCheck IN date:" << endl;
	cout << "Day (DD) : ";
	while (!(cin >> dayIn))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\nCheck IN date:";
	}

	cout << "Month (MM) : ";
	while (!(cin >> monthIn))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "Month (MM) : ";
	}

	cout << "Year (YYYY) : ";
	while (!(cin >> yearIn))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "Year (YYYY) : ";
	}

	cout << "\n\nCheck OUT date:" << endl;
	cout << "Day (DD) : ";
	while (!(cin >> dayOut))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "Day (DD) : ";
	}

	cout << "Month (MM) : ";
	while (!(cin >> monthOut))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "Month (MM) : ";
	}

	cout << "Year (YYYY) : ";
	while (!(cin >> yearOut))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "Year (YYYY) : ";
	}

	string dateIn = yearIn + "-" + monthIn + "-" + dayIn;
	cout << "\n\nCheck IN Date is " << dateIn;
	reservationCheckInDate = dateIn;

	string dateOut = yearOut + "-" + monthOut + "-" + dayOut;
	cout << "\nCheck OUT date is " << dateOut;
	reservationCheckOutDate = dateOut;

	int numOfDays = calculateDays(dayIn, monthIn, yearIn, dayOut, monthOut, yearOut);
	string SnumOfDays = to_string(numOfDays);

	// CHECK HOMESTAY AVAILABILITY
	string findHomestayIdById = "SELECT HomestayID,R_CheckInDate,R_CheckOutDate,Status FROM reservation_record WHERE HomestayID = '" + to_string(homestayId) + "'";
	const char* fhibi = findHomestayIdById.c_str();
	qstate = mysql_query(conn, fhibi);
	if (!qstate)
	{
		result = mysql_store_result(conn);
		while ((row = mysql_fetch_row(result)))
		{
			if (row[0] == to_string(homestayId))
			{
				storeHomestayId = row[0];
				storeReservationStatus = row[3];
				isEmpty = IsEmpty(dayIn, monthIn, yearIn, dayOut, monthOut, yearOut, row[1], row[2]);

				break;
			}
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "CHECK HOMESTAY AVAILABILITY <-- Query Execution Problem!" << mysql_errno(conn) << endl;
	}

		
	if (isEmpty)
	{
		cout << "\n\n\n\t\t\t\t|*****************************|";
		cout << "\n\t\t\t\t|     RESERVATION DETAILS     |";
		cout << "\n\t\t\t\t|                             |";
		cout << "\n\t\t\t\t|*****************************|";

		cout << "\n\n Name: ";
		getline(cin, custName);
		cout << " Address: ";
		getline(cin, custAddress);
		cout << " Phone No: ";
		getline(cin, custPhone);
		cout << " Email: ";
		getline(cin, custEmail);


		// INSERT CUSTOMER DETAILS
		string insertCustomerData = "INSERT INTO customer_record (C_Name, C_Address, C_PhoneNo, C_Email) values ('" + custName + "','" + custAddress + "', '" + custPhone + "','" + custEmail + "')";
		const char* icd = insertCustomerData.c_str(); // c_str converts string to constant char and this is required
		qstate = mysql_query(conn, icd);
		if (!qstate)
			cout << endl << "Successfully added CUSTOMER DETAILS in database." << endl;
		else
			SetConsoleTextAttribute(color, 4); cout << "INSERT CUSTOMER DETAILS <-- Query Execution Problem!" << mysql_errno(conn) << endl;

		// FIND HOMESTAY ID
		string findHomestayIdById2 = "SELECT * FROM homestay_record WHERE HomestayID LIKE '" + to_string(homestayId) + "%'";
		const char* fhibi2 = findHomestayIdById2.c_str();
		qstate = mysql_query(conn, fhibi2);
		if (!qstate)
		{
			result = mysql_store_result(conn);
			while ((row = mysql_fetch_row(result)))
			{
				storeHomestayId = row[0];

				if (storeHomestayId == to_string(homestayId))
				{
					storeHomestayId = storeHomestayId;
					storeHomestayPrice = row[2];

					mysql_free_result(result); //Clear result set from memory
					break;
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(color, 4);
			cout << "FIND HOMESTAY ID <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		}

		// FIND CUSTOMER ID BY NAME
		string findCustomerIdByName = "SELECT * FROM customer_record WHERE C_Name LIKE '" + custName + "%'";
		const char* fcibn = findCustomerIdByName.c_str();
		qstate = mysql_query(conn, fcibn);
		if (!qstate)
		{
			result = mysql_store_result(conn);
			while ((row = mysql_fetch_row(result)))
			{
				storeCustId = row[0];
				storeCustName = row[1];

				if (storeCustName == custName)
				{
					storeCustId = storeCustId;
					isEmpty = true;

					mysql_free_result(result); //Clear result set from memory
					break;
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(color, 4);
			cout << "FIND CUSTOMER ID BY NAME <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		}

		string insertReservation = "INSERT INTO reservation_record (HomestayID, StaffID, CustomerID, R_CheckInDate, R_CheckOutDate, Status) values ('" + storeHomestayId + "','" + to_string(staffId) + "','" + storeCustId + "','" + reservationCheckInDate + "', '" + reservationCheckOutDate + "', 'RESERVED')";
		const char* ir = insertReservation.c_str(); // c_str converts string to constant char and this is required
		qstate = mysql_query(conn, ir);
		if (!qstate)
			cout << endl << "Successfully added RESERVATION DETAILS in database." << endl;
		else
			SetConsoleTextAttribute(color, 4); cout << "RESERVATION <-- Query Execution Problem!" << mysql_errno(conn) << endl;


		// FIND RESERVATION ID, CALCULATE CHARGE & INSERT INTO BILL RECORD
		string findReservationId = "SELECT * FROM reservation_record ORDER BY ReservationID DESC LIMIT 1";
		const char* fri = findReservationId.c_str();
		qstate = mysql_query(conn, fri);
		if (!qstate)
		{
			result = mysql_store_result(conn);
			while ((row = mysql_fetch_row(result)))
			{
				// Get RESERVATION ID
				storeReservationId = row[0];

				// Calculate charge
				DhomestayPrice = stof(storeHomestayPrice);
				totalCharge = DhomestayPrice * numOfDays;

				// Convert DATA TYPE to string
				StotalCharge = to_string(totalCharge);

				string insertBillRecord = "INSERT INTO bill_record (ReservationID, B_Charge, B_NumOfDays) values ('" + storeReservationId + "','" + StotalCharge + "','" + SnumOfDays + "')";
				const char* ibr = insertBillRecord.c_str(); // c_str converts string to constant char and this is required
				qstate = mysql_query(conn, ibr);
				if (!qstate)
					cout << endl << "Successfully added BILL RECORD in database." << endl;
				else
					SetConsoleTextAttribute(color, 4); cout << "INSERT BILL RECORD <-- Query Execution Problem!" << mysql_errno(conn) << endl;
			}
		}
		else
		{
			SetConsoleTextAttribute(color, 4);
			cout << "\n\nFIND RESERVATION ID <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "\n\nHomestay is already RESERVED." << endl;
	}
}


void Header::r_receiptPayment(MYSQL* conn)
{
	system("cls");
	SetConsoleTextAttribute(color, 10);

	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|        PAYMENT RECEIPT      |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|";

back:
	cout << "\n\nHomestay ID: ";
	if (!(cin >> homestayId))
		SetConsoleTextAttribute(color, 4); cout << "That's not a number; "; SetConsoleTextAttribute(color, 10); goto back;

	// FIND RESERVATION ID BY HOMESTAY ID
	string findReservationIdByHomestayId = "SELECT * FROM reservation_record WHERE HomestayID LIKE '" + to_string(homestayId) + "%'";
	const char* fribhi = findReservationIdByHomestayId.c_str();
	qstate = mysql_query(conn, fribhi);
	if (!qstate)
	{
		result = mysql_store_result(conn);
		while ((row = mysql_fetch_row(result)))
		{
			if (row[1] == to_string(homestayId))
			{
				storeReservationId = row[0];

				// DIPSLAY PAYMENT RECEIPT
				string displayPaymentReceipt = "SELECT * FROM bill_record WHERE ReservationID LIKE '" + storeReservationId + "%'";
				const char* dpr = displayPaymentReceipt.c_str();
				qstate = mysql_query(conn, dpr);
				if (!qstate)
				{
					result = mysql_store_result(conn);
					row = mysql_fetch_row(result);
							
					cout << "\n\n\nBill ID: " << row[0] << endl;
					cout << "Reservation ID: " << row[1] << endl;
					cout << "Total charge: " << row[2] << endl;
					cout << "Number of day/s: " << row[3] << "\n\n";

					mysql_free_result(result); //Clear result set from memory
					break;
				}
				else
				{
					SetConsoleTextAttribute(color, 4);
					cout << "DIPSLAY PAYMENT RECEIPT <-- Query Execution Problem! " << mysql_errno(conn) << endl;
					SetConsoleTextAttribute(color, 10);
				}
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\tSorry, not found."<<endl;
				SetConsoleTextAttribute(color, 10);
			}
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "FIND RESERVATION ID BY HOMESTAY ID <-- Query Execution Problem! " << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 10);
	}
}


void Header::r_edit(MYSQL* conn, int staffId)
{
	bool isValid = false;
	SetConsoleTextAttribute(color, 10);
	system("cls");

	r_view(conn);

	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|      UPDATE RESERVATION     |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|";


	cout << "\n\n\t\t\tReservation ID: ";
	while (!(cin >> reservationId))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\n\n\t\t\tReservation ID: ";
	}

	cout << "\t\t\tHomestay ID: ";
	while (!(cin >> homestayId))
	{
		cin.clear();
		cin.ignore(999, '\n');
		SetConsoleTextAttribute(color, 4);
		cout << "\t\t\tThat's not a number; ";
		SetConsoleTextAttribute(color, 10);

		cout << "\t\t\tHomestay ID: ";
	}


	string query = "SELECT * FROM homestay_record WHERE HomestayID LIKE '%" + to_string(homestayId) + "%'";
	const char* check = query.c_str();
	qstate = mysql_query(conn, check);
	result = mysql_store_result(conn);
	if (!qstate)
	{
		while ((row = mysql_fetch_row(result)))
		{
			if (row[0] == to_string(homestayId))
			{
				storeHomestayPrice = row[2];
				isValid = true;

				mysql_free_result(result); //Clear result set from memory
				break;
			}
		}
	}
	
	if (isValid)
	{
		cout << "\t\t\tCustomer ID (Please enter customer ID to update): ";
		while (!(cin >> homestayId))
		{
			cin.clear();
			cin.ignore(999, '\n');
			SetConsoleTextAttribute(color, 4);
			cout << "\t\t\tThat's not a number; ";
			SetConsoleTextAttribute(color, 10);

			cout << "\t\t\tCustomer ID (Please enter customer ID to update): ";
		}

		if (custId == 0)
		{
			cout << "\n\nCheck IN date:" << endl;
			cout << "Day (DD) : ";
			while (!(cin >> dayIn))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "\n\nCheck IN date:";
			}

			cout << "Month (MM) : ";
			while (!(cin >> monthIn))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "Month (MM) : ";
			}

			cout << "Year (YYYY) : ";
			while (!(cin >> yearIn))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "Year (YYYY) : ";
			}

			cout << "\n\nCheck OUT date:" << endl;
			cout << "Day (DD) : ";
			while (!(cin >> dayOut))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "Day (DD) : ";
			}

			cout << "Month (MM) : ";
			while (!(cin >> monthOut))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "Month (MM) : ";
			}

			cout << "Year (YYYY) : ";
			while (!(cin >> yearOut))
			{
				cin.clear();
				cin.ignore(999, '\n');
				SetConsoleTextAttribute(color, 4);
				cout << "\t\t\tThat's not a number; ";
				SetConsoleTextAttribute(color, 10);

				cout << "Year (YYYY) : ";
			}

			string dateIn = yearIn + "-" + monthIn + "-" + dayIn;
			cout << "\n\nCheck IN Date is " << dateIn;
			reservationCheckInDate = dateIn;

			string dateOut = yearOut + "-" + monthOut + "-" + dayOut;
			cout << "\nCheck OUT date is " << dateOut;
			reservationCheckOutDate = dateOut;

			int numOfDays = calculateDays(dayIn, monthIn, yearIn, dayOut, monthOut, yearOut);
			string SnumOfDays = to_string(numOfDays);

			// Calculate charge
			DhomestayPrice = stof(storeHomestayPrice);
			totalCharge = DhomestayPrice * numOfDays;

			// Convert DATA TYPE to string
			StotalCharge = to_string(totalCharge);

			cout << "\t\t\tStatus: ", getline(cin, reservationStatus);

			string updateHomestayData = "UPDATE reservation_record SET HomestayID = '" + to_string(homestayId) + "', StaffID = '" + to_string(staffId) + "', R_CheckInDate = '" + reservationCheckInDate + "', R_CheckOutDate = '" + reservationCheckOutDate + "', Status = '" + reservationStatus + "' WHERE ReservationID = '" + to_string(reservationId) + "'";
			const char* uhd = updateHomestayData.c_str();
			qstate = mysql_query(conn, uhd);
			if (!qstate)
				cout << endl << "\n\n\t\t\tSuccessfully updated RESERVATION DETIALS in database." << endl;
			else
				SetConsoleTextAttribute(color, 4); cout << "Failed to update RESERVATION DETAILS. " << mysql_errno(conn) << endl;


			//UPDATE BILL RECORD
			string updateBillRecord = "UPDATE bill_record SET B_Charge = '" + StotalCharge + "', B_NumOfDays = '" + SnumOfDays + "' WHERE ReservationID = '" + to_string(reservationId) + "'";
			const char* ubr = updateBillRecord.c_str(); // c_str converts string to constant char and this is required
			qstate = mysql_query(conn, ubr);
			if (!qstate)
				cout << endl << "Successfully updated BILL RECORD in database." << endl;
			else
				SetConsoleTextAttribute(color, 4); cout << "UPDATE BILL RECORD <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		}
		else
		{
			isValid = false;

			string query = "SELECT * FROM customer_record WHERE CustomerID LIKE '%" + to_string(custId) + "%'";
			const char* check = query.c_str();
			qstate = mysql_query(conn, check);
			result = mysql_store_result(conn);
			if (!qstate)
			{
				while ((row = mysql_fetch_row(result)))
				{
					if (row[0] == to_string(custId))
					{
						isValid = true;

						mysql_free_result(result); //Clear result set from memory
						break;
					}
				}
			}

			if (isValid)
			{
				Header::c_update(conn, to_string(custId));

				//UPDATE DATE
				cout << "\n\nCheck IN date:" << endl;
				cout << "Day (DD) : ";
				while (!(cin >> dayIn))
				{
					cin.clear();
					cin.ignore(999, '\n');
					SetConsoleTextAttribute(color, 4);
					cout << "\t\t\tThat's not a number; ";
					SetConsoleTextAttribute(color, 10);

					cout << "\n\nCheck IN date:";
				}

				cout << "Month (MM) : ";
				while (!(cin >> monthIn))
				{
					cin.clear();
					cin.ignore(999, '\n');
					SetConsoleTextAttribute(color, 4);
					cout << "\t\t\tThat's not a number; ";
					SetConsoleTextAttribute(color, 10);

					cout << "Month (MM) : ";
				}

				cout << "Year (YYYY) : ";
				while (!(cin >> yearIn))
				{
					cin.clear();
					cin.ignore(999, '\n');
					SetConsoleTextAttribute(color, 4);
					cout << "\t\t\tThat's not a number; ";
					SetConsoleTextAttribute(color, 10);

					cout << "Year (YYYY) : ";
				}

				cout << "\n\nCheck OUT date:" << endl;
				cout << "Day (DD) : ";
				while (!(cin >> dayOut))
				{
					cin.clear();
					cin.ignore(999, '\n');
					SetConsoleTextAttribute(color, 4);
					cout << "\t\t\tThat's not a number; ";
					SetConsoleTextAttribute(color, 10);

					cout << "Day (DD) : ";
				}

				cout << "Month (MM) : ";
				while (!(cin >> monthOut))
				{
					cin.clear();
					cin.ignore(999, '\n');
					SetConsoleTextAttribute(color, 4);
					cout << "\t\t\tThat's not a number; ";
					SetConsoleTextAttribute(color, 10);

					cout << "Month (MM) : ";
				}

				cout << "Year (YYYY) : ";
				while (!(cin >> yearOut))
				{
					cin.clear();
					cin.ignore(999, '\n');
					SetConsoleTextAttribute(color, 4);
					cout << "\t\t\tThat's not a number; ";
					SetConsoleTextAttribute(color, 10);

					cout << "Year (YYYY) : ";
				}

				string dateIn = yearIn + "-" + monthIn + "-" + dayIn;
				cout << "\n\nCheck IN Date is " << dateIn;
				reservationCheckInDate = dateIn;

				string dateOut = yearOut + "-" + monthOut + "-" + dayOut;
				cout << "\nCheck OUT date is " << dateOut;
				reservationCheckOutDate = dateOut;

				int numOfDays = 0;
				numOfDays = calculateDays(dayIn, monthIn, yearIn, dayOut, monthOut, yearOut);
				string SnumOfDays = "";
				SnumOfDays = to_string(numOfDays);

				// Calculate charge
				DhomestayPrice = stof(storeHomestayPrice);
				totalCharge = DhomestayPrice * numOfDays;

				// Convert DATA TYPE to string
				StotalCharge = to_string(totalCharge);

				cout << "\n\n\n\t\t\tStatus [ RESERVED / CHECKOUT ]: ", getline(cin, reservationStatus);

				string updateHomestayData = "UPDATE reservation_record SET HomestayID = '" + to_string(homestayId) + "', StaffID = '" + to_string(staffId) + "', R_CheckInDate = '" + reservationCheckInDate + "', R_CheckOutDate = '" + reservationCheckOutDate + "', Status = '" + reservationStatus + "' WHERE ReservationID = '" + to_string(reservationId) + "'";
				const char* uhd = updateHomestayData.c_str();
				qstate = mysql_query(conn, uhd);
				if (!qstate)
					cout << endl << "\n\nSuccessfully updated RESERVATION DETIALS in database." << endl;
				else
					SetConsoleTextAttribute(color, 4); cout << "Failed to update RESERVATION DETAILS. " << mysql_errno(conn) << endl;


				//UPDATE BILL RECORD
				string updateBillRecord = "UPDATE bill_record SET B_Charge = '" + StotalCharge + "', B_NumOfDays = '" + SnumOfDays + "' WHERE ReservationID = '" + to_string(reservationId) + "'";
				const char* ubr = updateBillRecord.c_str(); // c_str converts string to constant char and this is required
				qstate = mysql_query(conn, ubr);
				if (!qstate)
					cout << endl << "Successfully updated BILL RECORD in database." << endl;
				else
					SetConsoleTextAttribute(color, 4); cout << "UPDATE BILL RECORD <-- Query Execution Problem!" << mysql_errno(conn) << endl;
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << " Sorry, data not found. " << endl;
			}
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << " Sorry, data not found. " << endl;
	}
}


void Header::r_view(MYSQL* conn)
{
	system("cls");
	SetConsoleTextAttribute(color, 10);
	cout << "\n\t\t\t\t|*****************************|";
	cout << "\n\t\t\t\t|      VIEW RESERVATION       |";
	cout << "\n\t\t\t\t|                             |";
	cout << "\n\t\t\t\t|*****************************|\n\n";

	string displayAllReservation = "SELECT * FROM reservation_record";
	const char* dar = displayAllReservation.c_str();
	qstate = mysql_query(conn, dar);
	if (!qstate)
	{
		cout << center("\n    Reservation ID ", 22) << "|";
		cout << center("Homestay ID", 18) << "|";
		cout << center("Staff ID", 18) << "|";
		cout << center("Customer ID", 18) << "|";
		cout << center("Check in date", 20) << "|";
		cout << center("Check out date", 20) << "|";
		cout << center("Status", 15) << "|";
		cout << "\n =======================================================================================================================================\n";

		result = mysql_store_result(conn);
		while ((row = mysql_fetch_row(result)))
		{
			cout << "  " << prd(row[0], 18) << "|";
			cout << prd(row[1], 18) << "|";
			cout << prd(row[2], 18) << "|";
			cout << prd(row[3], 18) << "|";
			cout << prd(row[4], 20) << "|";
			cout << prd(row[5], 20) << "|";
			cout << prd(row[6], 15) << "|";
			cout << "\n";
		}
		cout << "\n\n\n";
		mysql_free_result(result); //Clear result set from memory
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "DISPLAY ALL RESERVATION <-- Query Execution Problem!" << mysql_errno(conn) << endl;
	}
}


void Header::r_search(MYSQL* conn, int  reservationId) 
{
	string query = "SELECT * FROM reservation_record WHERE ReservationID = '" + to_string(reservationId) + "'";
	const char* check = query.c_str();
	mysql_query(conn, check);
	result = mysql_store_result(conn);

	int num_fields = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result)))
	{
		// Print all columns
		for (int i = 0; i < num_fields; i++)
		{
			// Make sure row[i] is valid!
			if (row[i] != NULL)
				cout << row[i] << endl;
			else
				cout << "NULL" << endl;

			// Also, you can use ternary operator here instead of if-else
			// cout << row[i] ? row[i] : "NULL" << endl;
		}
	}
}