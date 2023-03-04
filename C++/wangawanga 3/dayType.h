#include<string>
#include<iostream>
using namespace std;

static string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
class dayType {
private:
    string day;

public:
    dayType();
    dayType(string day);
    void setDay(string day);
    void printDay();
    string returnDay();
    string nextDay();
    string previousDay();
    string calculateDay(int num_of_days);



};
