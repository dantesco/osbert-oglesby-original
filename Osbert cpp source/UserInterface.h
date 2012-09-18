//
// UserInterface: This class provides numerous utility methods need in the application
//

#ifndef _UI
#define _UI

class UserInterface  
{

public:

    static void clearScreen ();							// clears the screen
    static void pressEnter ();							// waits until the user presses the <ENTER> key
    static void displayMainMenu ();						// displays the main menu containing all the options available to the user
    static void displayBuyPaintingMenu ();				// allows user to select the type of painting to be purchased
	static void displayReportMenu ();					// allows user to select the type of report to be displayed
    static void addArtist (string fn, string ln);		// inserts an artist name into the artist file
	static  int compareStr(string str1, string str2);	// compares strings while ignoring '?'

private:

	static void removeQ(string &str);					// remove all question marks from a string

};

#endif

