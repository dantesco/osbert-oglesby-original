#include "stdafx.h"
#include "ComputeFutureTrends.h"
#include "GalleryPainting.h"
#include "FutureTrendsReport.h"
#include "UserInterface.h"


void ComputeFutureTrends::compute(void)
//
// determine the trendy painters
//
{
	ifstream artFile;	// stream object used for file input
	bool found;			// indicates if qualified artists were found
	string tempFn;		// tempFn and tempLn
	string tempLn;		// stores values read from artist file, namely first name and last name, resp.

	found = false;

	UserInterface::clearScreen ();

	artFile.open ("artist.dat", ios::in);

	if (artFile)
	{
		//
		// read in all paintings from the gallery and
		// determine if they are candidates for the trends report
		//
		while (!artFile.eof ())
		{
			//
			// read an artist name from the artist file
			//
			artFile >> tempFn;
			artFile >> tempLn;

			if(tempFn.length() > 0)
			{
			  //
			  // check if all of their paintings have sold over the target price
			  //
			  if (overTarget (tempFn, tempLn))
			  {
			   	FutureTrendsReport::printReport (tempFn, tempLn);
				found = true;
			  }
			}

		} // while (!artFile.eof ())

		artFile.close ();

	} // if (artFile)

	if (!found)
		cout << "There are no artists who qualify for this report...";

	cout << endl << endl;
	cout << " Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

} // ComputeFutureTrends::compute

//-------------------------------------------------------------------------------------------------------------------

bool ComputeFutureTrends::overTarget (string fn, string ln) 	// first/last name of artist under examination
//
// examines all the sold paintings and determines if the artist represented
// by the string parameters fn and ln (first name/last name) has had all of his or her
// paintings sold over the target price during the past year (with at least 2 sales).
// Returns TRUE if all paintings were sold over the target price,
// returns FALSE otherwise
//
{

	ifstream inFile;				// stream object used for file input
	Date oneLess;					// date one year ago today
	int	count;						// # of paintings sold over target price
	bool found;						// denotes if all paintings sold over target
	GalleryPainting	tempGallery;	// temporary object used for file reading

	count = 0;
	found = true;

	oneLess = Date::currentDate;
	oneLess.subtractOneYear ();

	inFile.open ("sold.dat", ios::in);

	if (inFile)
	{

		//
		// examine all of the paintings that have been sold
		//
		while (!inFile.eof () && found)
		{
			//
			// read a temporary gallery object from the sold file
			//
			tempGallery.readSold (inFile);
		
			//
			// ensure that the temporary gallery object is the desired artist
			// and that the sale happened within the past year
			//
			if ((oneLess.compare(tempGallery.getSaleDate ())  <= 0) &&
				(UserInterface::compareStr (fn, tempGallery.getFirstName ()) == 0) &&
				(UserInterface::compareStr (ln, tempGallery.getLastName ())  == 0))
			{
				if (tempGallery.getSellPrice () > tempGallery.getTargetPrice ())
					count++;
				else
					found = false;
			}
		
		} // while (!inFile.eof ())

	} // if (inFile)

	inFile.close ();

	//
	// return TRUE iff all paintings sold in the past year were over the target
	// price (found == TRUE) and there were at least 2 sales (count > 1)
	//
	if (found && count > 1)
		return true;
	else
		return false;

} // ComputeFutureTrends::overTarget
