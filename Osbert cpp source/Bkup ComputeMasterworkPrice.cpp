#include "stdafx.h"
#include "ComputeMasterworkPrice.h"
#include "ComputeMasterpiecePrice.h"


float ComputeMasterworkPrice::getAlgorithmPrice (GalleryPainting* const masterwork)
//
// determines the maximum price to be offered for a masterwork
//
{
	int	century;				// century in which painting was created
    float masterpiecePrice;		// value if masterpiece
	//
	// first, compute the price of the painting as if it were a masterpiece
	//
	masterpiecePrice = ComputeMasterpiecePrice::getAlgorithmPrice (masterwork);

	//
	// next, obtain the century in which the painting was created and adjust
	// the price based upon the century
	//
	century = masterwork->getPaintDate().getYear() / 1000;

	if (century == 19)
		return masterpiecePrice * 0.25;
	else
		return masterpiecePrice * (20 - century) / (21 - century);

} // ComputeMasterworkPrice::getAlgorithmPrice