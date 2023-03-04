/*
 * BABY WEIGHT PROGRAM to display statistical details about 5 babies.
 * Name  :
 * Date  :
 * Class :
*/

#include <iostream>
using namespace std;

// Function to get weight from the user for a baby
void getBabyWeight(double &weight) {

    // Get user input
    cout << "Please enter the Baby's Weight > ";
    cin >> weight;

    // Check whether it is less than or equal to 0
    while (weight <= 0) {
        // If it is get input from user again
        cout << "Baby's weight should be greater than 0" << endl;
        cout << "Please enter the Baby's Weight > ";
        cin >> weight;
    }
}


// Function to find and display the lowest weight
void findLowest(double baby1, double baby2, double baby3, double baby4, double baby5) {

    // Find the lowest weight
    double lowest_value = min(min(min(min(baby1, baby2), baby3), baby4), baby5);

    // duplicates flag
    int duplicates = -1;
    // baby with the lowest weight
    int lowest_baby = 0;

    // Compare each baby with the lowest weight.
    // Check duplicates also
    if(baby1 == lowest_value){
        duplicates++;
        lowest_baby = 1;
    }

    if(baby2 == lowest_value){
        duplicates++;
        lowest_baby = 2;
    }

    if(baby3 == lowest_value){
        duplicates++;
        lowest_baby = 3;
    }
    if(baby4 == lowest_value){
        duplicates++;
        lowest_baby = 4;
    }
    if(baby5 == lowest_value){
        duplicates++;
        lowest_baby = 5;
    }

    // If more than 1 baby has the lowest weight
    if(duplicates > 0){
        cout << "\nWe have a TIE!! No Lowest Birth Weight for Today..." << endl;
        return;
    }

    // Display baby with the lowest weight
    cout << "\nBaby #" << lowest_baby << " has the lowest birth weight at " << lowest_value << ".\n";
}


void findHighest(double baby1, double baby2, double baby3, double baby4, double baby5) {

    // Find the highest weight
    double highest_value = max(max(max(max(baby1, baby2), baby3), baby4), baby5);

    // duplicates flag
    int duplicates = -1;
    // baby with the lowest weight
    int highest_baby = 0;


    // Compare each baby with the highest weight.
    // Check duplicates also
    if(baby1 == highest_value){
        duplicates++;
        highest_baby = 1;
    }

    if(baby2 == highest_value){
        duplicates++;
        highest_baby = 2;
    }

    if(baby3 == highest_value){
        duplicates++;
        highest_baby = 3;
    }
    if(baby4 == highest_value){
        duplicates++;
        highest_baby = 4;
    }
    if(baby5 == highest_value){
        duplicates++;
        highest_baby = 5;
    }

    // If more than 1 baby has the lowest weight
    if(duplicates > 0){
        cout << "We have a TIE!! No Highest Birth Weight for Today..." << endl;
        return;
    }

    // Display baby with the highest weight
    cout << "Baby #" << highest_baby << " has the highest birth weight at " << highest_value << ".\n";
}


// Function to display welcome screen
void welcome() {
    cout << "******************************************************************\n"
            "BABY WEIGHT PROGRAM\n"
            "Please Enter the Five Baby Weights\n"
            "Please enter a real number Weights (Must be > 0).\n"
            "Program Developed by: \"PUT YOUR NAME HERE\"\n"
            "*****************************************************************\n" << endl;
}

// Function to calculate and return average weight of the 5 babies
double weightAverage(double baby1, double baby2, double baby3, double baby4, double baby5){
    return (baby1 + baby2 + baby3 + baby4 + baby5)/5.0;
}


// Main function
int main() {

    // Declare variables to store each baby's weight
    double baby1, baby2, baby3, baby4, baby5;

    // Call welcome function to display welcome screen
    welcome();

    // Call getBabyWeight function 5 times to get user input for weights of babies
    getBabyWeight(baby1);
    getBabyWeight(baby2);
    getBabyWeight(baby3);
    getBabyWeight(baby4);
    getBabyWeight(baby5);


    // Call findLowest() function to display baby with the lowest weight
    findLowest(baby1, baby2, baby3, baby4, baby5);
    // Call findHighest() function to display baby with the highest weight
    findHighest(baby1, baby2, baby3, baby4, baby5);

    // Call weightAverage() to calculate and return average weight
    double average = weightAverage(baby1, baby2, baby3, baby4, baby5);

    // Display average weight
    cout << "Overall Baby Weight Average: " << average << endl;



    return 0;
}
