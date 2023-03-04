#include "dayType.h"

dayType::dayType() {
    this->day = "Sun";
}

dayType::dayType(string day) {
    this->day = day;
}

void dayType::setDay(string day){
    this->day = day;
}

string generateFullName(string day){
    string complete_day = day;
    if(day == "Tue")
        complete_day += "sday";
    else if(day == "Wed")
        complete_day += "nesday";
    else if(day == "Thu")
        complete_day += "rsday";
    else if(day == "Sat")
        complete_day += "urday";
    else
        complete_day += "day";

    return complete_day;
}

void dayType::printDay() {
    cout << generateFullName(day) << endl;

}

string dayType::returnDay() {
    return generateFullName(day);
}

string dayType::nextDay() {
    int index;
    for (index = 0; index < 7; ++index) {
        if(days[index] == day)
            break;
    }
    index++;

    if(index == 7)
        index = 0;

    return generateFullName(days[index]);
}

string dayType::previousDay() {
    int index;
    for (index = 0; index < 7; ++index) {
        if(days[index] == day)
            break;
    }
    index--;

    if(index == -1)
        index = 0;

    return generateFullName(days[index]);
}

string dayType::calculateDay(int num_of_days) {
    int index;
    for (index = 0; index < 7; ++index) {
        if(days[index] == day)
            break;
    }

    index += num_of_days;
    index %= 7;

    return generateFullName(days[index]);
}


