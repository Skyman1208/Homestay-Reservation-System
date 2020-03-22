#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"

void Header::a_report(MYSQL* conn, int staffId)
{
	int adminRChoice = 0;
	while (adminRChoice != 3)
	{
		system("cls");
		SetConsoleTextAttribute(color, 10);
		cout << "\n\t\t\t\t|*****************************|";
		cout << "\n\t\t\t\t|            REPORT           |";
		cout << "\n\t\t\t\t|                             |";
		cout << "\n\t\t\t\t|*****************************|";

		cout << "\n\n\n\t\t\t1. Report by month";
		cout << "\n\t\t\t2. Report by homestay";
		cout << "\n\t\t\t3. Back";

		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> adminRChoice;

		switch (adminRChoice)
		{
		case 1:
			reportByMonth(conn);
			break;
		case 2:
			reportByHomestay(conn);
			break;
		case 3:
			AdminMenu(conn, staffId);
			break;

		default:
		{
			SetConsoleTextAttribute(color, 4);
			cout << "\n\n\t\t\tInvalid choice!";
		}
		}

		cout << "\n\n\n   PRESS ANY KEY TO CONTINUE.....\n\n";
		_getch();
	}
}


void Header::reportByMonth(MYSQL *conn)
{
	int yearArry[500];
	float priceEachMonthNTotalAmountArry[500][12];

	string calculateForReportByMonthViaReservationId = "SELECT * FROM reservation_record";
	const char* cfrbmvri = calculateForReportByMonthViaReservationId.c_str();
	qstate = mysql_query(conn, cfrbmvri);
	if (!qstate)
	{
		system("cls");

		cout << center("\n\n\n    YEAR", 15) << "|";
		cout << center("Jan", 15) << "|";
		cout << center("Feb", 15) << "|";
		cout << center("Mar", 15) << "|";
		cout << center("Apr", 15) << "|";
		cout << center("May", 15) << "|";
		cout << center("Jun", 15) << "|";
		cout << center("July", 15) << "|";
		cout << center("Aug", 15) << "|";
		cout << center("Sept", 15) << "|";
		cout << center("Oct", 15) << "|";
		cout << center("Nov", 15) << "|";
		cout << center("Dis", 15) << "|";
		cout << "\n ==========================================================================================================================================================================================================\n";

		// Initialize all to 0.00
		for (int y = 0; y < 500; y++)
		{
			yearArry[y] = 0;
			for (int m=0; m<12; m++)
			{
				priceEachMonthNTotalAmountArry[y][m] = 0.00;
			}
		}

		result = mysql_store_result(conn);
		while ((row = mysql_fetch_row(result)))
		{
			//ReservationID
			storeReservationId = row[0];

			int qstate2;
			string findChargeByReservationId = "SELECT * FROM bill_record";
			const char* fcbri = findChargeByReservationId.c_str();
			qstate2 = mysql_query(conn, fcbri);
			if (!qstate2)
			{
				MYSQL_ROW row2;
				MYSQL_RES* result2;
				result2 = mysql_store_result(conn);
				while ((row2 = mysql_fetch_row(result2)))
				{
					if (row2[1] == storeReservationId)
					{
						storeBillCharge = row2[2];

						mysql_free_result(result2); //Clear result set from memory
						break;
					}
				}
			}
			else
			{
				SetConsoleTextAttribute(color, 4);
				cout << "FIND CHARGE IN BILL RECORD BY RESERVATION ID <-- Query Execution Problem!" << mysql_errno(conn) << endl;
			}

			//Check in date
			string checkInDate = row[4];
			char date[11];

			strcpy(date, checkInDate.c_str());
			int month = stoi(string(1, date[5]) + date[6]);
			int year = stoi(string(1, date[0]) + date[1] + date[2] + date[3]);

			//cout << month << "  " << year;

			// Search position to insert value
			for (int y=0; y<500; y++)
			{
				if (yearArry[y] == year)
				{
					for (int m=0; m<12; m++)
					{
						int mNew = m + 1;
						if (mNew == month)
						{
							priceEachMonthNTotalAmountArry[y][m] = priceEachMonthNTotalAmountArry[y][m] + stof(storeBillCharge);
							break;
						}
					}
					break;
				}
				else if (yearArry[y] == 0)
				{
					yearArry[y] = year;

					for (int m = 0; m < 12; m++)
					{
						int mNew = m + 1;
						if (mNew == month)
						{
							priceEachMonthNTotalAmountArry[y][m] = stof(storeBillCharge);
							break;
						}
					}
					break;
				}
			}
		}

		//mysql_free_result(result); //Clear result set from memory

		// Display result
		for (int y = 0; y < 500; y++)
		{
			if (yearArry[y] != 0)
			{
				string SYear = to_string(yearArry[y]);
				cout << "   " << prd(SYear, 7) << "|";
				for (int m = 0; m < 12; m++)
				{
					string SMonth = to_string(priceEachMonthNTotalAmountArry[y][m]);
					cout << prd(SMonth, 15) << "|";
					//cout << "\t";
				}
				cout << "\n\n";
			}
		}

		cout << "\n\n\n";
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "DISPLAY REPORT BY MONTH <-- Query Execution Problem!" << mysql_errno(conn) << endl;
	}
}

void Header::reportByHomestay(MYSQL *conn)
{
	float totalAmountPerHomestayArry[500];
	int homestayIdNFreqArry[500][2];
	string homestayName[500];
	int homestayId[500];

	system("cls");

	cout << center("\n\n\n                    HOMESTAY     ", 60) << "|";
	cout << center("Reserve freq.", 20) << "|";
	cout << center("Total amount (RM)", 20) << "|";
	cout << "\n =======================================================================================\n";


	// Initialize all to 0.00
	for (int i = 0; i < 500; i++)
	{
		homestayId[i] = 0;
		homestayName[i] = "";
		totalAmountPerHomestayArry[i] = 0.00;
		for (int j = 0; j < 2; j++)
			homestayIdNFreqArry[i][j] = 0;
	}

	string getHomestayName = "SELECT HomestayID, H_Name FROM homestay_record";
	const char* ghn = getHomestayName.c_str();
	qstate = mysql_query(conn, ghn);
	if (!qstate)
	{
		result = mysql_store_result(conn);
		int i = 0;
		while ((row = mysql_fetch_row(result)))
		{
			storeHomestayId = row[0];
			storeHomestayName = row[1];

			if (homestayId[i] == 0)
			{
				homestayId[i] = stoi(storeHomestayId);
				homestayName[i] = storeHomestayName;
			}

			i++;
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "GET HOMESTAY ID AND NAME <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 10);
	}
	
	string getHomestayIdFrequencyTotalAmount = "SELECT HomestayID, COUNT(*) AS Frequency, SUM(B_Charge) AS TOTAL_AMOUNT FROM bill_record INNER JOIN reservation_record USING (ReservationID) GROUP BY HomestayID";
	const char* ghinfta = getHomestayIdFrequencyTotalAmount.c_str();
	qstate = mysql_query(conn, ghinfta);
	if (!qstate)
	{
		result = mysql_store_result(conn);
		int i = 0;
		while ((row = mysql_fetch_row(result)))
		{
			storeHomestayId = row[0];
			string freq = row[1];

			if (homestayIdNFreqArry[i][0] == 0)
			{
				totalAmountPerHomestayArry[i] = stof(row[2]);
				for (int j = 0; j < 2; j++)
				{
					if (j == 0)
						homestayIdNFreqArry[i][j] = stoi(storeHomestayId);
					else if (j == 1)
						homestayIdNFreqArry[i][j] = stoi(freq);
				}
			}

			i++;
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 4);
		cout << "GET HOMESTAY ID AND FREQUENCY <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		SetConsoleTextAttribute(color, 10);
	}

	string hn = "";
	for (int i = 0; i < 500; i++)
	{
		if (homestayIdNFreqArry[i][0] != 0)
		{
			int h = homestayIdNFreqArry[i][0];
			int f = homestayIdNFreqArry[i][1];
			float ta = totalAmountPerHomestayArry[i];

			for (int f = 0; f < 500; f++)
			{
				if (homestayId[i] == h)
				{
					hn = homestayName[i];
					break;
				}
			}

			cout << prd(hn, 45) << "|";
			cout << prd(to_string(f), 20) << "|";
			cout << prd(to_string(ta), 20) << "|";
			cout << endl;
		}
	}
}