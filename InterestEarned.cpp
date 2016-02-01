* Programmer: Chad Thornton
*
* Assigned Project Number: 3
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     01/18/2016  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  Receives input for Account Balance, expected interest rate, and times compounded.
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   Program displays text on console asking the user three questions. After it  receives input for all three
*			questions it then displays interest rate, balance, interest accrued, times compounded, and final balance.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* **** Add name and description of any other methods defined in this file ****
*
********************************************************************************/
// External Definition files
// The first inclusion file is required by the Visual Studio complier and
// MUST be first in the "include" files list
#include "stdafx.h"  // Defines IDE required "pre-compiled" definition files

#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
// -----------------
void toUpper(string&);      //Function created by Professor Robert Main
char toUpper(char);         //                 "
void toLower(string&);      //                 "
char toLower(char);         //                 "


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** Using this program you will be asked to enter a starting balance, interest 
* ** rate you expect to receive, and how many times it will be compounded.
* ** After this information has been receive the program will display on the
* ** console the information you entered as well as the interest you will make 
* ** and what your final balance will be with the interest added.
*
*
* Preconditions
* -------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
*                           *** No methods invoked ***
*
*******************************************************************************
*/

#define interestRate pow((1 + (interestRateDecimal / timesCompounded)), timesCompounded);

int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution Status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors

	// Uninitialized Variable Declarations
	string getAnswer;

	do
	{
		cout << "Hello there! Thank you for your interest in use Thornton Banking.\nI understand you what kind of return you can get using our services.\n" << endl;
		cout << "Please tell us what the principal balance will be (in USD) in your account\n(Press enter to continue)" << endl;

		string balance;   
		cin >> balance;
		regex vowel_re("[^a-zA-Z\\d\\s:]");		//Allows the ability to take the balance as a string and filters any non-numerical values
		string balanceResult = regex_replace(balance, vowel_re, "");

		double principalBalance = stod(balanceResult);

		cout << "What is your estimated interest rate percentage?\n(Press Enter to continue)" << endl;

		string percent;
		cin >> percent;
		regex percent_re("[^a-zA-Z\\d\\s:]");
		string percentResult = regex_replace(percent, percent_re, "");
		double interestRatePercent = stod(percentResult);

		double interestRateDecimal = interestRatePercent / 100;

		cout << "Thank you, and lastly how many times will this interest be compounded yearly?\n(Press enter to continue)" << endl;

		double timesCompounded;		
		cin >> timesCompounded;

		double finalBalance = principalBalance*interestRate;
		double interest = finalBalance - principalBalance;

		cout << "Thank you! Based on the values you have chosen you should receive the following return:\n" << endl;

		cout << fixed << showpoint << setprecision(2);	//Restricted values to show only to the hundreth decimal place.

		cout << left << setw(12) << "Interest Rate:"	//setw() used in formatting
			<< right << setw(15) << interestRatePercent << "%" << endl;
		cout << fixed << showpoint << setprecision(0);
		cout << left << setw(12) << "Times Compounded:"
			<< right << setw(12) << timesCompounded << endl;
		cout << fixed << showpoint << setprecision(2);
		cout << left << setw(12) << "Principal:"
			<< right << setw(9) << "$" << setw(8) << principalBalance << endl;
		cout << left << setw(12) << "Interest:"
			<< right << setw(9) << "$" << setw(8) << interest << endl;
		cout << left << setw(12) << "Final Balance:"
			<< right << setw(7) << "$" << setw(8) << finalBalance << endl;

		cout << "\n\nWould you like to enter different values?" << endl;
		cout << "(Input 'Yes' followed by Enter to continue)\n(Input 'No' followed by Enter to exit the program)\n" << endl;

		cin >> getAnswer;
		toLower(getAnswer);
	}

	while (getAnswer == "yes");

	cout << "\nThank you for choosing Thornton Banking, have a nice day!\n" << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()



void toUpper(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toUpper(str[index]);
}

char toUpper(char chr)
{
	if (chr >= 'a' && chr <= 'z')
	{
		unsigned short excludeBit = 'a' - 'A';
		chr = chr ^ excludeBit;
	}

	return chr;
}

void toLower(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toLower(str[index]);
}

char toLower(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		unsigned short includeBit = 'a' - 'A';
		chr = chr | includeBit;
	}

	return chr;
}