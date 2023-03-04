#include <iostream>

using namespace std;

// fillArray function
void fillArray(int array[], int &filled) {

    // Get user input for positive number between 0 and 20
    cout << "Enter a positive number no larger than 20: ";
    cin >> filled;

    // If the user input number if not valid ask again
    while (filled < 0 || filled > 20) {
        cout << "Invalid Input" << endl;
        cout << "Enter a positive number no greater than 20: ";
        cin >> filled;
    }

    // Fill the array by random numbers upto filled
    for (int i = 0; i < filled; ++i) {
        // generate random number between 1 and 100
        int random = 1 + rand() % 99;
        // fill the array
        array[i] = random;
    }

}

// displayArray function
void displayArray(int array[], int filled) {
    // Iterate though array upto filled
    for (int i = 0; i < filled; ++i) {
        // display element
        cout << array[i] << endl;
    }
}


// replaceNum function
bool replaceNum(int array[], int filled, int previous, int next) {

    // initially set isFind to false
    bool isFind = false;

    // Iterate though array upto filled
    for (int i = 0; i < filled; ++i) {
        // If the element is found
        if (array[i] == previous) {
            // replace the element by new value
            array[i] = next;
            // set isFind as true
            isFind = true;
        }
    }

    // If the value successfully replaces return true
    if (isFind)
        return true;

    // If the value does not found return false
    return false;
}

int main() {

    // set the random seed to 20
    srand(20);
    // Initialize constant MAX_SIZE variable to 20
    const int MAX_SIZE = 20;
    // Define numbers array
    int numbers[MAX_SIZE];
    int filled;

    // Fill the array
    fillArray(numbers, filled);

    // Display menu
    cout << "(D)isplay, (R)eplace, Re(F)ill, or (Q)uit? ";

    // Get user input
    char choice;
    cin >> choice;

    // Convert user input to upper case
    choice = toupper(choice);

    // This loop continue until user want to quit
    while (choice != 'Q') {
        // If the user want to display the array
        if (choice == 'D') {
            displayArray(numbers, filled);
        }
            // If the user wants to replace number
        else if (choice == 'R') {
            int prev, next;

            // get the value needs to be replaced
            cout << "Enter a number to search for: ";
            cin >> prev;

            // get the replacing value
            cout << "Enter replacement: ";
            cin >> next;

            // If the replacement was successful
            if (replaceNum(numbers, filled, prev, next)) {
                cout << "Replacement successful." << endl;
            }
            // If the replacement is not successful
            else {
                cout << "Replacement not successful." << endl;
            }
        }
        // If the user wants to fill the array again
        else if (choice == 'F') {
            fillArray(numbers, filled);
        }
        // If the user enter invalid input
        else {
            cout << "Invalid input" << endl;
        }

        // Get user input again
        cout << "(D)isplay, (R)eplace, Re(F)ill, or (Q)uit? ";
        cin >> choice;
        choice = toupper(choice);
    }

    // display good bye message
    cout << "Good bye!" << endl;


    return 0;
}
