#ifndef WINDLOG_H_INCLUDED
#define WINDLOG_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Time.h"
#include "Old Files/Vector.h"

using namespace std;

/**
* @class WindLogType
* @brief Manages the WinLog while passing other object into the class
*
* Contains private variables for speed, solar radiation and temperature. Also contains
* composition of Date and Time classes. Contains Get Set methods for the aforementioned,
* private variables and functions that cannot be accessed outside the class without the appropriate
* get methods.
*
* @author Joshua Oh
* @version 01
* @date 14/10/2022 Joshua Oh, Started by creating the needed variables and functions.
*
* @author Joshua Oh
* @version 02
* @date 16/10/2022 Joshua Oh, Linked overloaded operator with Date and Time classes.
*
*
* @todo Submit to LMS.
*
* @bug Hopefully none.
*/

class WindLogType
{
private:
    /// private Date object composition
    Date m_date;

    /// private Time object composition
    Time m_time;

    /// private float variable for speed in m/s
    float m_speed;

    /// private float variable for solar radiation in W/m2
    float m_solarRadiation;

    /// private float variable for temperature
    float m_temperature;

public:

        /**
        * @brief    default constructor for WindLogType object
        *
        *           default constructor with no parameters to be passed.
        *           Set to default values.
        *
        */

    WindLogType();

        /**
        * @brief    overloaded constructor with 5 parameters
        *
        * @param    Date &date - reference to Date object. Time &time -
        *           Reference to Time object. float speed - wind speed.
        *           float sr - amount of solar radiation.
        *           float temp - temperature.
        *
        */

    WindLogType(Date &date, Time &time, float speed, float sr, float temp);

        /**
        * @brief    function to get the date from the Date object
        *
        *           Assessor function to retrieve the date by passing a
        *           reference of the date object
        * @param    Date &date - Reference of Date object,
        * @return   void
        *
        */

    void GetDate(Date &date) const;

        /**
        * @brief    function to get the time from the Time object
        *
        *           Assessor function to retrieve the time by passing a
        *           reference of the Time object
        * @param    Time &time - Reference of Time object
        * @return   void
        *
        */

    void GetTime(Time &time) const;

        /**
        * @brief    function to get the speed
        *
        *           Assessor function to retrieve the wind speed. Passing
        *           no parameters and returning the speed.
        *
        * @return   float
        *
        */

    float GetSpeed() const;

        /**
        * @brief    function to get solar radiation
        *
        *           Assessor function to retrieve the solar radiation. Passing
        *           no parameters and returning the solar radiation.
        *
        * @return   float
        *
        */

    float GetSolarRadiation() const;

        /**
        * @brief    function to get the temperature
        *
        *           Assessor function to retrieve the temperature. Passing
        *           no parameters and returning the temperature.
        *
        * @return   float
        *
        */
    float GetTemperature() const;

        /**
        * @brief    function to set the date
        *
        *           Mutator function to set the date object.
        * @pre      Date object is not null.
        * @param    Date &date - Reference to date object
        * @return   void
        *
        */

    void SetDate(Date &date);

        /**
        * @brief    function to set the time
        *
        *           Mutator function to set the Time object.
        * @pre      Time object is not null.
        * @param    Time &time - Reference to Time object
        * @return   void
        *
        */

    void SetTime(Time &time);

        /**
        * @brief    function to set the speed
        *
        *           Mutator function to set the wind speed.
        *
        * @param    float speed - float variable for speed
        * @return   void
        *
        */

    void SetSpeed(float speed);

        /**
        * @brief    function to set the solar radiation
        *
        *           Mutator function to set the solar radiation.
        *
        * @param    float solarRadiation - float variable for solar radiation
        * @return   void
        *
        */

    void SetSolarRadiation(float solarRadiation);

        /**
        * @brief    function to set the temperature
        *
        *           Mutator function to set the temperature.
        *
        * @param    float temperature - float variable for temperature
        * @return   void
        *
        */

    void SetTemperature(float temperature);

};

    /**
    * @brief    Unfriended overloaded istream >> operator
    *
    *           An overloaded istream >> operator unique to the Windlog class
    *           Takes in input from the Windlog class and input stream
    *           and returns the input
    *
    * @param    istream & input - Input stream, WindLogType &wl - Reference for Windlog object
    * @return   input
    */

istream &operator >>(istream &input, WindLogType &w1);

    /**
    * @brief    Unfriended overloaded ostream << operator
    *
    *           An overloaded ostream << operator unique to the Windlog class
    *           Takes output from the Windlog class and ostream
    *           and returns the output
    *
    * @param    ostream & output - Output stream, WindLogType &wl - Reference for Windlog object
    * @return   output
    */

ostream &operator <<(ostream &output, const WindLogType &w1);


#endif // WINDLOG_H_INCLUDED
