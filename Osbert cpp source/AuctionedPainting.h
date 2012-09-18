#ifndef _AUCTIONEDPAINTING
#define _AUCTIONEDPAINTING


#include "Painting.h"
#include "Date.h"

class AuctionedPainting : public Painting
{

protected:

	Date	auctionDate;	// date painting sold at auction
	float	auctionPrice;	// auction price of painting

 public:

	// getters-setters for AuctionedPainting	
	Date	getAuctionDate ()		{ return auctionDate; }
	void    setAuctionDate (Date d) { auctionDate = d; }
	float	getAuctionPrice ()		{ return auctionPrice; }
	void    setAuctionPrice (float p) { auctionPrice = p; }

	void readAuctionData (ifstream& fileName);	// reads an auction object from fileName

}; // class AuctionedPainting

#endif