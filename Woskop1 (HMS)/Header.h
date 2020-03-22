#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include<windows.h>
#include<mysql.h>
#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<cctype>
#include<limits>
#include<algorithm> 
using namespace std;

class Header 
{

public:

	//==========================Output design==========================
	const char sepatator = ' ';
	string center(const string s, const int w) 
	{
		stringstream ss, spaces;
		const int padding = w - s.size();
		for (int i = 0; i < padding / 2; ++i)
			spaces << " ";
		ss << spaces.str() << s << spaces.str();    // format with padding
		if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
			ss << " ";
		return ss.str();
	}

	string prd(const string s, const int w) 
	{
		stringstream ss, spaces;
		const int padding = w - s.size();
		for (int i = 0; i < padding / 2; ++i)
			spaces << " ";
		ss << left<< s << spaces.str() <<spaces.str();    // format with padding
		if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
			ss << " ";
		return ss.str();
	}

	//==========================CUSTOMER==========================
	void c_update(MYSQL *conn, string custId);

	//Declare Customer Variable
	int custId = 0;
	string custName = "";
	string custAddress = "";
	string custPhone = "";
	string custEmail = "";

	//Declare Store Variable For Customer
	string storeCustId = "";
	string storeCustName = "";
	string storeCustAddress = "";
	string storeCustPhone = "";
	string storeCustEmail = "";

	//==========================RESERVATION==========================
	void r_checkIn(MYSQL* conn, int staffId);
	void r_receiptPayment(MYSQL* conn);
	void r_edit(MYSQL* conn, int staffId);
	void r_view(MYSQL* conn);
	void r_search(MYSQL* conn, int reservationId);

	//Declare Reservation Variable
	int reservationId = 0;
	string reservationCheckInDate = "";
	string reservationCheckOutDate = "";
	string reservationStatus = "";
	double totalCharge = 0.00;

	//Declare Store Variable For Reservation
	string storeReservationId = "";
	string storeReservationStatus = "";

	//==========================HOMESTAY==========================
	void h_add(MYSQL* conn);
	void h_update(MYSQL* conn, int staffId);
	void h_delete(MYSQL* conn);
	void h_view(MYSQL* conn);
	void HomestaySearch(MYSQL* conn, int staffId);

	void SearchHomestayById(MYSQL* conn, int homestayId);
	void SearchHomestayByName(MYSQL* conn, string homestayName);
	void SearchHomestayByPrice(MYSQL* conn, double homestayPrice);
	void SearchHomestayByPool(MYSQL* conn, string homestayPool);
	void SearchHomestayByType(MYSQL* conn, string homestayType);
	void SearchHomestayByNumOfRoom(MYSQL* conn, int homestayNumOfRoom);
	void SearchHomestayByNumOfBed(MYSQL* conn, int homestayNumOfBed);
	void SearchHomestayByNumOfToilet(MYSQL* conn, int homestayNumOfToilet);
	void SearchHomestayByAircond(MYSQL* conn, string homestayAircond);

	void HomestayUpdateName(MYSQL* conn, int homestayId, string homestayName);
	void HomestayUpdatePrice(MYSQL* conn, int homestayId, double homestayPrice);
	void HomestayUpdatePool(MYSQL* conn, int homestayId, string homestayPool);
	void HomestayUpdateType(MYSQL* conn, int homestayId, string homestayType);
	void HomestayUpdateNumOfRoom(MYSQL* conn, int homestayId, int homestayNumOfRoom);
	void HomestayUpdateNumOfBed(MYSQL* conn, int homestayId, int homestayNumOfBed);
	void HomestayUpdateNumOfToilet(MYSQL* conn, int homestayId, int homestayNumOfToilet);
	void HomestayUpdateAircond(MYSQL* conn, int homestayId, string homestayAircond);
	void HomestayUpdateAll(MYSQL* conn, int homestayId);

	//Declare Homestay Variable
	int homestayId = 0;
	string homestayName = "";
	double homestayPrice = 0.00;
	string homestayPool = "";
	string homestayType = "";
	int homestayNumOfRoom = 0;
	int homestayNumOfBed = 0;
	int homestayNumOfToilet = 0;
	string homestayAircond = "";
	string StotalCharge = "0.00";
	double DhomestayPrice = 0.00;

	//Declare Store Variable For Homestay
	string storeHomestayId = "";
	string storeHomestayName = "";
	string storeHomestayPrice = "";
	string storeHomestayPool = "";
	string storeHomestayType = "";
	string storeHomestayNumOfRoom = "";
	string storeHomestayNumOfBed = "";
	string storeHomestayNumOfToilet = "";
	string storeHomestayAircond = "";

	//==========================STAFF==========================
	void StaffUpdate(MYSQL* conn);
	void StaffDelete(MYSQL* conn);
	void StaffView(MYSQL* conn);
	void StaffSearch(MYSQL* conn);

	void SearchStaffById(MYSQL* conn, int staffId);
	void SearchStaffByName(MYSQL* conn, string staffName);
	void SearchStaffByPhone(MYSQL* conn, string staffPhoneNo);
	void SearchStaffByEmail(MYSQL* conn, string staffEmail);
	void SearchStaffByAddress(MYSQL* conn, string staffAddress);

	void checkUserType(MYSQL *conn, int staffId);

	//Declare Staff Variable
	int staffId = 0;
	string staffName = "";
	string staffPhoneNo = "";
	string staffPassword = "";
	string staffType = "";
	string staffEmail = "";
	string staffAddress = "";

	//Declare Store variable for Staff
	string storeStaffId = "";
	string storeStaffName = "";
	string storeStaffPassword = "";
	string storeType = "";

	//==========================STAFF==========================
	void reportByHomestay(MYSQL *conn);
	void reportByMonth(MYSQL *conn);

	//==========================Software Structure==========================
	void AdminMenu(MYSQL* conn, int);
	void r_MainMenu(MYSQL* conn, int);
	void a_homestay(MYSQL* conn, int);
	void a_staff(MYSQL* conn, int);
	void a_report(MYSQL* conn, int);

	void StaffSignUp(MYSQL* conn);
	void Login(MYSQL* conn);

	//==========================CALENDER====================================

	int days_in_months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int first_day, second_day;
	int first_month, second_month;
	int first_year, second_year;
	int years_difference, days_difference;
	int months_total;
	int reg_year = 365;
	string dayIn, monthIn, yearIn;
	string dayOut, monthOut, yearOut;

	int calculateDays(string first_day, string first_month, string first_year, string second_day, string second_month, string second_year);
	bool IsEmpty(string dayIn, string monthIn, string yearIn, string dayOut, string  monthOut, string  yearOut, string  checkIn, string  CheckOut);
	/*
	int dayNumber(int day, int month, int year);
	int numberOfDays(int monthNumber, int year);
	string getMonthName(int monthNumber);
	void printCalendar(int year);
	*/

	//========================OTHER===========================
	// Colour
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	string storeBillCharge = "";

	//Database variable
	int qstate;
	MYSQL_ROW row;
	MYSQL_RES* result;

	void loading();
	bool check_number(string str)
	{
		for (int i = 0; i < str.length(); i++)
			if (isdigit(str[i]) == false)
				return false;
		return true;
	}
};

#endif