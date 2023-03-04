//#pragma once
#include "Employee.h"
#include <iostream>

#ifndef _COMMISSION_H
#define _COMMISSION_H

class CommissionEmployee : public Employee {
  public:
    CommissionEmployee();
    CommissionEmployee(string name, string ssn, double sales,
                       double commission);
    void set_sales(double sales);
    void set_commission(double commission);
    double get_sales() const;
    double get_commission() const;
    virtual void print_check() const;
    virtual istream &promptInput(istream &in, ostream &out);
    virtual double get_net_pay() const;

  private:
    double sales;
    double commission;
};
#endif // _COMMISSION_H
