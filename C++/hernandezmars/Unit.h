#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string> // C string library

using namespace std;

const unsigned UNIT_NAME_SIZE = 50;
const unsigned UNIT_ID_SIZE = 10;

class Unit {
public:
    Unit();

    Unit(const string nam, const string unitID, unsigned cred);
    // Construct a unit from a name, section letter,
    // and number of credits.

    // Get the number of credits.
    unsigned GetCredits() const;

    // Set the number of credits.
    void SetCredits(unsigned cred);

    // Get the number of credits.
    string GetMUnitID() const;

    // Set the number of credits.
    void SetMUnitID(string id);

    // These operators have been made friends. They have
    // privileged access to class internals.
    // Very useful for debugging the class, but not very good for class design.
    // We will keep using it for now but you will have a chance in a later lab
    // to redesign this class.
    friend ostream &operator<<(ostream &os, const Unit &U);

    friend istream &operator>>(istream &input, Unit &U);

private:
    string m_name;  // unit name, C style string. not a C++ string object
    string m_unitID;   // section (letter) can be enrolment mode
    unsigned m_credits;   // number of credits
};

#endif
