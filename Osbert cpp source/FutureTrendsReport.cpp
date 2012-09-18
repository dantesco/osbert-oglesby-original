#include "stdafx.h"
#include "FutureTrendsReport.h"
#include "GalleryPainting.h"
#include "UserInterface.h"

void FutureTrendsReport::printReport (string tempFn, string tempLn)
//
// displays a trend report for a specific painter
//
{
	ifstream soldFile;				// stream object used for file input
	Date oneLess;					// date one year ago today
	int	i;
	GalleryPainting	tempGallery;	// temporary object used for file reading

	i=0;

	oneLess = Date::currentDate;
	oneLess.subtractOneYear ();
	UserInterface::clearScreen ();

	cout << endl << endl;
	cout << "\t\t               Report Date:" << Date::currentDate << endl;
	cout << "\t\t      Osbert Oglesby - Collector of Fine Art\n";
	cout << "\t\t                  TRENDS\n\n";

	cout << "Painter: " << tempFn << " " << tempLn << endl;

	soldFile.open ("sold.dat", ios::in);

	//
	// examine every sold painting of the current artist
	// indicated by tempFn, tempLn
	//
	while (!soldFile.eof ())
	{
		//
		// read a painting object from the sold file
		//
		tempGallery.readSold (soldFile);
		
		//
		// check if the painting was sold within the past year
		// and make sure it was painted by the current artist
		//
		if ((oneLess.compare(tempGallery.getSaleDate()) <= 0) &&
			(UserInterface::compareStr (tempFn, tempGallery.getFirstName()) == 0) &&
			(UserInterface::compareStr (tempLn, tempGallery.getLastName())  == 0))
		{
			//
			// pause the screen after every three paintings
			//
			if (((i % 3) == 0) && (i != 0))
			{
				cout << endl << endl;
				cout << " Press <ENTER> to view the next screen...";
				UserInterface::pressEnter ();
				UserInterface::clearScreen ();

				cout << endl << endl;
				cout << "\t\t\t         Report Date:" << Date::currentDate << endl;
				cout << "\t\t\t Osbert Oglesby - Collector of Fine Art\n";
				cout << "\t\t\t            TRENDS\n\n";
					
				cout << "Painter: " << tempFn << " " << tempLn << endl;

			}

			cout << "--------------------------------------------------------------------\n";
			cout << "CLASSIFICATION: ";

			cout << tempGallery.getClassification() << "   ";
			cout << "\t\tTITLE: " << tempGallery.getTitle() << endl;
			cout << "SALE DATE:	" << tempGallery.getSaleDate() << endl;
			cout << "TARGET PRICE:	" << tempGallery.getTargetPrice();
			cout << "\t\tSELLING PRICE: " << tempGallery.getSellPrice() << endl;

			i++;

		} // if ((dateCompare (oneLess, saleDate) <= 0) &&

	} // while (!soldFile.eof ())

	cout << endl << endl;
	cout << " Press <ENTER> to continue...";
	UserInterface::pressEnter ();

	soldFile.close ();

} // FutureTrendsReport::displayTrend

