// MAIN.CPP - Case Study, Student Registration

// Count the number of units taken by the student, calculate total credits
// author KRI
//

#include <iostream>
#include <fstream>
#include <string>
#include "unit.h"  // Unit class declaration
#include "registration.h"  // Registration class declaration
#include "result.h" // Result class declaration
#include "date.h" // Date class declaration

using namespace std;

// Main program:
// Open an input file stream, read a Registration object,
// including its list of units. Redisplay all information,
// and calculate the total credits taken. Write the results
// to a file stream.

int main()
{
    std::ifstream infile;
    infile.open( "sinput.txt" );
    if( !infile )
        return -1;

    Registration R;
    infile >> R;

    std::ofstream outfile;
    outfile.open( "soutput.txt" );

    // Use a debugger and track down the calls made "behind the scene"

    cout << R
            << "Number of units = " << R.GetCount() << '\n'
            << "Total credits   = " << R.GetCredits() << '\n';

    outfile << R;

    outfile << R
            << "Number of units = " << R.GetCount() << '\n'
            << "Total credits   = " << R.GetCredits() << '\n';
    // Declare and initialize a Unit, and modify
    // its credits.

    Unit aUnit( "Business Admin", "BB1000", 2 );
    Result aResult (aUnit, 71);
    aUnit.SetCredits(5);
    Date aDate( aResult, 04 , 01 , 2022 );

    cout << aDate << endl;

    return 0;
}

