#include "stdafx.h"
#include "AuctionedPainting.h"


void AuctionedPainting::readAuctionData (ifstream& fileName)	// stream object where auction information is read
//
// reads an auction object from fileName
//
{
	string tempDate;

	fileName >> firstName;
	fileName >> lastName;
	fileName >> title;
	fileName >> tempDate;
	paintingDate.parseDate(tempDate);
	fileName >> height;
	fileName >> width;
	fileName >> medium;
	fileName >> subject;
	fileName >> tempDate;
	auctionDate.parseDate(tempDate);
	fileName >> auctionPrice;

} // AuctionedPainting::readAuctionData
