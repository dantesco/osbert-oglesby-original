#include "stdafx.h"
#include "GalleryPainting.h"
#include "ComputeMasterpiecePrice.h"
#include "ComputeMasterworkPrice.h"
#include "ComputeOtherPrice.h"
#include "UserInterface.h"


void GalleryPainting::getGalleryInformation (void)
//
// retrieves gallery painting information
//
{
	cout << endl << endl;

	purchaseDate = Date::currentDate;

	cout << "Enter the NAME of the seller: ";
	cin >> sellerName;

	cout << "Enter the ADDRESS of the seller: ";
	cin >> sellerAddr;

	cout << "Enter the purchase PRICE of the painting: ";
	cin >> purchasePrice;

	targetPrice = purchasePrice * TARGET_MARKUP;

} // GalleryPainting::getGalleryInformation

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::addNewPainting (void)
//
// inserts a gallery object in the proper place
//
{
	ifstream inTmp, inCopy;			// stream objects used for file input
	ofstream outTmp, outCopy;		// stream objects used for file output
	bool found = false;				// indicates if object insertion point found
	GalleryPainting	tempGallery;	// temporary object used for file copying

	inTmp.open ("gallery.dat", ios::in);

	if (inTmp)
	{
		outTmp.open ("tempG.dat", ios::out);
		//
		// copy the current gallery file to a temporary file
		//
		while (!inTmp.eof ())
		{
			//
			// read the temporary gallery object from the gallery file
			//
			tempGallery.readBought (inTmp);

		   	//
		   	// write the temporary gallery object to a temporary file
		   	//
			tempGallery.writeBought (outTmp);
		}



	} // if (inTmp)
		
	inTmp.close ();
	outTmp.close ();

	outCopy.open ("gallery.dat", ios::out);
	inCopy.open ("tempG.dat", ios::in);

	if (inCopy)
	{
		//
		// copy the temporary file to new gallery file
		// while inserting the gallery object in the proper location
		//
		while (!inCopy.eof ())
		{
			//
			// read a temporary gallery object from the temporary file
			//
			tempGallery.readBought (inCopy);
			
			//
			// write the proper object to the gallery file
			//
			if ((classification.compare(tempGallery.classification) <= 0) &&
				(purchaseDate.compare(tempGallery.purchaseDate) <= 0) && !found)
			{
				//
				// write the gallery object to the gallery file
				//
				writeBought (outCopy);

				//
				// write the temporary gallery object to the gallery file
				//
				tempGallery.writeBought (outCopy);

				found = true;

			}
			else
				tempGallery.writeBought (outCopy);


		} // while (!inCopy.eof ())

	} // if (inCopy)

	//
	// write the gallery object to the end of the gallery file
	//
	if (!found)
		writeBought (outCopy);

	inCopy.close ();
	outCopy.close ();

} // GalleryPainting::addNewPainting

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::buy (void)
//
// allows user to buy a painting
//
{
	ifstream inFile;				// stream object used for file input
	char ch;						// holds user response to Y/N question
	bool found = false;				// indicates if painting already in gallery
	GalleryPainting	tempGallery;	// temporary object used for file reading

	getDescription ();

	inFile.open ("gallery.dat", ios::in);

	if (inFile)
	{
		//
		// determine if the gallery object already exists in the gallery
		//
		while (!inFile.eof ())
		{
			//
			// read a temporary gallery object from the gallery file
			//
			tempGallery.readBought (inFile);
			
			//
			// check if there is a match with the gallery object
			//
			if ((UserInterface::compareStr (tempGallery.firstName, firstName) == 0) &&
				(UserInterface::compareStr (tempGallery.lastName, lastName) == 0) &&
				(UserInterface::compareStr (tempGallery.title, title) == 0))
			{
				found = true;
				break;
			}

		} // while (!inFile.eof ())


	} // if (inFile)
		
	inFile.close ();

	if (found == true)
	{
		cout << endl << endl;
		cout << "The painting you described has already been purchased!\n\n";
	}
	else
	{

		if(classification.compare("Masterpiece") == 0)
			algPrice = ComputeMasterpiecePrice::getAlgorithmPrice(this);
		if(classification.compare("Masterwork") == 0)
			algPrice = ComputeMasterworkPrice::getAlgorithmPrice(this);
		if(classification.compare("Other") == 0)
			algPrice = ComputeOtherPrice::getAlgorithmPrice(this);

		cout << endl << endl;

		if (algPrice > 0)
		{
			cout << "The algorithm has determined the maximum offering price to be:\n";
			cout << "$" << algPrice << " million dollars.\n\n";

			cout << "Do you want to purchase this painting (Y/N)? ";

			fflush (stdin);
			cout << endl;
			ch = getchar ();

			if ((ch == 'Y') || (ch == 'y'))
			{
				getGalleryInformation ();
				addNewPainting ();
			}
		}
		else
			cout << "The algorithm has suggested that you should not buy this painting.";
	}

	cout << endl << endl;
	cout << " Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

} // GalleryPainting::buy

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::readBought (ifstream& fileName) // stream object where gallery information is read
//
// reads a gallery object from fileName
//
{
	string tempDate;

	fileName >> classification;
	fileName >> firstName;
	fileName >> lastName;
	fileName >> title;
	fileName >> tempDate;
	paintingDate.parseDate(tempDate);
	fileName >> tempDate;
	purchaseDate.parseDate(tempDate);
	fileName >> medium;
	fileName >> subject;
	fileName >> sellerName;
	fileName >> sellerAddr;
	fileName >> algPrice;
	fileName >> purchasePrice;
	fileName >> targetPrice;
	fileName >> height;
	fileName >> width;	

} // GalleryPainting::readBought

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::writeBought (ofstream& fileName) // stream object where gallery information is written
//
// writes a gallery object to fileName
//
{
  if(classification.length() > 0)
  {
	fileName << classification << endl;
	fileName << firstName << endl;
	fileName << lastName << endl;
	fileName << title << endl;
	fileName << paintingDate << endl;
	fileName << purchaseDate << endl;
	fileName << medium << endl;
	fileName << subject << endl;
	fileName << sellerName << endl;
	fileName << sellerAddr << endl;
	fileName << algPrice << endl;
	fileName << purchasePrice << endl;
	fileName << targetPrice << endl;
	fileName << height << endl;
	fileName << width << endl;
  }
} // GalleryPainting::writeBought

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::addNewSale (void)
//
// records that a gallery painting has been sold
//
{
	ifstream inTmp, inCopy;			// stream objects used for file input
	ofstream outTmp, outCopy;		// stream objects used for file output
	bool found;						// indicates if object insertion point found
	GalleryPainting	tempGallery;	// temporary object used for file copying

	found = false;

	inTmp.open ("sold.dat", ios::in);

	if (inTmp)
	{
		outTmp.open ("tempS.dat", ios::out);

		//
		// copy the current sold file to a temporary file
		//
		while (!inTmp.eof ())
		{
			//
			// read a temporary gallery object from the sold file
			//
			tempGallery.readSold (inTmp);

	        //
		    // write the temporary gallery object to the temporary file
		    //
		    tempGallery.writeSold (outTmp);

		} // while (!inTmp.eof ())



	} // if (inTmp)
		
	inTmp.close ();
	outTmp.close ();

	outCopy.open ("sold.dat", ios::out);
	inCopy.open ("tempS.dat", ios::in);

	if (inCopy)
	{
		//
		// copy the temporary file to a new sold file
		// while inserting the painting object in the proper location
		//
		while (!inCopy.eof ())
		{
			//
			// read a temporary gallery object from the temporary file
			//
			tempGallery.readSold (inCopy);
			
			//
			// write the proper object to the sold file
			//
			if ((classification.compare(tempGallery.classification) <= 0) &&
				(tempGallery.saleDate.compare(saleDate)   <= 0) &&
				!found)
			{
				//
				// write the gallery object to the sold file
				//
				writeSold (outCopy);

				//
				// write the temporary gallery object to the sold file
				//
				tempGallery.writeSold (outCopy);

				found = true;
			}
			else
				tempGallery.writeSold (outCopy);

		} // while (!inCopy.eof ())

	} // if (inCopy)

	//
	// write the gallery object to the end of the sold file
	//
	if (!found)
		writeSold (outCopy);

	inCopy.close ();
	outCopy.close ();

} // GalleryPainting::addNewSale

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::sell (void)
//
// allows user to sell a painting found in the gallery
//
{
	ifstream inSold, inGallery;	// stream objects used for file input
	bool found;					// indicates if painting already in gallery
	int alreadySold;			// indicates if painting already sold
	string tempFn;				// tempFn, tempLn, and tempTitle
	string tempLn;				// store temporary information about
	string tempTitle;			// the painting to be sold, namely first name, last name, and title, resp.

	UserInterface::clearScreen ();

	//
	// retrieve information about the painting desired to be sold
	//

	cout << endl << endl;
	cout << "Please enter the following information describing the painting:\n\n";
	cout << "Note: - Use an underscore in place of any spaces.\n";
	cout << "      - Do not leave any request blank.\n\n\n";

	cout << "Enter the FIRST name of the artist (append ? if uncertain): ";
	cin >> tempFn;

	cout << "Enter the LAST name of the artist (append ? if uncertain): ";
	cin >> tempLn;

	cout << "Enter the TITLE of the painting (append ? if uncertain): ";
	cin >> tempTitle;

	alreadySold = false;

	inSold.open ("sold.dat", ios::in);

	if (inSold)
	{
		//
		// determine if the desired painting has already been sold
		//
		while (!inSold.eof ())
		{
			//
			// read a gallery object from the sold file
			//
			readSold (inSold);
		
			//
			// check if there is a match with the gallery object
			//
			if ((UserInterface::compareStr (firstName, tempFn) == 0) &&
				(UserInterface::compareStr (lastName, tempLn)  == 0) &&
				(UserInterface::compareStr (title, tempTitle)  == 0))
			{
				alreadySold = true;
				break;
			}
			

		} // while (!inSold.eof ())

		inSold.close ();

	} // if (inSold)

	if (alreadySold)
	{
		cout << endl << endl;
		cout << "The painting you described has already been sold!\n\n";
	}
	else
	{
		found = false;

		inGallery.open ("gallery.dat", ios::in);

		if (inGallery)
		{
			//
			// check to make sure that the desired painting
			// actually exists in the gallery
			//
			while (!inGallery.eof ())
			{
				//
				// read a gallery object from the gallery file
				//
				readBought (inGallery);
				
				//
				// check if there is a match with the desired painting
				//
				if ((UserInterface::compareStr (firstName, tempFn) == 0) &&
					(UserInterface::compareStr (lastName, tempLn) == 0) &&
					(UserInterface::compareStr (title, tempTitle) == 0))
				{
					found = true;
					break;
				}
				
			} // while (!inGallery.eof ())

			inGallery.close ();

		} // if (inGallery)

		if (found == true)
		{
			cout << endl << endl;
			cout << "Please enter the following sale information:\n\n\n";

			saleDate = Date::currentDate;

			cout << "Enter the NAME of the buyer: ";
			cin >> buyerName;

			cout << "Enter the ADDRESS of the buyer: ";
			cin >> buyerAddr;

			cout << "Enter the selling PRICE: ";
			cin >> sellPrice;

			addNewSale ();
			UserInterface::addArtist (firstName, lastName);

			cout << endl << endl;
			cout << "The sale has been recorded.";
		}
		else
		{
			cout << endl << endl;
			cout << "The painting you described cannot be found in the gallery.\n";
			cout << "Please make sure you entered the information correctly.\n";
			cout << "Proper case is required.\n";
		}
	} //  else (alreadySold != TRUE)

	cout << endl << endl;
	cout << " Press <ENTER> to return to main menu...";
	UserInterface::pressEnter ();

} // GalleryPainting::sell

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::readSold (ifstream& fileName)	// stream object where gallery information is read
//
// reads a sold gallery object from fileName
//
{
	string tempDate;

	fileName >> classification;
	fileName >> firstName;
	fileName >> lastName;
	fileName >> title;
	fileName >> tempDate;
	paintingDate.parseDate(tempDate);;
	fileName >> tempDate;
	purchaseDate.parseDate(tempDate);
	fileName >> tempDate;
	saleDate.parseDate(tempDate);
	fileName >> medium;
	fileName >> subject;
	fileName >> sellerName;
	fileName >> buyerName;
	fileName >> sellerAddr;
	fileName >> buyerAddr;
	fileName >> algPrice;
	fileName >> purchasePrice;
	fileName >> targetPrice;
	fileName >> sellPrice;
	fileName >> height;
	fileName >> width;
	
} // GalleryPainting::readSold

//-------------------------------------------------------------------------------------------------------------------

void GalleryPainting::writeSold (ofstream& fileName)  // stream object where gallery information is written
//
// writes a sold gallery object to fileName
//
{
  if(classification.length() > 0)
  {
	fileName << classification << endl;
	fileName << firstName << endl;
	fileName << lastName << endl;
	fileName << title << endl;
	fileName << paintingDate << endl;
	fileName << purchaseDate << endl;
	fileName << saleDate << endl;
	fileName << medium << endl;
	fileName << subject << endl;
	fileName << sellerName << endl;
	fileName << buyerName << endl;
	fileName << sellerAddr << endl;
	fileName << buyerAddr << endl;
	fileName << algPrice << endl;
	fileName << purchasePrice << endl;
	fileName << targetPrice << endl;
	fileName << sellPrice << endl;
	fileName << height << endl;
	fileName << width << endl;
  }
} // GalleryPainting::writeSold

