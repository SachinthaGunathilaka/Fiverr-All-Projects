#include "Date.h"

Date::Date() {
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(int day, int month, int year) {
    m_day = day;
    m_month = month;
    m_year = year;
}

int Date::GetDay() const {
    return m_day;
}

void Date::SetDay(int day) {
    m_day = day;
}

int Date::GetMonth() const {
    return m_month;
}

void Date::SetMonth(int month) {
    m_month = month;
}

int Date::GetYear() const {
    return m_year;
}

void Date::SetYear(int year) {
    m_year = year;
}

string Date::getDateString() {
    return to_string(GetYear()) + "/" + to_string(GetMonth());

}

istream &operator>>(istream &input, Date &date)   // overloaded input stream operator
{
    string temp;

    //set day
    getline(input, temp, '/');
    date.SetDay(stoi(temp));

    // set month
    getline(input, temp, '/');
    date.SetMonth(stoi(temp));

    // set year
    getline(input, temp, ' ');
    date.SetYear(stoi(temp));


    return input;
}

ostream &operator<<(ostream &output, const Date &date)    // overloaded output stream operator
{
    output << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear();
    return output;
}
