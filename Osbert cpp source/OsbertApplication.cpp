//
// OsbertApplication.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include "Date.h"
#include "UserInterface.h"

void main (void)
{
	bool dateOK = false;	// indicates if current date properly entered
	string dateStr;			// string representation of current date

	//
	// initialize float output to two digits after the decimal point
	//
	cout.precision (2);
	cout.setf (ios::showpoint);
	cout.setf (ios::fixed);

	while (!dateOK)
	{
		cout << "Please enter today's date (mm/dd/yyyy): ";
		cin >> dateStr;

		if (Date::currentDate.parseDate(dateStr))
			dateOK = true;
		else
		{
			cout << "You entered the date incorrectly.\n";
			cout << "Please use the format mm/dd/yyyy.\n";
		}
	}

	UserInterface::displayMainMenu ();


} // main