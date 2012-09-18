#include "stdafx.h"
#include "Fashionability.h"
#include "UserInterface.h"


void Fashionability::getDescription (void)
//
// retrieves fashionability description information
//
{
	UserInterface::clearScreen ();

	//
	// request fashionability object information
	//

	cout << "Please enter the following information concerning the artist whose\n";
	cout << "fashionability coefficient you wish to change.\n\n";
	cout << "Note: - Use an underscore in place of any spaces.\n";
	cout << "      - Do not leave any request blank.\n\n\n";

	cout << "Enter the FIRST name of the artist: ";
	cin >> firstName;

	cout << "Enter the LAST name of the artist: ";
	cin >> lastName;

	cout << "Enter the new fashionability coefficient for this artist: ";
	cin >> coefficient;

} // Fashionability::getDescription

//-------------------------------------------------------------------------------------------------------------------

void Fashionability::readFash (ifstream& fileName) // stream object where fashionability information is read
//
// reads a fashionability object from fileName
//
{
	fileName >> firstName;
	fileName >> lastName;
	fileName >> coefficient;

} // FashionabilityCoefficientClass::readFash

//-------------------------------------------------------------------------------------------------------------------

void Fashionability::writeFash (ofstream& fileName)	// stream object where fashionability information is written
//
// writes a fashionability object to fileName
//
{
  if(firstName.length() > 0)
  {
	fileName << firstName << endl;
	fileName << lastName << endl;
	fileName << coefficient << endl;
  }
} // FashionabilityCoefficientClass::writeFash

//-------------------------------------------------------------------------------------------------------------------

void Fashionability::addNewFash (void)
//
// allows the user to add/update the fashionability coefficient
// of an object of FashionabilityCoefficientClass
//
{
	ifstream inTmp, inCopy;		// stream objects used for file input
	ofstream outTmp, outCopy;	// stream objects used for file output
	bool found;					// indicates if object insertion point found
	Fashionability tempFash;	// temporary object used for file copying

	//
	// obtain information about the new fashionability object
	//
	getDescription ();

	found = false;

	inTmp.open ("fash.dat", ios::in);
	outTmp.open ("tempF.dat", ios::out);

	if (inTmp)
	{
		//
		// copy the current fashionability file to a temporary file
		//
		while (!inTmp.eof ())
		{
		  //
		  // read/write a temporary object from the fashionability file
		  //
		  tempFash.readFash (inTmp);
     	  tempFash.writeFash (outTmp);
		}


	} // if (inFile)

	outTmp.close ();
	inTmp.close ();

	outCopy.open ("fash.dat", ios::out);
	inCopy.open ("tempF.dat", ios::in);

	if (inCopy)
	{
		//
		// copy the temporary file to a new fashionability file
		// while updating/inserting the fashionability object
		//
		while (!inCopy.eof ())
		{
			//
			// read/write a temporary fashionability object from the temporary file
			//
			tempFash.readFash (inCopy);

			if ((UserInterface::compareStr (tempFash.firstName, firstName) == 0) &&
				(UserInterface::compareStr (tempFash.lastName, lastName)  == 0))
			{
				writeFash (outCopy);
				found = true;
			}
			else
				tempFash.writeFash (outCopy);

		} // while (!inFile.eof ())


	} // if (inFile)

	//
	// write the fashionability object to the end of the fashionability file
	//
	if (!found)
		writeFash (outCopy);
	
	inCopy.close ();
	outCopy.close ();

	cout << endl << endl;
	cout << " Press <ENTER> to return to main menu...";

	UserInterface::pressEnter ();

} // Fashionability::addNewFash
