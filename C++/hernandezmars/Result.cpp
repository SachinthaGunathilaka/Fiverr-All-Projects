#include "Result.h"

Result::Result()
{
    m_marks = 0;
}

Result::Result(Unit &unit,float marks)
{
    m_unit = unit;
    m_marks = marks;
}

float Result::GetMarks() const
{
    return m_marks;
}

void Result::GetUnit(Unit &unit) const
{
    unit = m_unit;
}

void Result::SetMarks(float marks)
{
    m_marks = marks;
}

void Result::SetUnit(Unit &unit)
{
    m_unit = unit;
}

ostream & operator <<( ostream & os, const Result & R )
{
    os << R.m_unit
        << "  Marks    :  " << R.m_marks << '\n';
    return os;
}
istream & operator >>( istream & input, Result & R )
{
    input >> R.m_unit >> R.m_marks;
    return input;
}
