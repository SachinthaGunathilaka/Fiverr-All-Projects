#include "date.h"

Date::Date()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(Result &result, unsigned day, unsigned month, unsigned year)
{
    m_result = result;
    m_day = day;
    m_month = month;
    m_year = year;
}

unsigned Date::GetDay() const
{
    return m_day;
}

void Date::SetDay(unsigned day)
{
    m_day = day;
}

void Date::SetMonth(unsigned month)
{
    m_month = month;
}

unsigned Date::GetMonth() const
{
    return m_month;
}

void Date::SetYear(unsigned year)
{
    m_year =  year;
}

unsigned Date::GetYear() const
{
    return m_year;
}

void Date::GetResult(Result &result) const
{
    result = m_result;
}

void Date::SetResult(Result &result)
{
    m_result = result;
}

istream & operator >>( istream & input, Date & D )
{
    input >> D.m_result >> D.m_day >> D.m_month >> D.m_year;
    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os << D.m_result
        << "  Date     :  " << D.m_day << "-" << D.m_month << "-" << D.m_year << '\n';
    return os;
}

