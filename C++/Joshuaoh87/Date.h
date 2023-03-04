#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**
* @class Date
* @brief Manages the date
*
* Contains private variables for day, month and year for the date object.
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

class Date
{
private:
    /// private int variable for day
    int m_day;

    /// private int variable for month
    int m_month;

    /// private int variable for year
    int m_year;

public:

        /**
        * @brief    default constructor for Date object
        *
        *           default constructor with no parameters to be passed.
        *           set to default values.
        *
        */

    Date();

        /**
        * @brief    overloaded constructor with 3 parameters
        *
        * @param    int day - day of the date. int month - month of the date
        *           int year - year of the date.
        * @pre      Day is greater than 0 but smaller than 32. Month
        *           is between 1 - 12 and year cannot be negative.
        *
        */

    Date(int day, int month, int year);

        /**
        * @brief    function to get the day
        *
        *           Assessor function to retrieve the day of the date. Passing
        *           no parameters and returning the day.
        * @return   int
        *
        */

    string getDateString();
    int GetDay() const;

        /**
        * @brief    function to set the day
        *
        *           Mutator function to set the day of the date.
        *
        * @param    int day - day variable of the date.
        * @pre      Day is greater than 0 but smaller than 32.
        * @return   void
        *
        */

    void SetDay(int day);

        /**
        * @brief    function to get the month
        *
        *           Assessor function to retrieve the month of the date. Passing
        *           no parameters and returning the month.
        * @pre      Month is between 1 - 12
        * @return   int
        *
        */

    int GetMonth() const;

        /**
        * @brief    function to set the month
        *
        *           Mutator function to set the month of the date
        * @pre      Month is between 1 - 12
        * @param    int month - month variable of the date
        * @return   void
        *
        */

    void SetMonth(int month);

        /**
        * @brief    function to get the year
        *
        *           Assessor function to retrieve the year of the date. Passing
        *           no parameters and returning the year.
        * @pre      Year cannot be negative
        * @return   int
        */

        int GetYear() const;

        /**
        * @brief    function to set the year
        *
        *           Mutator function to set the year of the date
        *
        * @param    int year - year variable of the date
        * @pre      year cannot be negative
        * @return   void
        */

    void SetYear(int year);

        /**
        * @brief    function to set the year for reading into in
        *
        *           Assessor function to retrieve the year of the date.
        * @pre      Year cannot be negative
        * @return   int
        */
};

    /**
    * @brief    Unfriended overloaded istream >> operator
    *
    *           An overloaded istream >> operator unique to the Date class
    *           Takes in input from the Date class and istream
    *           and returns the input
    *
    * @param    istream & input - Input stream, Date &date - Reference for Date object
    * @return   input
    */

istream &operator >>( istream &input, Date &date );

    /**
    * @brief    Unfriended overloaded ostream << operator
    *
    *           An overloaded ostream << operator unique to the Date class
    *           Takes output from the Date class and ostream
    *           and returns the output
    *
    * @param    ostream & os - Output stream, Date &date - Reference for Date object
    * @return   output
    */

ostream &operator <<( ostream &os, const Date &date );

#endif // DATE_H_INCLUDED
