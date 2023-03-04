#include "Windlog.h"

int main()
{
    // Create a Date
    Date date(11,11,2004);
    cout << "Date: " << date << endl;

    //Create Time
    Time time(10,26);
    cout << "Time: " << time << endl;

    // Create windlog object
    WindLogType wl(date, time, 23, 3, 32.1);
    cout << "WindLog: " << wl << endl;

    //Set new date
    Date newDate(12,12,2012);
    wl.SetDate(newDate);
    cout << "After setting new date : " << wl << endl;

    //Set new time
    Time newTime(5,55);
    wl.SetTime(newTime);
    cout << "After setting new time: " << wl << endl;

    //Set wind speed
    wl.SetSpeed(100);
    cout << "After setting new speed: " << wl << endl;

    //Set Solar Radiation
    wl.SetSolarRadiation(0);
    cout << "After setting new solar radiation: " << wl << endl;

    //Set temperature
    wl.SetTemperature(25.4);
    cout << "After setting new temperature: " << wl << endl;

    //Get date
    Date retrieveDate;
    wl.GetDate(retrieveDate);
    cout << "The new date is " << retrieveDate << endl;

    //Get Time
    Time retrieveTime;
    wl.GetTime(retrieveTime);
    cout << "The new time is " << retrieveTime << endl;

    //Get speed, sr and temp
    cout << "The new speed is " << wl.GetSpeed() << endl;

    cout << "The new solar radiation is " << wl.GetSolarRadiation() << endl;

    cout << "The new temperature is " << wl.GetTemperature() << endl;



    return 0;
}
