#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Result.h"

using namespace std;

class Date
{
public:
    Date();
    Date(Result &result,unsigned day,unsigned month,unsigned year);

    unsigned GetCount() const;

    unsigned GetDay() const;
    void SetDay(unsigned day);

    unsigned GetMonth() const;
    void SetMonth(unsigned month);

    unsigned GetYear() const;
    void SetYear(unsigned year);

    void GetResult(Result &result) const;
    void SetResult(Result &result);

    friend ostream & operator <<( ostream & os, const Date & D );
    friend istream & operator >>( istream & input, Date & D );

private:
    Result m_result;
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
    unsigned count;
};

inline unsigned Date::GetCount() const
{
    return count;
}

#endif // DATE_H_INCLUDED
