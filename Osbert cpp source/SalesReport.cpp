#include "stdafx.h"
#include "SalesReport.h"
#include "GalleryPainting.h"
#include "UserInterface.h"


void SalesReport::printReport(void)
//
// displays a report of sold paintings
//
{
	ifstream inFile;				// stream object used for file input
	Date oneLess;					// date one year ago today
	int i;							// counts number of paintings in report
	float totalSelling;				// sum of actual selling prices
	float totalTarget;				// sum of target prices
    GalleryPainting tempGallery;	// temporary object used for file reading

	totalSelling = 0.0;
	totalTarget  = 0.0;
	i = 0;

	UserInterface::clearScreen ();

	oneLess = Date::currentDate;
	oneLess.subtractOneYear ();

	inFile.open ("sold.dat", ios::in);

	if (inFile)
	{
		//
		// read in all paintings from the gallery and
		// determine if they are candidates for the sold report
		//
		while (!inFile.eof ())
		{
			//
			// read a gallery object from the sold file
			//
			tempGallery.readSold (inFile);
			
			//
			// check if the painting was sold within the past year
			//
			if (oneLess.compare(tempGallery.getSaleDate()) <= 0)
			{
				//
				// pause the screen after every three paintings
				//
				if (((i % 3) == 0) && (i != 0))
				{
					cout << endl << endl;
					cout << " Press <ENTER> to view the next screen...";
					UserInterface::pressEnter ();

				}

				//
				// display a header message after every third painting
				//
				if ((i % 3) == 0)
				{
					UserInterface::clearScreen ();
					cout << endl << endl;
					cout << "\t\t               Report Date:" << Date::currentDate << endl;
					cout << "\t\t      Osbert Oglesby - Collector of Fine Art\n";
					cout << "\t\t                  SOLD PAINTINGS\n\n";
				}

				cout << "--------------------------------------------------------------------------\n";
				cout << "CLASSIFICATION: ";

				if (tempGallery.getSellPrice() < (tempGallery.getTargetPrice() * 0.95))
					cout << "*";

				cout << tempGallery.getClassification() << "   ";
				cout << "\tSALE DATE:     " << tempGallery.getSaleDate() << endl;
				cout << "LAST NAME:      " << tempGallery.getLastName();
				cout << "\t\tTITLE:         " << tempGallery.getTitle() << endl;
				cout << "TARGET PRICE:   " << tempGallery.getTargetPrice();
				cout << "\t\tSELLING PRICE: " << tempGallery.getSellPrice() << endl;

				totalSelling = totalSelling + tempGallery.getSellPrice();
				totalTarget = totalTarget + tempGallery.getTargetPrice();

				i++;

			} // if (dateCompare (oneLess, saleDate) <= 0)

		} // while (!inFile.eof ())

		inFile.close ();

	} // if (inFile)

	cout << endl << endl;

	if (totalTarget > 0)
		cout << "Average ratio: " << (totalSelling / totalTarget);
	else
		cout << "There have been no paintings sold within the past year.";

	cout << endl << endl;
	cout << " Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

} // SalesReport::printReport

