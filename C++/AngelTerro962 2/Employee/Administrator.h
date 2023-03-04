/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional
 * members:
 *  1. a string type member variable to store the title (director, Vice
 * President, ... )
 *  3. Constructor functions: one default one, another taking necessary info.
 * about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start
 * with the version from SalariedEmployee
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator : public SalariedEmployee {
  public:
    Administrator();
    ~Administrator() = default;
    Administrator(string name, string ssn, double salary, string title,
                  double bonus);

    void set_title(string title);
    void set_bonus(double bonus);
    string get_title() const;
    double get_bonus() const;

    virtual double get_net_pay() const;
    virtual void print_check() const;
    virtual istream &promptInput(istream &in, ostream &out);

  private:
    string title;
    double bonus;
};

#endif
