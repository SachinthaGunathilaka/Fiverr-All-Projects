#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct _Car {
    int id;
    string ownerName;
    int ownerAge;
    string carModel;
    string plateNumber;

    _Car() {

    }

    _Car(int id, string owner_name, int owner_age, string model, string plate_number) : id(id), ownerName(
            std::move(owner_name)),
                                                                                        ownerAge(owner_age),
                                                                                        carModel(std::move(model)),
                                                                                        plateNumber(std::move(
                                                                                                plate_number)) {
    }


} Car;


void displayMenu() {
    cout << "\n+-----------------------------+" << endl;
    cout << "|         Car Company         |" << endl;
    cout << "+-----------------------------+" << endl;
    cout << "\n\t1) Add a car \n"
            "\t2) Search for a car \n"
            "\t3) Update a car\n"
            "\t4) Delete a car \n"
            "\t5) Sort cars\n"
            "\t6) Display all cars\n"
            "\t7) Quit" << endl;
}

int getIntegerValue(const string &text) {
    int number;
    string input;

    while (true) {
        cout << "\nEnter " << text << ": ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> number && number >= 0) {
            break;
        }

        cout << "Error: Invalid input. Please enter a valid " << text << "." << std::endl;
    }

    return number;
}

int getOption() {
    int option = getIntegerValue("option");

    while (option < 1 || option > 7) {
        cout << "Error: Invalid input. Please enter a valid option." << std::endl;
        option = getIntegerValue("option");
    }

    return option;
}

void readFromFile(Car *cars, int &cur_index, const string &filename) {
    ifstream file(filename);
    string line;

    // Read the data into a vector of Car objects
    while (getline(file, line)) {
        int id, ownerAge;
        string ownerName, carModel, plateNumber;
        stringstream ss(line);
        getline(ss, line, ',');

        id = stoi(line);
        getline(ss, ownerName, ',');
        getline(ss, line, ',');
        ownerAge = stoi(line);
        getline(ss, carModel, ',');
        ss >> plateNumber;
        Car car(id, ownerName, ownerAge, carModel, plateNumber);
        cars[cur_index++] = car;
    }
    file.close();
    cout << "\nData has read from the file successfully!" << endl;


}

void displayCar(const Car &car) {

    const int ID_WIDTH = 6;
    const int NAME_WIDTH = 20;
    const int AGE_WIDTH = 10;
    const int MODEL_WIDTH = 25;
    const int PLATE_WIDTH = 12;

    cout << "| " << left << setw(ID_WIDTH) << car.id
         << "| " << setw(NAME_WIDTH) << car.ownerName
         << "| " << setw(AGE_WIDTH) << car.ownerAge
         << "| " << setw(MODEL_WIDTH) << car.carModel
         << "| " << setw(PLATE_WIDTH) << car.plateNumber.c_str() << " |" << std::endl;
}

void displayCars(Car *cars, int cur_size) {

    cout << "+-----------------------------------------------------------------------------------+" << endl;
    cout << "| ID    | Owner Name          | Owner Age | Model                    | Plate Number |" << endl;
    cout << "+-----------------------------------------------------------------------------------+" << endl;


    for (int i = 0; i < cur_size; i++) {
        displayCar(cars[i]);
    }
    cout << "+-----------------------------------------------------------------------------------+" << endl;

}

bool compareStrings(const string &string1, const string &string2) {
    if (string1.length() != string2.length()) {
        return false;
    }

    for (int i = 0; i < string1.length(); i++) {
        if (tolower(string1[i]) != tolower(string2[i])) {
            return false;
        }
    }

    return true;
}

void searchCar(Car *cars, int cur_index) {
    cout << "\n1) Search by ID\n"
            "2) Search by owner name\n"
            "3) Search by place number\n"
            "4) Search by model" << endl;

    cout << "\nEnter option: ";
    int choice;
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Error: Invalid input. Please enter a number between 1 and 4." << endl;
        cout << "\nEnter option: ";
        cin >> choice;
    }

    string search_term;
    cout << "Enter the search term: ";
    cin.ignore();
    getline(cin, search_term);

    bool found = false;
    cout << "\n+-----------------------------------------------------------------------------------+" << endl;
    cout << "| ID    | Owner Name          | Owner Age | Model                    | Plate Number |" << endl;
    cout << "+-----------------------------------------------------------------------------------+" << endl;
    for (int i = 0; i < cur_index; i++) {
        if ((choice == 1 && cars[i].id == stoi(search_term)) ||
            (choice == 2 && compareStrings(cars[i].ownerName, search_term)) ||
            (choice == 3 && compareStrings(cars[i].plateNumber, search_term)) ||
            (choice == 4 && compareStrings(cars[i].carModel, search_term))) {

            displayCar(cars[i]);
            found = true;
        }
    }


    if (!found) {
        cout << "|                               No results found.                                   |" << endl;
    }

    cout << "+-----------------------------------------------------------------------------------+" << endl;

}

void addNewCar(Car *cars, int &cur_index) {
    int id;
    string ownerName;
    int ownerAge;
    string carModel;
    string plateNumber;

    id = getIntegerValue("Id");

    while (true) {
        bool is_valid = true;
        for (int i = 0; i < cur_index; i++) {
            if (cars[i].id == id) {
                cout << "Error: ID already exists." << endl;
                is_valid = false;
                break;
            }
        }

        if (is_valid)
            break;

        id = getIntegerValue("Id");

    }

    cout << "Enter the owner name: ";
    getline(cin, ownerName);

    ownerAge = getIntegerValue("owner age");


    cout << "Enter the car model: ";
    getline(cin, carModel);

    cout << "Enter the plate number: ";
    getline(cin, plateNumber);

    Car car(id, ownerName, ownerAge, carModel, plateNumber);
    cars[cur_index++] = car;

    cout << "Car added successfully!" << endl;
}

void updateCar(Car *cars, int cur_index) {
    int id;
    string ownerName;
    int ownerAge;
    string carModel;
    string plateNumber;

    id = getIntegerValue("Id");
    int index;
    index = 0;
    bool is_valid = false;
    for (int i = 0; i < cur_index; i++) {
        if (cars[i].id == id) {
            is_valid = true;
            break;
        }
        index++;
    }

    if (!is_valid) {
        cout << "Car with given id is not found!" << endl;
        return;
    }

    cout << "Enter the new owner name: ";
    getline(cin, ownerName);

    ownerAge = getIntegerValue("new owner age");


    cout << "Enter the new car model: ";
    getline(cin, carModel);

    cout << "Enter the new plate number: ";
    getline(cin, plateNumber);

    cars[index].id = id;
    cars[index].ownerName = ownerName;
    cars[index].ownerAge = ownerAge;
    cars[index].carModel = carModel;
    cars[index].plateNumber = plateNumber;

    cout << "Car updated successfully!" << endl;
}

void deleteCar(Car *cars, int &cur_index) {
    int id;

    id = getIntegerValue("Id");
    int index;
    index = 0;
    bool is_valid = false;
    for (int i = 0; i < cur_index; i++) {
        if (cars[i].id == id) {
            is_valid = true;
            break;
        }
        index++;
    }

    if (!is_valid) {
        cout << "Car with given id is not found!" << endl;
        return;
    }

    for (int i = index; i < cur_index - 1; ++i) {
        cars[i] = cars[i + 1];
    }
    cur_index--;
    cout << "Car deleted successfully!" << endl;
}


bool compareCars(const Car &a, const Car &b, int sortType) {

    switch (sortType) {
        case 1:
            return a.id > b.id;
        case 2:
            return a.ownerName > b.ownerName;
        case 3:
            return a.ownerAge > b.ownerAge;
        case 4:
            return a.carModel > b.carModel;
        case 5:
            return a.plateNumber > b.plateNumber;
    }

    return true;
}

void sortCars(Car *cars, int cur_index) {


    int sortType;
    cout << "\n1. Sort by ID" << endl;
    cout << "2. Sort by owner name" << endl;
    cout << "3. Sort by owner age" << endl;
    cout << "4. Sort by model" << endl;
    cout << "5. Sort by plate number" << endl;

    sortType = getIntegerValue("sort type");

    while (sortType < 1 || sortType > 5) {
        cout << "Invalid sort type." << endl;
        cout << "\nEnter option: ";
        cin >> sortType;
    }

    for (int i = 0; i < cur_index - 1; i++) {
        for (int j = 0; j < cur_index - i - 1; j++) {
            if (compareCars(cars[j], cars[j + 1], sortType)) {
                std::swap(cars[j], cars[j + 1]);
            }
        }
    }

    displayCars(cars, cur_index);


}

void writeToFile(Car *cars, int cur_index, const string &filename) {
    ofstream outFile(filename);
    for (int i = 0; i < cur_index; i++) {
        outFile << cars[i].id << "," << cars[i].ownerName << "," << cars[i].ownerAge << ","
                << cars[i].carModel << "," << cars[i].plateNumber << endl;
    }

    outFile.close();
    cout << "Data has written to the car details file successfully!" << endl;
}

void writeLog(const string &filename, int cur_index){

    auto cur_datetime = time(nullptr);
    auto cur_time = *localtime(&cur_datetime);


    ofstream outFile;
    outFile.open(filename, ios_base::app);
    outFile << put_time(&cur_time, "%d-%m-%Y %H-%M-%S") << "\t\t" <<  cur_index << " records\t" << endl;
    outFile.close();
    cout << "Data has written to the statical report file successfully!" << endl;
}

int main() {

    int size = 15;
    int cur_index = 0;
    string filename = "car_details.csv";
    string logfile_name = "statistical_report.txt";
    Car *cars = new Car[size];

    readFromFile(cars, cur_index, filename);

    while (true) {
        displayMenu();
        int option = getOption();

        if (option == 1) {
            addNewCar(cars, cur_index);
        } else if (option == 2) {
            searchCar(cars, cur_index);
        } else if (option == 3) {
            updateCar(cars, cur_index);
        } else if (option == 4) {
            deleteCar(cars, cur_index);
        } else if (option == 5) {
            sortCars(cars, cur_index);
        } else if (option == 6) {
            displayCars(cars, cur_index);
        } else {
            break;
        }
    }

    writeToFile(cars, cur_index, filename);
    writeLog(logfile_name, cur_index);
    return 0;
}
