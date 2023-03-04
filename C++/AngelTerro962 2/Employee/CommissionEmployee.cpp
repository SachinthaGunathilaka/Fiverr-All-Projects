#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee() : Employee() {}
CommissionEmployee::CommissionEmployee(string name, string SSN, double sales,
                                       double commission)
    : Employee(name, SSN), sales(sales), commission(commission) {}

void CommissionEmployee::set_sales(double sales) { this->sales = sales; }

void CommissionEmployee::set_commission(double commission) {
    this->commission = commission;
}

double CommissionEmployee::get_sales() const { return sales; }

double CommissionEmployee::get_commission() const { return commission; }

double CommissionEmployee::get_net_pay() const {
    return commission / 100 * sales;
}

void CommissionEmployee::print_check() const {
    Employee::print_check();
    cout << "Sales: " << get_sales() << endl;
    cout << "Commission: " << get_commission() << endl;
}

istream &CommissionEmployee::promptInput(istream &in, ostream &out) {
    Employee::promptInput(in, out);
    out << "Enter sales and commission (each on its own line):" << endl;
    string s_sales, s_commission;
    getline(in, s_sales);
    getline(in, s_commission);
    sales = stoi(s_sales);
    commission = stoi(s_commission);
    return in;
}
