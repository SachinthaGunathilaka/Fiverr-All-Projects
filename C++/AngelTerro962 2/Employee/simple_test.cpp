// DISPLAY 15.7 Using Derived Classes
#include "Administrator.h"
#include "CommissionEmployee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <iostream>
#include <vector>
using namespace std;

// payday function - using vector of pointers
void paydayPtrs(const vector<Employee *> &employeePtrs);

// payday function - using vector of pointers
void paydaySlices(const vector<Employee> &employeeSlices);

int main() {
    vector<Employee *> employeePtrs;
    vector<Employee> employeeSlices;
    int numberEmployees;

    cout << "Welcome to ABC Corporation!!\n";
    cout << "Enter the number of employees: ";
    cin >> numberEmployees;

    // Enter the number of employees
    for (int i = 0; i < numberEmployees; i++) {
        cout << "Enter employee #" << (i + 1) << ":\n";
        string type;
        cout << "Enter the type of employee (hourly, salaried, admin, "
                "commission):";
        cin >> type;

        // Request an hourly employee
        if (type == "hourly") {
            // Construct an HourlyEmployee
            HourlyEmployee *hourly = new HourlyEmployee();

            // Prompt for input
            hourly->promptInput(cin, cout);

            // Store in the vectors
            employeePtrs.push_back(hourly);
            employeeSlices.push_back(*hourly);
        } else if (type == "salaried") {
            // Construct a SalariedEmployee
            SalariedEmployee *mgmt = new SalariedEmployee();

            // Prompt for input
            mgmt->promptInput(cin, cout);

            // Add to the lists
            employeePtrs.push_back(mgmt);
            employeeSlices.push_back(*mgmt);
        } else if (type == "admin")
        // Construct an Adminstrator
        {
            Administrator *admin = new Administrator();
            admin->promptInput(cin, cout);
            employeePtrs.push_back(admin);
            employeeSlices.push_back(*admin);

        } else if (type == "commission") {
            CommissionEmployee *com = new CommissionEmployee();
            com->promptInput(cin, cout);
            employeePtrs.push_back(com);
            employeeSlices.push_back(*com);
        }
    }

    // Print pointers
    paydayPtrs(employeePtrs);
    paydaySlices(employeeSlices);

    for (int i = 0; i < employeePtrs.size(); i++) {
        delete employeePtrs[i];
    }

    return 0;
}

// Payday!
void paydaySlices(const vector<Employee> &employeeSlices) {
    cout << "***********************************************\n";
    cout << "Payday Slices! Print all checks in a batch!\n";
    for (int i = 0; i < employeeSlices.size(); i++)

    {
        cout << "Slice Check for " << employeeSlices[i].get_name() << endl;
        employeeSlices[i].print_check();
        cout << endl;
    }
}
// Payday!
void paydayPtrs(const vector<Employee *> &employeePtrs) {
    cout << "***********************************************\n";
    cout << "Payday Virtual! Print all checks in a batch!\n";
    for (int i = 0; i < employeePtrs.size(); i++) {
        cout << "Virtual Check for " << employeePtrs[i]->get_name() << endl;
        employeePtrs[i]->print_check();
        cout << endl;
    }
}
