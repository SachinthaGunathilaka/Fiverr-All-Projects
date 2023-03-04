// REGIST.H - Registration class definition
// author KRI
// modified smr

#ifndef REGIST_H
#define REGIST_H

#include <string>
#include <iostream>
#include "result.h"
#include "date.h"

using namespace std;

const unsigned MAX_RESULTS = 100;
const unsigned MAX_DATE = 100;

class Registration {
public:
  Registration();

  Registration(std::string studentId, std::string semester);

  void setStudentID(std::string studentId);
  void setSemester(std::string semester);

  std::string getStudentId();
  std::string getSemester();

  unsigned GetCredits() const;
  unsigned GetCount() const;

  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend std::ostream & operator <<( std::ostream & os,
         const Registration & R);

  friend std::istream & operator >>( std::istream & input,
         Registration & R );

private:
  std::string studentId;             // student ID number
  std::string semester;          // semester year, number
  unsigned count;             // number of results
  Date m_date[MAX_DATE]; //array of dates
};

inline unsigned Registration::GetCount() const
{
  return count;
}

#endif

