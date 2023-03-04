#include <iostream>
#include "ADT.h"

using namespace std;

// Display menu function
void displayMenu() {
    cout << "\n1. Insert Person\n"
            "2. Search Person\n"
            "3. Delete Person\n"
            "4. Edit Person\n"
            "5. Display All\n"
            "6. Exit" << endl;
}

// get option function
int getOption() {
    cout << "\nEnter option : ";
    int option;
    cin >> option;

    // If the user input is invalid
    while (option < 1 || option > 6) {
        cout << "Invalid option" << endl;
        cout << "Enter option : ";
        cin >> option;
    }
    return option;
}


int main() {

    ADT people_details;

    int option = 1;
    do {
        displayMenu(); // display menu
        option = getOption(); // get input from user

        // Adding person
        if (option == 1) {
            string fname, lname, birthday;
            cout << "\nEnter first name : ";
            cin >> fname;

            cout << "Enter last name : ";
            cin >> lname;

            cout << "Enter Birthday : ";
            cin >> birthday;

            people_details.insert(fname + " " + lname, birthday);
        }
        // Seaching a person
        else if (option == 2) {
            string fname, lname;
            cout << "\nEnter first name : ";
            cin >> fname;

            cout << "Enter last name : ";
            cin >> lname;
            people_details.search(fname + " " + lname);
        }
        // deleting a person
        else if (option == 3) {
            string fname, lname;
            cout << "\nEnter first name : ";
            cin >> fname;

            cout << "Enter last name : ";
            cin >> lname;
            people_details.remove(fname + " " + lname);
        }
        // editing a person
        else if (option == 4) {
            string fname, lname, birthday;
            cout << "\nEnter first name : ";
            cin >> fname;

            cout << "Enter last name : ";
            cin >> lname;

            cout << "Enter Birthday : ";
            cin >> birthday;

            people_details.modify(fname + " " + lname, birthday);
        }
        // display all persons
        else if (option == 5) {
            people_details.displayAll();
        }


    } while (option != 6);

    cout << "\nThank you." << endl;

}