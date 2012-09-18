#ifndef _GALLERY
#define _GALLERY


#include "Painting.h"
#include "Date.h"

#define	TARGET_MARKUP 2.15

class GalleryPainting : public Painting
{

protected:

	string classification;	// gallery classification type
	Date   purchaseDate;	// date painting was purchased
	Date   saleDate;		// date painting was sold
	string sellerName;		// full name of seller
	string buyerName;		// full name of painting buyer
	string sellerAddr;		// address of seller
	string buyerAddr;		// address of buyer
	float  algPrice;		// price determined by algorithm
	float  purchasePrice;	// actual purchase price
	float  targetPrice;		// target selling price
	float  sellPrice;		// actual selling price

public:

	// getters-setters for GalleryPainting
	string getClassification ()			{ return classification; }
	void   setClassification (string c) { classification = c; }
	Date   getPurchaseDate ()			{ return purchaseDate; }
    void   setPurchaseDate (Date d)		{ purchaseDate = d; } 
	Date   getSaleDate ()				{ return saleDate; }
	void   setSaleDate (Date d)			{ saleDate = d; } 
	string getSellerName ()				{ return sellerName; }
	void   setSellerName (string n)		{ sellerName = n; }
	string getBuyerName ()				{ return buyerName; }
    void   setBuyerName (string n)		{ buyerName = n; }
	string getSellerAddr ()				{ return sellerAddr; }
    void   setSellerAddr (string a)		{ sellerAddr = a; }
	string getBuyerAddr ()				{ return buyerAddr; }
	void   setBuyerAddr (string a)		{ buyerAddr = a; }	
	float  getAlgPrice ()				{ return algPrice; }
	void   setAlgPrice (float p)		{ algPrice = p; }	
	float  getPurchasePrice ()			{ return purchasePrice; }
	void   setPurchasePrice (float p)	{ purchasePrice = p; }	
	float  getTargetPrice ()			{ return targetPrice; }
	void   setTargetPrice (float p)		{ targetPrice = p; }	
	float  getSellPrice ()				{ return sellPrice; }
	void   setSellPrice (float p)		{ sellPrice = p; }

	void	getGalleryInformation (void);		// retrieves gallery painting information
	void	addNewPainting (void);				// inserts a gallery object in the proper place
	void	buy (void);							// allows user to buy a painting
	void	readBought (ifstream& fileName);	// reads a gallery object from fileName
	void	writeBought (ofstream& fileName);	// writes a gallery object to fileName
	void	addNewSale (void);					// records that a gallery painting has been sold
	void	sell (void);						// allows user to sell a painting found in the gallery
	void	readSold (ifstream& fileName);		// reads a sold gallery object from fileName
	void	writeSold (ofstream& fileName);		// writes a sold gallery object to fileName

}; // class GalleryPainting

#endif