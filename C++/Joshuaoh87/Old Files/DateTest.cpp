#include "../Date.h"

using namespace std;

int main()
{
//    // Construct a Date with default constructor
//    Date date();
//    cout << "Constructed date with default constructor: " << date << endl;

    // Construct a Date with parameterized constructor
    Date NewDate(12,06,2022);
    cout << "Constructed Date: " << NewDate << endl;

    // Set Day
    NewDate.SetDay(31);
    cout << "After setting day: " << NewDate << endl;

    // Set a new Month
    NewDate.SetMonth(12);
    cout << "After setting month: " <<NewDate << endl;

    // Set a New Year
    NewDate.SetYear(1987);
    cout << "After setting year: " << NewDate << endl;

    cout << "New Day: "  << NewDate.GetDay() << endl;

    cout << "New Month: " << NewDate.GetMonth() << endl;

    cout << "New Year: " << NewDate.GetYear() << endl;


    return 0;
}
