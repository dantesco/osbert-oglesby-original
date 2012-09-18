#ifndef _COMPUTEMASTERPIECE
#define _COMPUTEMASTERPIECE


#include "GalleryPainting.h"

#define	ANNUAL_INTEREST	1.085

class ComputeMasterpiecePrice
{

public:

	float static getAlgorithmPrice (GalleryPainting* const masterpiece);	// determines the maximum price to be offered for a masterpiece

}; // class ComputeMasterpiecePrice

#endif
