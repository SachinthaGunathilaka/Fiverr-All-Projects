#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include "unit.h"

class Result
{
public:
    Result();
    Result(Unit &unit, float marks);

    float GetMarks() const;
    void GetUnit(Unit &unit) const;

    void SetMarks(float marks);
    void SetUnit(Unit &unit);

    friend ostream & operator <<( ostream & os, const Result & R );
    friend istream & operator >>( istream & input, Result & R );

private:
    Unit m_unit;
    float m_marks;
};
#endif // RESULT_H_INCLUDED
