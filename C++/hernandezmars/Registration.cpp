#include "registration.h"

Registration::Registration()
{
    count = 0;
}

unsigned Registration::GetCredits() const
{
    unsigned sum = 0;
    Result result;
    Unit unit;

    for(unsigned i = 0; i < count; i++)
    {
        m_date[i].GetResult(result);
        result.GetUnit(unit);

        sum += unit.GetCredits();
    }

    return sum;
}


std::istream & operator >>( std::istream & input, Registration & R )
{
    input >> R.studentId >> R.semester >> R.count;

    Result temp_result;
    for(unsigned i = 0; i < R.count; i++)
    {
        input >> R.m_date[i];  // track down which >> operator is called. Hint: look at what is being input.
    }

    return input;
}

std::ostream & operator <<( std::ostream & os, const Registration & R )
{
    os << "Student ID: " << R.studentId << '\n'
       << "Semester:   " << R.semester << '\n';

    for(unsigned i = 0; i < R.count; i++)
    {
        os << R.m_date[i] << '\n';
    }

    return os;
}
