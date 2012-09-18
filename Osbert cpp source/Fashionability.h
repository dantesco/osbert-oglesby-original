#ifndef _FASHIONABILITY
#define _FASHIONABILITY

class Fashionability
{

protected:

	string	firstName;		// first name of artist
	string	lastName;		// last name of artist
	float	coefficient;	// fashionability coefficient

public:

	// getters-setters for Fashionability
	string getFirstName ()			{ return firstName; }
    void   setFirstName (string n)  { firstName = n; }
	string getLastName ()			{ return lastName; }
	void   setLastName (string n)	{ lastName = n; }
	float  getCoefficient ()		{ return coefficient; }
	void   setCoefficient (float c)	{ coefficient = c; }

	void	getDescription (void);			// retrieves fashionability description information
	void	addNewFash (void);				// allows the user to add/update the fashionability coefficient
	void	readFash (ifstream& fileName);  // reads a fashionability object from fileName  
	void	writeFash (ofstream& fileName);	// writes a fashionability object to fileName

}; // class Fashionability

#endif
