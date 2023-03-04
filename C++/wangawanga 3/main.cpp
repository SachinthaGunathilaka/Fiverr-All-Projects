#include <iostream>
#include "dayType.h"

int main() {
    dayType day1("Mon");
    dayType day2("Tue");
    dayType day3;

    day1.printDay();
    day2.printDay();
    day3.printDay();

    day3.setDay("Wed");
    day3.printDay();

    cout << day1.returnDay() << endl;
    cout << day1.nextDay() << endl;
    cout << day3.nextDay() << endl;
    cout << day1.previousDay() << endl;
    cout << day2.previousDay() << endl;

    cout << day1.calculateDay(15) << endl;
    return 0;
}
