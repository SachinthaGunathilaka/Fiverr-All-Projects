#ifndef EJOBE_PROJECT_ADT_H
#define EJOBE_PROJECT_ADT_H

#include "BST.h"

using namespace std;

class ADT {
public:
    BST<string> people_details;

    void insert(string name, string birthday);

    void remove(string name);

    void search(string name);

    void modify(string name, string birthday);

    void displayAll();
};

// Inserting a person
void ADT::insert(string name, string birthday) {
    // If person successfully inserted
    if (people_details.Insert(name, birthday)) {
        cout << "person added successfully" << endl;
    }
        // If the person already exists
    else {
        cout << "Person already exists" << endl;
    }
}

// Searching a person
void ADT::search(string name) {
    people_details.Search(people_details.root, name);
}

// Editing a person
void ADT::modify(string name, string birthday) {
    people_details.Edit(people_details.root, name, birthday);
}

// Removing a person
void ADT::remove(string name) {
    if (people_details.Delete(name)) {
        cout << "person removed successfully" << endl;
    } else {
        cout << "Person not found" << endl;
    }

}

// Display all the persons
void ADT::displayAll() {
    people_details.Inorder(people_details.root);
}

#endif
