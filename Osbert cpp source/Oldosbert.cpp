
//
// This is a C++ implementation of the Osbert Oglesby Case Study
// as described in Section 14.13 of "Classical and Object-Oriented
// Software Engineering," Fourth Edition, by Stephen R. Schach
//
// It was developed using Microsoft Visual C++ version 5.0
//==================================================================

#include	<stdio.h>
#include	<stdlib.h>
#include	<fstream>
#include	<ctype.h>
#include	<string>

#include	<ostream>
#include	<iostream>

using namespace std;



//
// constants
//
#define	TARGET_MARKUP	2.15
#define	ANNUAL_INTEREST	1.085










//-------------------------------------------------------------------------------------------------------------------

void stringLower (char *s)		// the string to convert to lowercase
//
// converts characters of string s to lowercase if needed
//
{
	int				i;				// index counter for string s

	for (i = 0; i <= strlen (s); i++)
	//
	// change the current character to lowercase if needed
	//
	if (isupper(s[i]))
		s[i] = tolower(s[i]);

} // stringLower

//-------------------------------------------------------------------------------------------------------------------



