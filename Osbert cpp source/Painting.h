#ifndef _PAINTING
#define _PAINTING


#include "Date.h"

class Painting
{

protected:

	string firstName;	// first name of artist
	string lastName;	// last name of artist
	string title;		// title of painting
    Date   paintingDate;// date painting was created
	Date   saleDate;	// date painting was sold
	string medium;		// medium of painting
	string subject;		// subject of painting
	float  height;		// height of painting (in cm)
	float  width;		// width of painting (in cm)

public:

	// getters-setters for Painting
	string	getFirstName ()			{ return firstName; }
    void	setFirstName (string fn) { firstName = fn; }
	string	getLastName ()			{ return lastName; }
    void	setLastName (string ln) { lastName = ln; }
	string	getTitle ()				{ return title; }
    void	setTitle (string t)		{ title = t; }
	Date	getPaintDate ()			{ return paintingDate; }
	Date	getSaleDate ()			{ return saleDate; }
    void	setSaleDate (Date d)	{ saleDate = d; }	
	string	getMedium ()			{ return medium; }
    void	setMedium (string m)	{ medium = m; }
	string	getSubject ()			{ return subject; }
    void	setSubject (string s)	{ subject = s; }
	float	getHeight ()			{ return height; }
    void	setHeight (float h)		{ height = h; }
	float	getWidth ()				{ return width; }
    void	setWidth (float w)		{ width = w; }

	void	getDescription ();	// get painting description

}; // class Painting

#endif
