#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>      /// to setfill and setw for 00 minutes.

using namespace std;

/**
* @class Time
* @brief Manages the time
*
* Contains private variables for hours and minutes for the Time object.
* Get Set methods for the aforementioned,
* private variables that cannot be accessed outside the class without the appropriate
* get methods.
*
* @author Joshua Oh
* @version 01
* @date 14/10/2022 Joshua Oh, Started by creating the needed variables and functions.
*
* @author Joshua Oh
* @version 02
* @date 16/10/2022 Joshua Oh, Done up overloaded operators.
*
*
* @todo Submit to LMS.
*
* @bug Hopefully none.
*/

class Time
{

private:
    /// private int variable for minutes
    int m_minutes;

    /// private int variable for hours
    int m_hours;
public:

        /**
        * @brief    default constructor for Date object
        *
        *           default constructor with no parameters to be passed.
        *           set to default values.
        *
        */

    Time();

        /**
        * @brief    overloaded constructor with 2 parameters
        *
        * @param    int hours - represents the hour hand.
        *           int monutes - represents the minute hand.
        * @pre      Hours is between 1 - 24 and minutes is
        *           between 1 - 60
        *
        */

    Time(int hours, int minutes);

        /**
        * @brief    function to get the minutes
        *
        *           Assessor function to retrieve the minutes for the time. Passing
        *           no parameters and returning the minutes.
        * @pre      Minutes is between 1 - 60
        * @return   int
        *
        */

    int GetMinutes() const;

        /**
        * @brief    function to get the hours
        *
        *           Assessor function to retrieve the hours for the time. Passing
        *           no parameters and returning the hours.
        * @pre      Minutes is between 1 - 24
        * @return   int
        *
        */

    int GetHours() const;

        /**
        * @brief    function to set the minutes
        *
        *           Mutator function to set the minutes for the time.
        * @pre      Minutes is between 1 - 60
        * @param    int minutes - represents the minute hand
        * @return   void
        *
        */

    void SetMinutes(int minutes);

        /**
        * @brief    function to set the hours
        *
        *           Mutator function to set the hours for the time.
        * @pre      Hours is between 1 - 24
        * @param    int hours - represents the hours hand
        * @return   void
        *
        */

    void SetHours(int hours);

};

    /**
    * @brief    Unfriended overloaded istream >> operator
    *
    *           An overloaded istream >> operator unique to the Time class
    *           Takes in input from the Time class and istream
    *           and returns the input
    *
    * @param    istream & input - Input stream, Time &time - Reference for Time object
    * @return   input
    */

istream &operator >>( istream &input, Time &time );

    /**
    * @brief    Unfriended overloaded ostream << operator
    *
    *           An overloaded ostream << operator unique to the Time class
    *           Takes output from the Time class and ostream
    *           and returns the output
    *
    * @param    ostream & os - Output stream, Time &time - Reference for Time object
    * @return   output
    */

ostream &operator <<( ostream &os, const Time &time );

#endif // TIME_H_INCLUDED
