#include "stdafx.h"
#include "ComputeOtherPrice.h"
#include "Fashionability.h"
#include "UserInterface.h"


void ComputeOtherPrice::getAlgorithmPrice (void)
//
// determines the maximum price to be offered for an "other" piece of work
//
{
	ifstream inFile;			// stream object used for file input
	float fashionCoefficient;	// current coefficient of painting artist
	Fashionability tempFash;	// temp. fashionability object used for file reading

	fashionCoefficient = 0.0;

	inFile.open ("fash.dat", ios::in);

	if (inFile)
	{
		//
		// loop through the fashionability file to find a match with the artist
		//
		while (!inFile.eof ())
		{
			//
			// read in an object from the fashionability file
			//
			tempFash.readFash (inFile);
		
			//
			// check if there is a match with the current other object
			//
			if ((UserInterface::compareStr (tempFash.getFirstName (), firstName) == 0) &&
				(UserInterface::compareStr (tempFash.getLastName (), lastName)  == 0))
			{
				fashionCoefficient = tempFash.getCoefficient ();
				break;
			}
		
		} // while (!inFile.eof ())

		inFile.close ();

	} // if (inFile)

	algPrice = fashionCoefficient * height * width;

} // Other::determineAlgPrice
