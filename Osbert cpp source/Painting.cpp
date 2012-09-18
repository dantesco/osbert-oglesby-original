#include "stdafx.h"
#include "Painting.h"
#include "UserInterface.h"


void Painting::getDescription ()
//
// retrieves painting description information
//
{
	bool valid;		// determines if the value for a medium or subject is valid
    string tempStr;	// temporary string holder for a date

	UserInterface::clearScreen ();

	cout << "Please enter the following information about the painting:\n\n";

	cout << "Note: - Use an underscore in place of any spaces.\n";
	cout << "     - Do not leave any request blank.\n\n\n";

	cout << endl << endl;

	cout << "Enter the FIRST name of the artist (append ? if uncertain): ";
	cin >> firstName;

	cout << "Enter the LAST name of the artist (append ? if uncertain): ";
	cin >> lastName;

	cout << "Enter the TITLE of the painting (append ? if uncertain): ";
	cin >> title;

	cout << "Enter the DATE the painting was created (mm/dd/yyyy) (append ? if uncertain): ";
	cin >> tempStr;
	paintingDate.parseDate(tempStr);;

	cout << "Enter the HEIGHT of the painting (in centimeters): ";
	cin >> height;

	cout << "Enter the WIDTH of the painting (in centimeters): ";
	cin >> width;

	//
	// retrieves and validates a value for medium
	//
	valid = false;
	while (!valid)
	{	
		cout << "Enter the MEDIUM of the painting (oil, watercolor, other): ";
		cin >> medium;

		if ((medium.compare("oil") == 0) || (medium.compare("watercolor") == 0)
			|| (medium.compare("other") == 0))
			valid = true;
		else
		{
			cout << endl << "Invalid response!" << endl;
			cout << "Please enter one of the following:";
			cout << " oil, watercolor, other" << endl << endl;
		}
	}

	//
	// retrieves and validates a value for subject
	//
	valid = false;
	while (!valid)
	{	
		cout << "Enter SUBJECT of the painting (portrait, landscape, still, other): ";
		cin >> subject;

		if ((subject.compare("portrait") == 0) || (subject.compare("landscape") == 0)
			|| (subject.compare("still") == 0) || (subject.compare("other") == 0))
			valid = true;
		else
		{
			cout << endl << "Invalid response!" << endl;
			cout << "Please enter one of the following:";
			cout << " portrait, landscape, still, other" << endl << endl;
		}
	}

} // getDescription

