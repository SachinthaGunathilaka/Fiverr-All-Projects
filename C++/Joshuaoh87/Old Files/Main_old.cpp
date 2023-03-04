#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>
#include "../Date.h"
#include "../Time.h"
#include "Vector.h"
#include "../Windlog.h"

using namespace std;

int GetLines(ifstream &infile);

int GetUserInput(int &input);

string ConvertMonth(int month);

void ShowMenu();

void MenuOne(Vector<WindLogType> &windlog);

void MenuTwo(Vector<WindLogType> &windlog);

void MenuThree(Vector<WindLogType> &windlog);

void MenuFour(Vector<WindLogType> &windlog);

void EnterMonth(int &input);

void EnterYear(int &input);

void LoadData(string fileName, Vector<WindLogType> &windlog);

void LoadContents(string fileToLoad, Vector<WindLogType> &windlog);

const string DATA_FILE = "data/met_index.txt";

int main() {
    Vector<WindLogType> windlog;
    WindLogType T1;

    cout << endl;
    LoadData(DATA_FILE, windlog);


    int choice = 0;
    do {
        ShowMenu();                 // display menu
        GetUserInput(choice);       // get user input with validation

        switch (choice)              // enter menu
        {
            case 1: {
                Vector<WindLogType> windlog2;
                windlog2 = windlog;
                MenuOne(windlog2);  // passing in deep copy
                windlog2.Clear();
            }
                break;
            case 2: {
                Vector<WindLogType> windlog2;
                windlog2 = windlog;
                MenuTwo(windlog2);
                windlog2.Clear();
            }
                break;
            case 3: {
                Vector<WindLogType> windlog2;
                windlog2 = windlog;
                MenuThree(windlog2);
                windlog2.Clear();
            }
                break;
            case 4: {
                Vector<WindLogType> windlog2;
                windlog2 = windlog;
                MenuFour(windlog2);
                windlog2.Clear();
            }
                break;
            case 5:
                cout << "Thank you for using this program, bye!" << endl;
                exit(0);
            default:
                cout << "\nPlease only select option 1 - 5!\n" << endl;
        }

    } while (choice != 5);

    return 0;
}
// end of main

//========================= IMPLEMENTATION =========================//

// function for getting the number of lines to read in
int GetLines(ifstream &infile) {
    int lines = 0;
    string temp;
    while (infile.peek() != EOF) {
        getline(infile, temp);
        lines++;
    }
    infile.clear();             // clear EOF flag
    infile.seekg(0, ios::beg);  // put point back to the beginning
    return lines;
}

int GetUserInput(int &input)        // input validation for user input
{
    cout << "Please select your option: ";
    cin >> setw(1) >> input;

    // check for error
    while (!cin.good()) {
        // Return Error
        cout << "\nInvalid choice! Try again!\n" << endl;

        // Clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Get input again
        ShowMenu();
        cout << "Please select your option: ";
        cin >> setw(1) >> input;
    }

    // Clear Stream
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return input;
}

string ConvertMonth(int month)      // convert month from number value to string equivalent
{
    const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                              "October", "November", "December"};

    for (int i = 0; i < 13; i++) {
        if (month == i) {
            return months[i - 1];
        }
    }
    return 0;
}

void ShowMenu()                     // print out menu
{
    cout << "Please select the following: " << endl;
    cout << "1. Calculate the average wind speed and average ambient air temperature for a specified month and year"
         << endl;
    cout
            << "2. Calculate the average wind speed and average ambient air temperature for each month of a specified year."
            << endl;
    cout << "3. Calculate the total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "4. Write to a file the average wind speed, average ambient air temperature and total solar radiation in";
    cout << " kWh/m2 for each month of a specified year" << endl;
    cout << "5. Exit the program." << endl;
}

void MenuOne(Vector<WindLogType> &windlog)      // option 1 of menu
{
    int month = 0;
    int year = 0;
    EnterMonth(month);
    EnterYear(year);

    Date date;
    float sumOfSpeed = 0;
    float sumOfTemp = 0;
    bool check = false;
    int count = 0;

    for (int i = 0; i < windlog.GetSize(); i++) {
        windlog.at(i).GetDate(date);
        if (month == date.GetMonth() && year == date.GetYear()) {
            sumOfSpeed += windlog.at(i).GetSpeed() * 3.6;
            sumOfTemp += windlog.at(i).GetTemperature();
            count++;
            check = true;
        }

    }
    if (check) {
        cout << ConvertMonth(month) << " " << year << ": " << std::fixed << setprecision(1) << sumOfSpeed / count;
        cout << " km/h, " << sumOfTemp / count << " degrees C.\n" << endl;
    } else {
        cout << ConvertMonth(month) << " " << year << ": No Data\n" << endl;
    }
}

void MenuTwo(Vector<WindLogType> &windlog)       // option 2 of menu
{
    int year = 0;

    EnterYear(year);

    Date date;
    float sumOfSpeed = 0;
    float sumOfTemp = 0;
    bool check = false;
    int count = 0;

    for (int i = 0; i < windlog.GetSize(); i++) {
        windlog.at(i).GetDate(date);
        if (year == date.GetYear()) {
            check = true;
        }
    }

    if (check) {
        cout << year << endl;
        for (int month = 1; month < 13; month++) {
            count = 0;
            sumOfSpeed = 0;
            sumOfTemp = 0;

            for (int i = 0; i < windlog.GetSize(); i++) {
                windlog.at(i).GetDate(date);
                if (date.GetMonth() == month && year == date.GetYear()) {
                    sumOfSpeed += windlog.at(i).GetSpeed() * 3.6;
                    sumOfTemp += windlog.at(i).GetTemperature();
                    count++;
                }
            }

            if (sumOfSpeed == 0 && sumOfTemp == 0) {
                cout << ConvertMonth(month) << ": No Data." << endl;
            } else {
                cout << ConvertMonth(month) << ": " << std::fixed << setprecision(1) << sumOfSpeed / count << " km/h, ";
                cout << sumOfTemp / count << " degrees C. " << endl;
            }

        }
    } else {
        cout << year << endl;
        for (int month = 1; month < 13; month++) {
            cout << ConvertMonth(month) << ": No Data." << endl;
        }
    }
}

void MenuThree(Vector<WindLogType> &windlog)         // option 3 of menu
{
    int year;
    EnterYear(year);

    Date date;
    float sumOfSR = 0;
    bool check = false;
    int count = 0;

    for (int i = 0; i < windlog.GetSize(); i++) {
        windlog.at(i).GetDate(date);
        if (year == date.GetYear()) {
            check = true;
        }
    }

    if (check) {
        cout << year << endl;
        for (int month = 1; month < 13; month++) {
            sumOfSR = 0;

            for (int i = 0; i < windlog.GetSize(); i++) {
                windlog.at(i).GetDate(date);
                if (date.GetMonth() == month && year == date.GetYear()) {
                    if (windlog.at(i).GetSolarRadiation() >= 100) {
                        sumOfSR += windlog.at(i).GetSolarRadiation() / 6000;
                    }
                }
            }
            if (sumOfSR == 0) {
                cout << ConvertMonth(month) << ": No Data." << endl;
            } else {
                cout << ConvertMonth(month) << ": " << std::fixed << setprecision(1) << sumOfSR << " kWh/m2." << endl;
            }

        }
    } else {
        cout << year << endl;
        for (int month = 1; month < 13; month++) {
            cout << ConvertMonth(month) << ": No Data." << endl;
        }
    }
}

void MenuFour(Vector<WindLogType> &windlog)          // option 4 of menu
{
    ofstream ofile("WindTempSolar.csv");
    int year;

    EnterYear(year);

    Date date;
    float sumOfSpeed = 0;
    float sumOfTemp = 0;
    float sumOfSR = 0;
    bool check = false;
    int count = 0;

    for (int i = 0; i < windlog.GetSize(); i++) {
        windlog.at(i).GetDate(date);
        if (year == date.GetYear()) {
            check = true;
        }
    }

    if (check) {
        ofile << year << endl;
        for (int month = 1; month < 13; month++) {
            // reset values back to 0 for each new month
            count = 0;
            sumOfSpeed = 0;
            sumOfTemp = 0;
            sumOfSR = 0;
            for (int i = 0; i < windlog.GetSize(); i++) {
                windlog.at(i).GetDate(date);
                if (date.GetMonth() == month && year == date.GetYear()) {
                    sumOfSpeed += windlog.at(i).GetSpeed() * 3.6;
                    sumOfTemp += windlog.at(i).GetTemperature();
                    count++;
                    if (windlog.at(i).GetSolarRadiation() >= 100) {
                        sumOfSR += windlog.at(i).GetSolarRadiation() / 6000;
                    }
                }
            }

            if (sumOfSpeed != 0 || sumOfTemp != 0 || sumOfSR != 0) {
                ofile << ConvertMonth(month) << ',' << std::fixed << setprecision(1) << sumOfSpeed / count << ',';
                ofile << sumOfTemp / count << ',' << sumOfSR << endl;
            }
        }
    } else {
        ofile << year << "\nNo Data" << endl;
    }

    cout << "\nFile successfully written to WindTempSolar.csv\n" << endl;
}

void EnterMonth(int &input)              // get user input for month and perform input validation
{
    bool monthCheck = false;
    do {
        cout << "Please enter a specific month: ";
        cin >> input;

        //Test Value
        if (!cin.fail()) {
            if (input >= 1 && input <= 12) {
                monthCheck = true;
            } else {
                cout << "There are only 12 months in a year!" << endl;
            }
        } else {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    } while (!monthCheck);
}

void EnterYear(int &input)               // get user input for year and perform input validation
{
    bool yearCheck = false;
    do {
        cout << "Please enter a specific year: ";
        cin >> input;

        //Test Value
        if (!cin.fail()) {
            if (input > 0) {
                yearCheck = true;
            } else {
                cout << "Year entered must be positive!" << endl;
            }
        } else {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    } while (!yearCheck);
}

void LoadData(string fileName, Vector<WindLogType> &windlog) {
    string dataFileName;

    ifstream fileStr(fileName);
    if (!fileStr) {
        cout << "File cannot be found!" << endl;
        return;
    }

    while (!fileStr.eof()) {
        getline(fileStr, dataFileName);
        cout << dataFileName << endl;
        LoadContents(dataFileName, windlog);
        cout << dataFileName << " loaded!" << endl;
    }
}

void LoadContents(string fileToLoad, Vector<WindLogType> &windlog) {
    fileToLoad = "data/" + fileToLoad;

    cout << fileToLoad << endl;
    ifstream infile(fileToLoad);
    if (!infile) {
        cout << "Data file cannot be found1" << endl;
        return;
    }

    cout << "Loading file: " << fileToLoad << endl;

    // calculate number of lines in file
    int lines = 0;
    lines = GetLines(infile);

    // remove first line of headers
    string temp;
    getline(infile, temp);

    // read in file and add to vector
    WindLogType T1;
    for (int i = 0; i < lines - 1; i++) {
        infile >> T1;
        windlog.Add(T1);
    }

//    for (int i = 0; i < windlog.GetSize(); ++i) {
//        cout << windlog[i];
//    }
}
