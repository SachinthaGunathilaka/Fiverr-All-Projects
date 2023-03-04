#include "unit.h"

#include <utility>

Unit::Unit()
{
    m_name = ""; // it is a char * string, not a C++ string object.
    m_unitID = "";
    m_credits = 0;
}

Unit::Unit( const string nam, const string unitID, unsigned cred)
{
    m_name = nam;
    m_unitID= unitID;
    m_credits = cred;
}

unsigned Unit::GetCredits() const
{
    return m_credits;
}

std::string Unit::GetMUnitID() const
{
    return m_unitID;
}

void Unit::SetMUnitID(string id) {
    m_unitID = std::move(id);
}

void Unit::SetCredits( unsigned cred )
{
    m_credits = cred;
}

istream & operator >>( istream & input, Unit & U )
{
    input >> U.m_name >> U.m_unitID >> U.m_credits;
    return input;
}

ostream & operator <<( ostream & os, const Unit & U )
{
    os << "  Unit Name:  " << U.m_name    << '\n'
       << "  Unit ID  :  " << U.m_unitID  << '\n'
       << "  Credits  :  " << U.m_credits << '\n';
    return os;
}




