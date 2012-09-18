#include "stdafx.h"
#include "Date.h"


Date Date::currentDate;


bool Date::parseDate (string dateStr)	// string containing date to be parsed
//
// given a valid date in the format MM/DD/YYYY, parses the
// respective parts and returns whether the date is valid
//
{
	char temp[5];	// for storing parts of date

	//
	// retrieve the year component from the date string
	//
	temp[4] = '\0';	
	temp[0] = dateStr[6];
	temp[1] = dateStr[7];
	temp[2] = dateStr[8];
	temp[3] = dateStr[9];
	year = atoi (temp);

	//
	// retrieve the day component from the date string
	//
	temp[2] = '\0';
	temp[0] = dateStr[3];
	temp[1] = dateStr[4];
	day = atoi (temp);

	//
	// retrieve the month component from the date string
	//
	temp[0]  = dateStr[0];
	temp[1]  = dateStr[1];
	month = atoi (temp);

	return validDate();  // return whether the parsed date is valid

} // parseDate

//-------------------------------------------------------------------------------------------------------------------

bool Date::validDate ()	
//
// determines if the date corresponds to a valid date
// of the form mm/dd/yyyy, where 1 <= mm <= 12, 1 <= dd <= 31, 1900 <= yyyy <= 2010
// return true iff the date is valid
//
{


	//
	// check that the year component makes sense
	//
	if ((year < 1900) || (year > 2010))
		return false;

	//
	// check that the month component makes sense
	//
	if ((month < 1) || (month > 12))
		return false;

	//
	// check that the day component makes sense
	//
	if ((day < 1) || (day > 31))
		return false;
	else
		return true;

} // validDate

//-------------------------------------------------------------------------------------------------------------------

int Date::compare (Date aDate)	
//
// determines the temporal order of two dates
// returns -1 if this < aDate
// returns 0 if the dates are the same
// returns 1 if aDate < this
//
{

	//
	// first, compare the respective years
	//
	if (year < aDate.getYear())
		return -1;

	if (year > aDate.getYear())
		return 1;

	//
	// next, compare the months
	//
	if (month < aDate.getMonth())
		return -1;

	if (month > aDate.getMonth())
		return 1;

	//
	// finally, compare the respective days
	//
	if (day < aDate.getDay())
		return -1;

	if (day > aDate.getDay())
		return 1;
	else
		return 0;

} // compare


