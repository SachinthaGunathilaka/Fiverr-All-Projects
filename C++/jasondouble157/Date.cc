
#include "Date.h"

Date::Date() {
    setDate(1, 1, 1901);
    setHour(0);
    setDuration(1);
}

Date::Date(int y, int m, int d, int h, int duration) {
    setDate(y, m, d);
    setHour(h);
    setDuration(duration);
}

//setters
void Date::setDay(int d) {
    int max = getMaxDay();
    if (d > max) d = max;
    if (d < 1) d = 1;
    day = d;
}

void Date::setMonth(int m) {
    if (m > 12) m = 12;
    if (m < 1) m = 1;
    month = m;
}

void Date::setYear(int y) {
    if (y < 1901) y = 1901;
    year = y;
}

void Date::setDate(int y, int m, int d) {
    setMonth(m);
    setDay(d);
    setYear(y);
}

void Date::setDate(Date &d) {
    setDate(d.day, d.month, d.year);
    setHour(d.hour);
    setDuration(d.duration);

}

void Date::setHour(int h) {
    if (h < 0)
        h = 0;
    if (h > 23)
        h = 23;

    this->hour = h;
}

void Date::setDuration(int d) {
    if (d < 1)
        d = 1;
    if (d > max_duration)
        d = max_duration;
    this->duration = d;;
}


//getters
int Date::getDay() { return day; }

int Date::getMonth() { return month; }

int Date::getYear() { return year; }

int Date::getHour() { return hour; }

int Date::getDuration() { return duration; }

const string &Date::getMonthName() { return months[month - 1]; }


//other

bool Date::lessThan(Date &d) {
    if (year == d.year) {
        if (month == d.month) {
            if (day == d.day) {
                return hour < d.hour;
            } else {
                return day < d.day;
            }
        } else {
            return month < d.month;
        }
    } else {
        return year < d.year;
    }
}

void Date::print() {
    cout << "Date : " << getMonthName() << " " << getDay() << ", " << getYear();
    cout << "  Hour : " << getHour() << "  Duration : " << getDuration() << endl;
}

int Date::getMaxDay() {
    switch (getMonth()) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28;
        default:
            return 31;
    }
}

bool Date::overlaps(Date &d) {
    if (year != d.year || month != d.month || day != d.day)
        return false;

    if ((hour <= d.hour) && ((hour + duration) > d.hour)) {
        return true;
    }

    if ((hour >= d.hour) && ((d.hour + d.duration) > hour)) {
        return true;
    }
    return false;


}

