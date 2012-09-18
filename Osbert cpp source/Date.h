#ifndef _DATE
#define _DATE

class Date  
{

public:

	//initialize to 1/1/1900
	Date() { year = 1900; month = 1; day = 1; }

	// getter-setters for Date
	int getYear()			{ return year; }
	int getMonth()			{ return month; }
	int getDay()			{ return day; }
	void setYear(int y)		{ year = y; }
	void setMonth(int m)	{ month = m; }
	void setDay(int d)		{ day = d; }

	// date methods
	bool parseDate (string dateStr);
	int  compare (Date aDate);	
    void subtractOneYear () { year--; }

	// define the i/o stream operator for date
	friend std::ostream &operator<<(std::ostream &o, const Date &d)
	{
		if(d.month < 10)
           o << "0";
		o << d.month << "/";
		if(d.day < 10)
			o<< "0";
		o << d.day << "/" << d.year;
		return o;
	}

    static Date currentDate;	// contains today's date

private:

	bool validDate ();			// are the values for a date valid?	
    int year, month, day;		// year, month, and day of a date

};

#endif
