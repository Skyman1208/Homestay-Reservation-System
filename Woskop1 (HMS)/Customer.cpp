#include"Header.h"

void Header::c_update(MYSQL *conn, string custId)
{
	/*
		// FIND CUSTOMER ID BY NAME
		string findCustomerIdByName = "SELECT * FROM customer_record WHERE CustomerID LIKE '" + custId + "%'";
		const char* fcibn = findCustomerIdByName.c_str();
		qstate = mysql_query(conn, fcibn);
		if (!qstate)
		{
			result = mysql_store_result(conn);
			while ((row = mysql_fetch_row(result)))
			{
				storeCustId = row[0];

				if (storeCustId == custId)
				{
					storeCustId = storeCustId;

					mysql_free_result(result); //Clear result set from memory
					break;
				}
			}
		}
		else
		{
			cout << "FIND CUSTOMER ID BY NAME <-- Query Execution Problem!" << mysql_errno(conn) << endl;
		}
		*/

	string displayCustomerDetails = "SELECT * FROM customer_record WHERE CustomerID = '" + custId + "'";
	const char* dcd = displayCustomerDetails.c_str();
	qstate = mysql_query(conn, dcd);
	if (!qstate)
	{
		cout << center("\n\n\n\n     Customer ID     ", 22) << "|";
		cout << center("Name", 40) << "|";
		cout << center("Address", 60) << "|";
		cout << center("Phone No.", 30) << "|";
		cout << center("Email", 35) << "|";
		cout << "\n ==============================================================================================================================================================================================\n";

		result = mysql_store_result(conn);
		while ((row = mysql_fetch_row(result)))
		{
			cout << "  " << prd(row[0], 19) << "|";
			cout << prd(row[1], 40) << "|";
			cout << prd(row[2], 60) << "|";
			cout << prd(row[3], 30) << "|";
			cout << prd(row[4], 35) << "|";
			cout << "\n";
		}
		cout << "\n\n\n";
		mysql_free_result(result); //Clear result set from memory
	}
	else
	{
		cout << "DISPLAY ALL RESERVATION <-- Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	cout << " Name: ", getline(cin, custName);
	cout << " Address: ", getline(cin, custAddress);
	cout << " Phone No: ", getline(cin, custPhone);
	cout << " Email: ", getline(cin, custEmail);

	//UPDATE CUSTOMER DETAILS
	string updateCustomerData = "UPDATE customer_record SET C_Name = '" + custName + "', C_Address = '" + custAddress + "', C_PhoneNo = '" + custPhone + "', C_Email = '" + custEmail + "' WHERE CustomerID = '" + custId + "'";
	const char* ucd = updateCustomerData.c_str(); // c_str converts string to constant char and this is required
	qstate = mysql_query(conn, ucd);
	if (!qstate)
		cout << endl << "Successfully updated CUSTOMER DETAILS in database." << endl;
	else
		cout << "UPDATE CUSTOMER DETAILS <-- Query Execution Problem! " << mysql_errno(conn) << endl;
}

