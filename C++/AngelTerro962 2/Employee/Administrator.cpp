/* Implement Administrator class */
#include "Administrator.h"
#include <iostream>

using namespace std;

Administrator::Administrator() : SalariedEmployee() {}
Administrator::Administrator(string name, string SSN, double salary,
                             string title, double bonus)
    : SalariedEmployee(name, SSN, salary), title(title), bonus(bonus)

{
    // deliberately empty
    // cout << "Adminstrator(" << name << "," << SSN << "," << salary << "," <<
    // title << ")\n";
}

void Administrator::set_title(string title) { this->title = title; }

void Administrator::set_bonus(double bonus) { this->bonus = bonus; }

string Administrator::get_title() const { return title; }

double Administrator::get_bonus() const { return bonus; }

double Administrator::get_net_pay() const { return get_salary() + bonus; }

void Administrator::print_check() const {
    SalariedEmployee::print_check();
    cout << "Administrator full pay: " << get_net_pay() << endl;
}

istream &Administrator::promptInput(istream &in, ostream &out) {
    SalariedEmployee::promptInput(in, out);
    out << "Enter bonus, and title: ";
    ignorespace(in);
    in >> bonus;
    in >> title;
    return in;
}
