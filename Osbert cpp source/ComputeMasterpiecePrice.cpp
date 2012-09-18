#include "stdafx.h"
#include "ComputeMasterpiecePrice.h"
#include "AuctionedPainting.h"
#include "UserInterface.h"


float ComputeMasterpiecePrice::getAlgorithmPrice (GalleryPainting* const masterpiece)
//
// determines the maximum price to be offered for a masterpiece
//
{
	ifstream inFile;					// stream object used for file input
	float high;							// keeps track of highest similarity
	float algHigh;						// price of most similar work
	float temp;							// number of matches on medium/subject
	float auctionArea;					// area of an auction painting
	float galleryArea;					// area of a gallery painting
	int	i;								// loop iterator for compound interest
	Date highDate;						// date of most similar work
	AuctionedPainting	tempAuction;	// temporary object used for file reading

	high = 0.0;
	algHigh = 0.0;

	highDate = Date::currentDate;

	inFile.open ("auction.dat", ios::in);

	if (inFile)
	{
		//
		// loop through all of the auction objects and find the most similar work
		//
		while (!inFile.eof ())
		{
			//
			// read an auction object
			//
			tempAuction.readAuctionData (inFile);
			
			temp = 0.0;

			//
			// if the artist names match, compute the similarity
			//
			if ((UserInterface::compareStr (tempAuction.getFirstName (), masterpiece->getFirstName()) == 0) &&
				(UserInterface::compareStr (tempAuction.getLastName (), masterpiece->getLastName()) == 0))
			{
				if (masterpiece->getMedium().compare(tempAuction.getMedium ()) == 0)
					temp++;

				if (masterpiece->getSubject().compare(tempAuction.getSubject ()) == 0)
					temp++;

				auctionArea = tempAuction.getHeight () * tempAuction.getWidth ();
				galleryArea = masterpiece->getHeight() * masterpiece->getWidth();

				if (auctionArea > galleryArea)
					temp = temp * galleryArea / auctionArea;
				else
					temp = temp * auctionArea / galleryArea;

				//
				// a higher similarity was found...
				//
				if (temp > high)
				{
					high = temp;
					algHigh = tempAuction.getAuctionPrice ();
					highDate = tempAuction.getAuctionDate ();
				}

			} // if ((compareStr (tempAuction.getFirstName (), firstName) == 0)
		
		} // while (!inFile.eof ())

		inFile.close ();

	} // if (inFile)

	//
	// compute the compound interest
	//
	for (i = highDate.getYear(); i < Date::currentDate.getYear(); i++)
		algHigh = algHigh * ANNUAL_INTEREST;

	return algHigh;

} // ComputeMasterpiecePrice::getAlgorithmPrice
