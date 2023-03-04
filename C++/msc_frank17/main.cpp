#include <iostream>
#include <vector>

using namespace std;


class Vehicle {
protected:
    string number_plate;
    int registered_year;
    int inspected_year;
    bool inspection_due;

public:
    Vehicle(string number_plate, int registered_year, int inspected_year) {
        this->number_plate = number_plate;
        this->registered_year = registered_year;
        this->inspected_year = inspected_year;
        this->inspection_due = false;
        if (2022 - this->inspected_year > 3) {
            this->inspection_due = true;
        }
    }

    string getNumberPlate() {
        return number_plate;
    }

    bool getInspectionDue() {
        return inspection_due;
    }

    void displayInspectionDue() const {
        if (inspection_due)
            cout << "General inspection is due" << endl;
        else
            cout << "General inspection is not due yet" << endl;
    }

    virtual void display() = 0;

    virtual double getTaxLiability() = 0;
};


class Car : public Vehicle {
private:
    double horse_power;
    int emission_class;

public:
    Car(string number_plate, int registered_year, int inspected_year, double horse_power, int emission_class) : Vehicle(
            std::move(number_plate), registered_year, inspected_year) {
        this->horse_power = horse_power;
        this->emission_class = emission_class;
    }

    double getTaxLiability() {
        return (horse_power + 99) / 100 * 10 * (emission_class + 1);
    }

    void display() {
        cout << "\nType : Car,\t Number plate : " << number_plate << ",\tRegistered year : " << registered_year
             << ",\t Inspected year : " << inspected_year << ",\t Horse power : " << horse_power
             << ",\t Emission class : " << emission_class;
    }


};

class Motorbike : public Vehicle {
private:
    double horse_power;
    int max_speed;

public:
    Motorbike(string number_plate, int registered_year, int inspected_year, double horse_power, int max_speed)
            : Vehicle(
            std::move(number_plate), registered_year, inspected_year) {
        this->horse_power = horse_power;
        this->max_speed = max_speed;
    }

    double getTaxLiability() {
        return (horse_power + 59) / 100 * 20 * (max_speed / 150);
    }

    void display() {
        cout << "\nType : Motorbike,\t Number plate : " << number_plate << ",\tRegistered year : " << registered_year
             << ",\t Inspected year : " << inspected_year << ",\t Horse power : " << horse_power
             << ",\t Max speed : " << max_speed;
    }

};

class Truck : public Vehicle {
private:
    int num_of_axles;
    double payload;

public:
    Truck(string number_plate, int registered_year, int inspected_year, int num_of_axles, double payload) : Vehicle(
            std::move(number_plate), registered_year, inspected_year) {
        this->num_of_axles = num_of_axles;
        this->payload = payload;
    }

    double getTaxLiability() {
        return payload * 50;
    }

    void display() {
        cout << "\nType : Car,\t Number plate : " << number_plate << ",\tRegistered year : " << registered_year
             << ",\t Inspected year : " << inspected_year << ",\t Number of axles : " << num_of_axles
             << ",\t Payload : " << payload;
    }
};


void displayMenu() {
    cout << "\n1. Create a new vehicle\n"
            "2. Search a vehicle\n"
            "3. Listing of all stored vehicle data and the liability\n"
            "4. Listing of all vehicles with general inspection is due\n"
            "5. Exit" << endl;
}

int getOption() {
    cout << "\nEnter option: ";
    int option;
    cin >> option;
    while (option < 1 || option > 5) {
        cout << "\nInvalid option. Enter option again: ";
        cin >> option;
    }

    return option;
}

void createVehicle(vector<Vehicle *> &vehicles) {
    string number_plate;
    int registered_year;
    int inspected_year;
    string type;


    cout << "Enter number plate : ";
    cin >> number_plate;

    cout << "Enter registered year : ";
    cin >> registered_year;

    cout << "Enter general inspection year : ";
    cin >> inspected_year;

    while (true) {
        cout << "Enter vehicle type (C)ar, (M)otorbike, (T)ruck : ";
        cin >> type;
        if (type == "c" || type == "C") {
            double horse_power;
            int emission_class;

            cout << "Enter horse power : ";
            cin >> horse_power;

            cout << "Enter emission class : ";
            cin >> emission_class;
            while (emission_class < 0 || emission_class > 2) {
                cout << "Invalid emission class. Enter emission class : ";
                cin >> emission_class;
            }

            Car *car = new Car(number_plate, registered_year, inspected_year, horse_power, emission_class);
            vehicles.push_back(car);

        } else if (type == "M" || type == "m") {
            double horse_power;
            int max_speed;

            cout << "Enter horse power : ";
            cin >> horse_power;

            cout << "Enter max speed : ";
            cin >> max_speed;

            auto *motorbike = new Motorbike(number_plate, registered_year, inspected_year, horse_power, max_speed);
            vehicles.push_back(motorbike);

        } else if (type == "T" || type == "t") {
            int num_of_axles;
            double payload;


            cout << "Enter number of axles : ";
            cin >> num_of_axles;

            cout << "Enter payload : ";
            cin >> payload;

            auto *truck = new Truck(number_plate, registered_year, inspected_year, num_of_axles, payload);
            vehicles.push_back(truck);

        } else {
            cout << "Invalid vehicle type. ";
            continue;
        }

        break;
    }
}

void displayVehiclesWithLiability(const vector<Vehicle *> &vehicles) {
    for (Vehicle *vehicle: vehicles) {
        vehicle->display();
        cout << "\t Tax Liability : " << vehicle->getTaxLiability() << endl;

    }
}

void displayInspectionDueVehicles(const vector<Vehicle *> &vehicles) {
    for (Vehicle *vehicle: vehicles) {
        if (vehicle->getInspectionDue()) {
            vehicle->display();
            cout << "\t Tax Liability : " << vehicle->getTaxLiability() << endl;
        }
    }
}

void searchVehicle(vector<Vehicle *> vehicles) {
    string number_plate;
    cout << "Enter license plate number : ";
    cin >> number_plate;

    bool is_find = false;
    for (auto vehicle: vehicles) {
        if (vehicle->getNumberPlate() == number_plate) {
            vehicle->display();
            cout << "\t Tax Liability : " << vehicle->getTaxLiability() << endl;
            vehicle->displayInspectionDue();

            is_find = true;
            break;
        }
    }

    if (!is_find) {
        cout << "Number plate does not exists." << endl;
    }


}


int main() {
    vector<Vehicle *> vehicles;
    int option;

    cout << "Vehicle Management System" << endl;
    cout << "-------------------------" << endl;

    while (true) {
        displayMenu();
        option = getOption();
        switch (option) {
            case 1:
                createVehicle(vehicles);
                break;
            case 2:
                searchVehicle(vehicles);
                break;
            case 3:
                displayVehiclesWithLiability(vehicles);
                break;
            case 4:
                displayInspectionDueVehicles(vehicles);
                break;
            case 5:
                cout << "Exiting!" << endl;
                return 0;
        }

    }
}
