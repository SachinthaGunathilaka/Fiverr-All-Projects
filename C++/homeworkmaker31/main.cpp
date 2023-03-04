#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// Employee Parent class
class Employee {
protected:
    string surname;
    string firstName;
    string dateOfBirth;
    int holidaysAlreadyTaken;

public:
    Employee() {

    }

    Employee(const string &surname, const string &firstName, const string &dateOfBirth)
            : surname(surname), firstName(firstName), dateOfBirth(dateOfBirth) {
        holidaysAlreadyTaken = 0;
    }

    const string &getSurname() const {
        return surname;
    }

    const string &getFirstName() const {
        return firstName;
    }

    const string &getDateOfBirth() const {
        return dateOfBirth;
    }

    int getHolidaysAlreadyTaken() const {
        return holidaysAlreadyTaken;
    }

    void requestingHoliday(int count) {
        this->holidaysAlreadyTaken += count;
    }

    virtual double returnHourlyWage() { return 0; }

    virtual double returnHoursWorked() { return 0; }

    virtual double returnAnnualSalary() { return 0; }

    virtual double returnProfitSharing() { return 0; }

};


// Hourly Employee(Sub class)
class HourlyEmployee : public Employee {
private:
    double hourlyWage;
    double hoursWorked;

public :

    HourlyEmployee() {

    }

    HourlyEmployee(string surname, string firstName, string dob, double hourlyWageInput, double hoursWorkedInput)
            : Employee(surname, firstName, dob) {

        this->hourlyWage = hourlyWageInput;
        this->hoursWorked = hoursWorkedInput;
    }

    double returnHourlyWage() {
        return this->hourlyWage;
    }

    double returnHoursWorked() {
        return this->hoursWorked;
    }
};


// Salaried Employee(Sub class)
class SalariedEmployee : public Employee {
private:
    double annualSalary;

public :

    SalariedEmployee() {

    }

    SalariedEmployee(string surname, string firstName, string dob, double annualSalaryInput) : Employee(surname,
                                                                                                        firstName,
                                                                                                        dob) {
        this->annualSalary = annualSalaryInput;
    }

    double returnAnnualSalary() {
        return this->annualSalary;
    }
};


// Manager(Sub class)
class Manager : public Employee {
private:
    double profitSharing;

public :

    Manager() {

    }

    Manager(string surname, string firstName, string dob, double profitSharingInput) : Employee(surname, firstName,
                                                                                                dob) {
        this->profitSharing = profitSharingInput;
    }

    double returnProfitSharing() {
        return this->profitSharing;
    }

};


// Define 3 array for each employees
HourlyEmployee hourlyEmployees[500];
SalariedEmployee salariedEmployees[500];
Manager managers[500];
int hourlyEmployeesCount = 0;
int salariedEmployeesCount = 0;
int managersCount = 0;


// Method to create an employee
void createEmployee() {
    char empType = 'a';

    while (toupper(empType) != 'M' && toupper(empType) != 'S' && toupper(empType) != 'H') {
        cout << "\nEnter the type of the employee (Manager - M / Salaried Employee - S / Hourly Employee - H ) : ";
        cin >> empType;
        cin.ignore();
    }

    string firstName, surName, dob;
    double hourlyWage = 0, hoursWorked = 0, annualSalary = 0, profitSharing = 0;

    cout << "Surname of the employee          : ";
    cin >> surName;

    cout << "Firstname of the employee        : ";
    cin >> firstName;

    cout << "DOB of the employee [yyyy/mm/dd] : ";
    cin >> dob;

    if (toupper(empType) == 'H') {
        cout << "Hourly Wage                      : ";
        cin >> hourlyWage;
        cin.ignore();

        cout << "Hours worked                     : ";
        cin >> hoursWorked;
        cin.ignore();

        HourlyEmployee employee(surName, firstName, dob, hourlyWage, hoursWorked);
        hourlyEmployees[hourlyEmployeesCount++] = employee;
    }

    if (toupper(empType) == 'S') {
        cout << "Annual Salary                    : ";
        cin >> annualSalary;
        cin.ignore();

        SalariedEmployee employee(surName, firstName, dob, annualSalary);
        salariedEmployees[salariedEmployeesCount++] = employee;
    }

    if (toupper(empType) == 'M') {
        cout << "Profit Sharing                   : ";
        cin >> profitSharing;
        cin.ignore();

        Manager manager(surName, firstName, dob, profitSharing);
        managers[managersCount++] = manager;
    }

    string date;
    int maximumHolidays;



//
}


// Method to display an employee
void displayEmployees() {
    //printing all the details about hourly employees
    cout << "\n--- HOURLY EMPLOYEES ---\n" << setw(25) << "Surname" << setw(25) << "First Name" << setw(25) << "DOB"
         << setw(25) << "Taken Holidays" << setw(25) << "Hourly Wage" << setw(25) << "Hours Worked" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
            << endl;

    for (int i = 0; i < hourlyEmployeesCount; ++i) {
        cout << setw(25) << hourlyEmployees[i].getSurname() << setw(25) << hourlyEmployees[i].getFirstName() << setw(25)
             << hourlyEmployees[i].getDateOfBirth() << setw(25) << hourlyEmployees[i].getHolidaysAlreadyTaken()
             << setw(25)
             << hourlyEmployees[i].returnHourlyWage() << setw(25) << hourlyEmployees[i].returnHoursWorked() << endl;
    }




    //printing all details about salaried employees
    cout << "\n--- SALARIED EMPLOEES ---\n" << setw(25) << "Surname" << setw(25) << "First Name" << setw(25) << "DOB"
         << setw(25) << "Taken Holidays" << setw(25) << "Annual Salary" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
            << endl;

    for (int i = 0; i < salariedEmployeesCount; ++i) {
        cout << setw(25) << salariedEmployees[i].getSurname() << setw(25) << salariedEmployees[i].getFirstName()
             << setw(25)
             << salariedEmployees[i].getDateOfBirth() << setw(25) << salariedEmployees[i].getHolidaysAlreadyTaken()
             << setw(25)
             << salariedEmployees[i].returnAnnualSalary() << endl;

    }



    // printing all details about managers
    cout << "\n--- MANAGERS ---\n" << setw(25) << "Surname" << setw(25) << "First Name" << setw(25) << "DOB"
         << setw(25) << "Taken Holidays" << setw(25) << "Profit Sharing" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
            << endl;


    for (int i = 0; i < managersCount; ++i) {
        cout << setw(25) << managers[i].getSurname() << setw(25) << managers[i].getFirstName() << setw(25)
             << managers[i].getDateOfBirth() << setw(25) << managers[i].getHolidaysAlreadyTaken() << setw(25)
             << managers[i].returnProfitSharing() << endl;

    }
    cout << endl;

}

// Method to find age from given birthday
int findAge(string birthDay) {
    stringstream token(birthDay);
    string splittedPart;
    getline(token, splittedPart, '/');
    return (2021 - stoi(splittedPart));
}


// Method to search an employee
void searchEmployee() {
    string fname, surname;

    cout << "\nEnter The Surname Of The Employee : ";
    cin >> surname;

    cout << "Enter The First Name Of The Employee : ";
    cin >> fname;


    for (int i = 0; i < hourlyEmployeesCount; ++i) {
        if (hourlyEmployees[i].getSurname() == surname && hourlyEmployees[i].getFirstName() == fname) {

            int maximumHolidays = 30;
            if (findAge(hourlyEmployees[i].getDateOfBirth()) >= 50)
                maximumHolidays = 32;


            cout << "\n--- HOURLY EMPLOYEE ---\n" << setw(25) << "Surname" << setw(25) << "First Name" << setw(25)
                 << "DOB"
                 << setw(25) << "Taken Holidays" << setw(25) << "Holidays Left" << setw(25) << "Hourly Wage" << setw(25)
                 << "Hours Worked" << endl;
            cout
                    << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
                    << endl;

            cout << setw(25) << hourlyEmployees[i].getSurname() << setw(25) << hourlyEmployees[i].getFirstName()
                 << setw(25)
                 << hourlyEmployees[i].getDateOfBirth() << setw(25) << hourlyEmployees[i].getHolidaysAlreadyTaken()
                 << setw(25) << (maximumHolidays - hourlyEmployees[i].getHolidaysAlreadyTaken()) << setw(25)
                 << hourlyEmployees[i].returnHourlyWage() << setw(25) << hourlyEmployees[i].returnHoursWorked() << endl;

            return;
        }
    }


    for (int i = 0; i < salariedEmployeesCount; ++i) {
        if (salariedEmployees[i].getSurname() == surname && salariedEmployees[i].getFirstName() == fname) {
            int maximumHolidays = 30;
            if (findAge(salariedEmployees[i].getDateOfBirth()) >= 50)
                maximumHolidays = 32;

            cout << "\n--- SALARIED EMPLOYEE ---\n" << setw(25) << "Surname" << setw(25) << "First Name" << setw(25)
                 << "DOB"
                 << setw(25) << "Taken Holidays" << setw(25) << "Holidays Left" << setw(25) << "Annual Salary" << endl;
            cout
                    << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
                    << endl;

            cout << setw(25) << salariedEmployees[i].getSurname() << setw(25) << salariedEmployees[i].getFirstName()
                 << setw(25)
                 << salariedEmployees[i].getDateOfBirth() << setw(25) << salariedEmployees[i].getHolidaysAlreadyTaken()
                 << setw(25) << (maximumHolidays - salariedEmployees[i].getHolidaysAlreadyTaken()) << setw(25)
                 << salariedEmployees[i].returnAnnualSalary() << endl;


            return;
        }


    }


    for (int i = 0; i < managersCount; ++i) {
        if (managers[i].getSurname() == surname && managers[i].getFirstName() == fname) {
            int maximumHolidays = 30;
            if (findAge(managers[i].getDateOfBirth()) >= 50)
                maximumHolidays = 32;

            cout << "\n--- MANAGER ---\n" << setw(25) << "Surname" << setw(25) << "First Name" << setw(25) << "DOB"
                 << setw(25) << "Taken Holidays" << setw(25) << "Holidays Left" << setw(25) << "Profit Sharing" << endl;
            cout
                    << "------------------------------------------------------------------------------------------------------------------------------------------------------------"
                    << endl;

            cout << setw(25) << managers[i].getSurname() << setw(25) << managers[i].getFirstName() << setw(25)
                 << managers[i].getDateOfBirth() << setw(25) << managers[i].getHolidaysAlreadyTaken() << setw(25)
                 << (maximumHolidays - managers[i].getHolidaysAlreadyTaken()) << setw(25)
                 << managers[i].returnProfitSharing() << endl;

            return;
        }


    }


    cout << "Employee Not Found" << endl;
}


// Method to request holidays
void requestHoliday() {
    string fname, surname;

    cout << "\nEnter The Surname Of The Employee : ";
    cin >> surname;

    cout << "Enter The First Name Of The Employee : ";
    cin >> fname;

    char empType = 'a';

    while (toupper(empType) != 'M' && toupper(empType) != 'S' && toupper(empType) != 'H') {
        cout << "Enter the type of the employee (Manager - M / Salaried Employee - S / Hourly Employee - H ) : ";
        cin >> empType;
        cin.ignore();
    }

    int holiday_count;
    cout << "Enter the number of holidays : ";
    cin >> holiday_count;

    bool isFound = false;
    if (toupper(empType) == 'M') {
        int i;
        for (i = 0; i < managersCount; ++i) {
            if (managers[i].getSurname() == surname && managers[i].getFirstName() == fname) {
                isFound = true;
                managers[i].requestingHoliday(holiday_count);
                break;
            }
        }
    } else if (toupper(empType) == 'S') {
        int i;
        for (i = 0; i < salariedEmployeesCount; ++i) {
            if (salariedEmployees[i].getSurname() == surname && salariedEmployees[i].getFirstName() == fname) {
                salariedEmployees[i].requestingHoliday(holiday_count);

                isFound = true;
                break;
            }
        }

    } else {
        int i;
        for (i = 0; i < hourlyEmployeesCount; ++i) {
            if (hourlyEmployees[i].getSurname() == surname && hourlyEmployees[i].getFirstName() == fname) {
                hourlyEmployees[i].requestingHoliday(holiday_count);

                isFound = true;
                break;
            }
        }
    }

    if (!isFound)
        cout << "Employee Not Found" << endl;

}


// Method to delete an employee
void deleteEmployee() {
    string fname, surname;

    cout << "\nEnter The Surname Of The Employee : ";
    cin >> surname;

    cout << "Enter The First Name Of The Employee : ";
    cin >> fname;

    char empType = 'a';

    while (toupper(empType) != 'M' && toupper(empType) != 'S' && toupper(empType) != 'H') {
        cout << "Enter the type of the employee (Manager - M / Salaried Employee - S / Hourly Employee - H ) : ";
        cin >> empType;
        cin.ignore();
    }


    bool isFound = false;
    if (toupper(empType) == 'M') {
        int i;
        for (i = 0; i < managersCount; ++i) {
            if (managers[i].getSurname() == surname && managers[i].getFirstName() == fname) {
                isFound = true;
                break;
            }
        }
        for (int j = i; j < managersCount - 1; ++j) {
            managers[i] = managers[i + 1];
        }

        managersCount--;
    } else if (toupper(empType) == 'S') {
        int i;
        for (i = 0; i < salariedEmployeesCount; ++i) {
            if (salariedEmployees[i].getSurname() == surname && salariedEmployees[i].getFirstName() == fname) {
                isFound = true;
                break;
            }
        }
        for (int j = i; j < salariedEmployeesCount - 1; ++j) {
            salariedEmployees[i] = salariedEmployees[i + 1];
        }
        salariedEmployeesCount--;
    } else {
        int i;
        for (i = 0; i < hourlyEmployeesCount; ++i) {
            if (hourlyEmployees[i].getSurname() == surname && hourlyEmployees[i].getFirstName() == fname) {
                isFound = true;
                break;
            }
        }

        for (int j = i; j < hourlyEmployeesCount - 1; ++j) {
            hourlyEmployees[i] = hourlyEmployees[i + 1];
        }

        hourlyEmployeesCount--;
    }

    if (!isFound)
        cout << "Employee Not Found" << endl;

}


// Method to get option from user
int getOption() {
    int option;
    cout << "\n1). Adding Employees " << endl;
    cout << "2). Removing Employees " << endl;
    cout << "3). Request Holidays " << endl;
    cout << "4). Display All Employees " << endl;
    cout << "5). Search For An Employee " << endl;
    cout << "6). Exit" << endl;

    cout << "\nSelect An Option : ";
    cin >> option;

    while (option < 1 || option > 6) {
        cout << "Invalid Option" << endl;
        cout << "\nSelect An Option : ";
        cin >> option;
    }

    return option;


}


// Main method
int main(void) {

    int option = getOption();
    while (option != 6) {
        if (option == 1) {
            createEmployee();
        } else if (option == 2) {
            deleteEmployee();
        } else if (option == 3) {
            requestHoliday();
        } else if (option == 4) {
            displayEmployees();
        } else if (option == 5) {
            searchEmployee();
        }
        option = getOption();

    }
    return 0;
}




