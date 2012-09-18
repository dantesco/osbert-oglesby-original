#include "stdafx.h"
#include "UserInterface.h"
#include "GalleryPainting.h"
#include "Masterpiece.h"
#include "Masterwork.h"
#include "Fashionability.h"
#include "Other.h"
#include "PurchasesReport.h"
#include "SalesReport.h"
#include "ComputeFutureTrends.h"


void UserInterface::clearScreen ()
//
// clears the screen
//
{

	//
	// implementation-dependent code to clear the screen should replace
	// the code given below
	//

	for (int i = 0; i < 26; i++)
		cout << endl;

} // clearScreen

//-------------------------------------------------------------------------------------------------------------------

void UserInterface::pressEnter ()
//
// waits until the user presses the <ENTER> key
//
{

	char ch;  // dummy variable used to induce keyboard input

	fflush (stdin);
	cout << endl;
	ch = getchar ();

} // pressEnter

//-------------------------------------------------------------------------------------------------------------------

void UserInterface::displayMainMenu ()
//
// displays the main menu containing all the options available to the user
//
{

	bool done;					// terminates do-loop
	int	 choice;				// user's choice
	GalleryPainting	painting;	// painting object to be sold

	done = false;
	while (!done)
	{
		clearScreen ();
		cout << "				MAIN MENU\n\n\n";
		cout << "		Osbert Oglesby - Collector of Fine Art\n\n\n";
		cout << "			1. Buy a Painting\n\n";
		cout << "			2. Sell a Painting\n\n";
		cout << "			3. Produce a Report\n\n";
		cout << "			4. Quit\n\n\n";
		cout << "		Enter your choice and press <ENTER>: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				displayBuyPaintingMenu ();
				break;

			case 2:
				painting.sell ();
				break;

			case 3:
				displayReportMenu ();
				break;

			case 4:
				done = true;
				break;

			default:
				cout << endl << endl << "Choice is out of range\n\n";
				cout << "      Press <ENTER> to return to menu...";
				pressEnter ();
				break;

		} // switch (choice)

	} // while (!done)

} // displayMainMenu

//-------------------------------------------------------------------------------------------------------------------

void UserInterface::displayBuyPaintingMenu ()
//
// allows user to select the type of painting to be purchased
//
{

	bool done;					// terminates do-loop
	int	 choice;				// user's choice
	Masterpiece	masterpiece;	// item to be bought
	Masterwork masterwork;		// item to be bought
	Other other;				// item to be bought
	Fashionability fash;		// item to be updated

	done = false;
	while (!done)
	{
		clearScreen ();
		cout << "				BUY PAINTING MENU\n\n\n";
		cout << "		Osbert Oglesby - Collector of Fine Art\n\n\n";
		cout << "			1. Buy a Masterpiece\n\n";
		cout << "			2. Buy a Masterwork\n\n";
		cout << "			3. Buy an Other piece of work\n\n";
		cout << "			4. Update Fashionability Coefficient\n\n";
		cout << "			5. Return to Main Menu\n\n\n";
		cout << "		Enter your choice and press <ENTER>: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				masterpiece.buy ();
				break;

			case 2:
				masterwork.buy ();
				break;

			case 3:
				other.buy ();
				break;

			case 4:
				fash.addNewFash ();
				break;

			case 5:
				done = true;
				break;

			default:
				cout << endl << endl << "Choice is out of range\n\n";
				cout << "      Press <ENTER> to return to menu...";
				pressEnter ();
				break;

		} // switch (choice)

	} // while (!done)

} // displayBuyPaintingMenu

//-------------------------------------------------------------------------------------------------------------------

void UserInterface::displayReportMenu ()
//
// allows user to select the type of report to be displayed
//
{

	bool done;					// terminates do-loop
	int	choice;					// user's choice
	GalleryPainting	painting;	// item used to invoke report

	done = false;
	while (!done)
	{
		clearScreen ();
		cout << "				REPORT MENU\n\n\n";
		cout << "		Osbert Oglesby - Collector of Fine Art\n\n\n";
		cout << "			1. Report on Bought Paintings\n\n";
		cout << "			2. Report on Sold Paintings\n\n";
		cout << "			3. Report on Trends\n\n";
		cout << "			4. Return to Main Menu\n\n\n";
		cout << " 	Enter your choice and press <ENTER>: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				PurchasesReport::printReport ();
				break;

			case 2:
				SalesReport::printReport ();
				break;

			case 3:
				ComputeFutureTrends::compute ();
				break;

			case 4:
				done = true;
				break;

			default:
				cout << endl << endl << "Choice is out of range\n\n";
				cout << "      Press <ENTER> to return to menu...";
				pressEnter ();
				break;

		} // switch (choice)

	} // while (!done)

} // displayReportMenu

//-------------------------------------------------------------------------------------------------------------------

void UserInterface::addArtist (string fn, string ln)	// first/last name of artist to be added
//
// inserts an artist name into the artist file
//
{
	ifstream inTmp, inCopy;		// stream objects used for file input
	ofstream outTmp, outCopy;	// stream objects used for file output
	string tempFn;				// temporary string used for file copying
	string tempLn;				// temporary string used for file copying
	bool found = false;			// indicates if artist insertion point found

	inTmp.open ("artist.dat", ios::in);

	if (inTmp)
	{
		outTmp.open ("tempArt.dat", ios::out);

		//
		// the following loop copies the current artist file to a temporary file
		//
		while (!inTmp.eof ())
		{
			//
			// read a temporary name from the artist file
			//
			inTmp >> tempFn;
			inTmp >> tempLn;

			if((tempFn.length() > 0) && ((tempFn.compare(fn) != 0) || (tempLn.compare(ln) != 0)))
			{
			  //
			  // write the temporary name to the temporary file
			  //
			  outTmp << tempFn << endl;
		      outTmp << tempLn << endl;
			}
		}

		outTmp.close ();
		inTmp.close ();

	} // if (inTmp)

	outCopy.open ("artist.dat", ios::out);
	inCopy.open ("tempArt.dat", ios::in);

	if (inCopy)
	{
		//
		// copy the temporary file to a new artist file
		// while inserting the new artist name in the proper location
		//
		while (!inCopy.eof ())
		{
			//
			// read a temporary name from the temporary file
			//
			inCopy >> tempFn;
			inCopy >> tempLn;

			if(tempFn.length() > 0)
			{
			  //
			  // write the proper record to the artist file in alphabetical order
			  //
			  if ((compareStr (tempLn, ln) < 0) || found)
			  {
				outCopy << tempFn << endl;
				outCopy << tempLn << endl;
			  }
			  else
			  {
				if (compareStr (tempLn, ln) > 0)
				{
			    	outCopy << fn << endl;
			    	outCopy << ln << endl;
				    outCopy << tempFn << endl;
				    outCopy << tempLn << endl;
					found = true;
				}
				else
				{
					if (compareStr (tempFn, fn) < 0)
                    {
				       outCopy << tempFn << endl;
				       outCopy << tempLn << endl;
					}
					else
					{
			     	    outCopy << fn << endl;
				        outCopy << ln << endl;
				        outCopy << tempFn << endl;
				        outCopy << tempLn << endl;
						found = true;
					}
			
				}

			  }

			}


		} // while (!inCopy.eof ())

		inCopy.close ();

	} // if (inCopy)

	//
	// write the artist name to the end of the artist file
	//
	if (!found)
    {
		outCopy << fn << endl;
		outCopy << ln << endl;
	}

	outCopy.close ();

} // addArtist

//-------------------------------------------------------------------------------------------------------------------

int UserInterface::compareStr (string str1, string str2)	// represents the two strings to compare
//
// compares two strings in the same manner as strcmp while ignoring any
// question marks
//
{
	string temp1 = str1, temp2 = str2;	// represents strings void of any question marks

	//
	// remove all question marks from both strings
	//
	removeQ (temp1);
	removeQ (temp2);

	//
	// compare the two strings without question marks
	//
	return temp1.compare(temp2);

} // compareStr

//-------------------------------------------------------------------------------------------------------------------

void UserInterface::removeQ(string &str)
//
// remove all question marks from a string
//
{

  //
  // loop and remove question marks until none remain
  //
  while(str.find("?") != -1)
  {

     int location = str.find("?");

     str.erase(location, 1);

  }

} // removeQ


