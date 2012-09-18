#include "stdafx.h"
#include "PurchasesReport.h"
#include "GalleryPainting.h"
#include "UserInterface.h"


void PurchasesReport::printReport(void)
//
// displays a report of bought paintings
//
{
	ifstream			inFile;			// stream object used for file input
	Date oneLess;						// date one year ago today
	int					i;				// counts number of paintings in report
	float				totalPurchase;	// sum of actual purchase prices
	float				totalMax;		// sum of maximum purchase prices
    GalleryPainting		tempGallery;	// temporary object used for file reading

	totalPurchase = 0.0;
	totalMax = 0.0;
	i = 0;

	UserInterface::clearScreen ();

	oneLess = Date::currentDate;
	oneLess.subtractOneYear();

	inFile.open ("gallery.dat", ios::in);

	if (inFile)
	{

		//
		// read in all paintings from the gallery and
		// determine if they are candidates for the bought report
		//
		while (!inFile.eof ())
		{
			//
			// read a gallery object from the gallery file
			//
			tempGallery.readBought (inFile);
		
			//
			// check if the painting was purchased within the past year
			//
			if (oneLess.compare(tempGallery.getPurchaseDate()) <= 0)
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
					cout << "\t\t                  BOUGHT PAINTINGS\n\n";
				}

				cout << "--------------------------------------------------------------------------\n";
				cout << "CLASSIFICATION: ";

				if (tempGallery.getPurchasePrice() > tempGallery.getAlgPrice())
					cout << "*";

				cout << tempGallery.getClassification() << "   ";
				cout << "\tPURCHASE DATE:  " << tempGallery.getPurchaseDate() << endl;
				cout << "LAST NAME:	" << tempGallery.getLastName();		
				cout << "\t\tTITLE:          " << tempGallery.getTitle() << endl;
				cout << "SUGG. PRICE:	" << tempGallery.getAlgPrice();
				cout << "\t\tPURCHASE PRICE: " << tempGallery.getPurchasePrice() << endl;

				totalPurchase = totalPurchase + tempGallery.getPurchasePrice();
				totalMax = totalMax + tempGallery.getAlgPrice();

				i++;

			} // if (dateCompare (oneLess, purchaseDate) <= 0)


		} // while (!inFile.eof ())

		inFile.close ();

	} // if (inFile)

	if (totalMax > 0)
	{
		cout << endl << endl;
		cout << "Average ratio: " << (totalPurchase / totalMax);

	}
	else
		cout << "There have been no paintings bought within the past year.";

	cout << endl << endl;
	cout << " Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

} // PurchasesReport::printReport

