#include "Node.h"
#include<iostream>


// Constructor of the Node Class
Node::Node(const string& word, int count) {

    this->word = word;
    this->count = count;
    this->next = nullptr;
}


// Function to display given Node
void Node::display() {
        cout << this->word << "  " << this->count << endl;
}
