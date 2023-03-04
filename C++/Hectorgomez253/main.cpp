#include <iostream>
#include <vector>
#include <fstream>
#include "VirtualPet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Dolphin.h"
#include "Rabbit.h"

void displayMenu() {
    cout << "\nADD PET MENU\n"
            "\t1. Add a Cat\n"
            "\t2. Add a Dog\n"
            "\t3. Add a Fish\n"
            "\t4. Add a Dolphin\n"
            "\t5. Add a Rabbit\n"
            "\tQ. Done Adding Pets\n" << endl;

}

void displaySecondaryMenu() {
    cout << "\n1. Print All Pet Info\n"
            "2. Print PetNames.txt\n"
            "Q. Quit\n" << endl;
}


int main() {

    srand((unsigned int) time(nullptr));

    vector<VirtualPet *> virtual_pets;
    string option;

    while (true) {
        displayMenu();

        cout << "Enter option: ";
        cin >> option;

        if(option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "Q" && option != "q"){
            cout << "Invalid input" << endl;
            continue;
        }

        else if (option == "Q" || option == "q") {
            break;
        }

        string name, color;
        double baseAdoptionFee;

        cout << "Enter pet name: ";
        cin >> name;

        cout << "Enter pet color: ";
        cin >> color;

        cout << "Enter base adoption fee: ";
        cin >> baseAdoptionFee;

        if (option == "1") {
            double licenceFee, vetFee;

            cout << "Enter licence fee: ";
            cin >> licenceFee;

            cout << "Enter vet fee: ";
            cin >> vetFee;


            VirtualPet *pet = new Cat(name, color, baseAdoptionFee, licenceFee, vetFee);
            virtual_pets.push_back(pet);
        } else if (option == "2") {
            double licenceFee, vetFee;

            cout << "Enter licence fee: ";
            cin >> licenceFee;

            cout << "Enter vet fee: ";
            cin >> vetFee;


            VirtualPet *pet = new Dog(name, color, baseAdoptionFee, licenceFee, vetFee);
            virtual_pets.push_back(pet);
        } else if (option == "3") {
            string waterType;

            cout << "Enter water type: ";
            cin >> waterType;


            VirtualPet *pet = new Fish(name, color, baseAdoptionFee, waterType);
            virtual_pets.push_back(pet);
        } else if (option == "4") {
            string waterType;

            cout << "Enter vet fee: ";
            cin >> waterType;


            VirtualPet *pet = new Dolphin(name, color, baseAdoptionFee, waterType);
            virtual_pets.push_back(pet);
        } else if (option == "5") {
            double licenceFee, vetFee;

            cout << "Enter licence fee: ";
            cin >> licenceFee;

            cout << "Enter vet fee: ";
            cin >> vetFee;


            VirtualPet *pet = new Rabbit(name, color, baseAdoptionFee, licenceFee, vetFee);
            virtual_pets.push_back(pet);
        }
    }


    ofstream MyFile("PetNames.txt");
    for (int i = 0 ; i < virtual_pets.size(); i++) {
        MyFile << virtual_pets[i]->getType() << " " << virtual_pets[i]->getName() << endl;
    }
    MyFile.close();


    while (true) {
        displaySecondaryMenu();
        cout << "Enter option: ";
        cin >> option;

        if (option == "1") {
            for (VirtualPet *pet: virtual_pets) {
                pet->changeMood();
                pet->printInfo();
            }
        }

        else if(option == "2"){
            for (VirtualPet *pet: virtual_pets) {
                cout << pet->getType() << " " << pet->getName() << endl;
            }
        }

        else if(option == "Q" || option == "q"){
            break;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }


    return 0;
}
