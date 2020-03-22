
#include"Header.h"

int Header::calculateDays(string dayIn, string monthIn, string yearIn, string dayOut, string monthOut, string yearOut)
{
	first_day = stoi(dayIn), first_month = stoi(monthIn), first_year = stoi(yearIn), second_day = stoi(dayOut), second_month = stoi(monthOut), second_year = stoi(yearOut);

	if (first_day > 31 || first_day <= 0)
	{
		cout << "Incorrect day entered" << endl;
		cin.ignore();
		//return 0;
	}
	if (first_month > 12 || first_month <= 0)
	{
		cout << "Incorrect Month entered" << endl;
		cin.ignore();
		//return 0;
	}
	if (first_year > 9999 || first_year < 0)
	{
		cout << "Incorrect Year Entered" << endl;
		cin.ignore();
		//return 0;
	}

	if (second_day > 31 || second_day <= 0)
	{
		cout << "Incorrect day entered" << endl;
		cin.ignore();
		//return 0;
	}
	if (second_month > 12 || second_month <= 0)
	{
		cout << "Incorrect Month entered" << endl;
		cin.ignore();
		//return 0;
	}
	if (second_year > 9999 || second_year < 0)
	{
		cout << "Incorrect Year Entered" << endl;
		cin.ignore();
		//return 0;
	}


	//======================================== Years ========================================


	if (first_year == second_year)
	{
		years_difference = 0;
	}
	else
	{
		if (first_year % 4 == 0 && first_year % 100 != 0 || first_year % 400 == 0)
		{
			if (second_year % 4 == 0 && second_year % 100 != 0 || second_year % 400 == 0)
			{
				if (first_year > second_year)
				{
					years_difference = (first_year - second_year) * (reg_year)+2;
				}
				else
				{
					years_difference = (second_year - first_year) * (reg_year)+2;
				}
				if (second_month > first_month)
				{
					if (days_in_months[first_month - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
			else
			{
				if (first_year > second_year)
				{
					years_difference = (first_year - second_year) * (reg_year)+1;
				}
				else
				{
					years_difference = (second_year - first_year) * (reg_year)+1;
				}
				if (first_month > second_month)
				{
					if (days_in_months[second_month - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
		}
		else
		{
			if (first_year > second_year)
			{
				years_difference = (first_year - second_year) * (reg_year);
			}
			else
			{
				years_difference = (second_year - first_year) * (reg_year);
			}
		}
	}

	//======================================== Months ========================================


	if (first_month == second_month)
	{
		months_total = 0;
	}
	else
	{
		if (first_month > second_month)
		{
			for (int i = (first_month - 1); i > (second_month - 1); i--)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
		else
		{
			for (int i = (first_month - 1); i < (second_month - 1); i++)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
	}

	//======================================== Days ========================================

	int days_total = 0;

	if (first_day == second_day)
	{
		days_difference = 0;
		days_total = (years_difference + months_total) - days_difference;
	}
	else
	{
		if (first_day > second_day)
		{
			days_difference = first_day - second_day;
			days_total = (years_difference + months_total) - days_difference;
		}
		else
		{
			days_difference = second_day - first_day;
			days_total = (years_difference + months_total) + days_difference;
		}
	}

	//======================================== In Between Leap Years ========================================

	if (first_year == second_year)
	{
	}
	else
	{
		if (first_year > second_year)
		{
			for (int i = (second_year + 1); i < first_year; i++)
			{
				if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout << endl;
					cout << i << endl;
					++days_total;
				}
			}
		}
		else
		{
			for (int i = (first_year + 1); i < second_year; i++)
			{
				if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout << endl;
					cout << i << endl;
					++days_total;
				}
			}
		}
	}

	//======================================== Output ========================================

	return days_total;
	//cout << endl;
	//cout << "\nThe total days in between your dates are: " << days_total << endl;
	//cout << endl;

	//cin.get();
	//cin.ignore();
	//return 0;
}

bool Header::IsEmpty(string dayIn, string monthIn, string yearIn, string dayOut, string  monthOut, string  yearOut, string  checkIn, string  checkOut)
{
	//User input
	int IdayIn = stoi(dayIn), ImonthIn = stoi(monthIn), IyearIn = stoi(yearIn), IdayOut = stoi(dayOut), ImonthOut = stoi(monthOut), IyearOut = stoi(yearOut);
	int userInputDate[2][3] = { IdayIn, ImonthIn, IyearIn, 
								IdayOut, ImonthOut, IyearOut };

	//DB
	//Check in
	string checkInDate = checkIn;
	char dateIn[10];

	strcpy(dateIn, checkInDate.c_str());
	int inDay = stoi(string(1, dateIn[8]) + dateIn[9]);
	int inMonth = stoi(string(1, dateIn[5]) + dateIn[6]);
	int inYear = stoi(string(1, dateIn[0]) + dateIn[1] + dateIn[2] + dateIn[3]);

	//Check out
	string checkOutDate = checkOut;
	char dateOut[10];

	strcpy(dateOut, checkOutDate.c_str());
	int outDay = stoi(string(1, dateOut[5]) + dateOut[6]);
	int outMonth = stoi(string(1, dateOut[5]) + dateOut[6]);
	int outYear = stoi(string(1, dateOut[0]) + dateOut[1] + dateOut[2] + dateOut[3]);

	//Check
	int entryDate = (userInputDate[0][2] * 10000) + (userInputDate[0][1] * 100) + userInputDate[0][0];
	int entryDate1 = (userInputDate[1][2] * 10000) + (userInputDate[1][1] * 100) + userInputDate[1][0];

	int startDate = (inYear * 10000) + (inMonth * 100) + inDay;
	int endDate = (outYear * 10000) + (outMonth * 100) + outDay;

	if (entryDate >= startDate && entryDate <= endDate || entryDate1 >= startDate && entryDate1 <= endDate)
		return false;
	else
		return true;
		
}


/*
#include"Header.h"

/*A Function that returns the index of the day
  of the date- day/month/year
  For e.g-

  Index     Day
  0         Sunday
  1         Monday
  2         Tuesday
  3         Wednesday
  4         Thursday
  5         Friday
  6         Saturday

int Header::dayNumber(int day, int month, int year)
{

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 +
        year / 400 + t[month - 1] + day) % 7;
}

///*
  A Function that returns the name of the month
  with a given month number

  Month Number     Name
  0                January
  1                February
  2                March
  3                April
  4                May
  5                June
  6                July
  7                August
  8                September
  9                October
  10               November
  11               December 

string Header::getMonthName(int monthNumber)
{
    string months[] = { "January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
    };

    return (months[monthNumber]);
}

///* A Function to return the number of days in
   a month

  Month Number     Name        Number of Days
  0                January     31
  1                February    28 (non-leap) / 29 (leap)
  2                March       31
  3                April       30
  4                May         31
  5                June        30
  6                July        31
  7                August      31
  8                September   30
  9                October     31
  10               November    30
  11               December    31

//

int Header::numberOfDays(int monthNumber, int year)
{
    // January 
    if (monthNumber == 0)
        return (31);

    // February 
    if (monthNumber == 1)
    {
        // If the year is leap then February has 
        // 29 days 
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    // March 
    if (monthNumber == 2)
        return (31);

    // April 
    if (monthNumber == 3)
        return (30);

    // May 
    if (monthNumber == 4)
        return (31);

    // June 
    if (monthNumber == 5)
        return (30);

    // July 
    if (monthNumber == 6)
        return (31);

    // August 
    if (monthNumber == 7)
        return (31);

    // September 
    if (monthNumber == 8)
        return (30);

    // October 
    if (monthNumber == 9)
        return (31);

    // November 
    if (monthNumber == 10)
        return (30);

    // December 
    if (monthNumber == 11)
        return (31);
}

// Function to print the calendar of the given year 

void Header::printCalendar(int year)
{
    printf("         Calendar - %d\n\n", year);
    int days;

    // Index of the day from 0 to 6 
    int current = dayNumber(1, 1, year);

    // i --> Iterate through all the months 
    // j --> Iterate through all the days of the 
    //       month - i 
    for (int i = 0; i < 12; i++)
    {
        days = numberOfDays(i, year);

        // Print the current month name 
        printf("\n  ------------%s-------------\n",
            getMonthName(i).c_str());

        // Print the columns 
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces 
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }

    return;
}*/

