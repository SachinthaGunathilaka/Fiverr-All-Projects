#include <iostream>
#include <utility>
#include "LinkedList.h"

using namespace std;

// Function to insert word to the linked list
void Linkedlist::insertWord(const string &word) {


    // Assign to head
    if (head == NULL) {
        Node *newNode = new Node(word, 1);

        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp != nullptr) {
        if (temp->word == word) {
            temp->count++;
            return;
        }

        temp = temp->next;

    }



    // Traverse till end of list
    temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    Node *newNode = new Node(word, 1);

    temp->next = newNode;

}


// Function to display linked list
void Linkedlist::printList() {

    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }
    Node *temp = head;

    while (temp != nullptr) {
        temp->display();
        temp = temp->next;
    }
}


// Function to insert node (with the count) to the linked list
void Linkedlist::insertNode(const string &word, int count) {
    Node *newNode = new Node(word, count);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


// Function to sort the linked list (Using selection sort)
// Linked list will be sorted upto given node
void Linkedlist::sort(int sort_level) {


    Node* temp = head;
    for (int i = 0; i < this->sorted_upto; ++i) {
        temp = temp->next;
    }

    int cur_sort_pos = this->sorted_upto;
    // Traverse the List
    while (temp) {
        if(cur_sort_pos == sort_level+1)
            break;
        Node* min = temp;
        Node* r = temp->next;


        // Traverse the unsorted sublist
        while (r) {
            if (min->count < r->count || (min->count == r->count && min->word.compare(r->word) > 0))
                min = r;

            r = r->next;
        }

        // Swap Data
        swap(*min, *temp);

        temp = temp->next;
        cur_sort_pos++;
    }

    this->sorted_upto = sort_level+1;

}


// Function to swap 2 nodes
void Linkedlist::swap(Node &node1, Node &node2) {
    string temp_word = node1.word;
    node1.word = node2.word;
    node2.word = temp_word;

    int temp_count = node1.count;
    node1.count = node2.count;
    node2.count = temp_count;
}


// Function to get word by given index
string Linkedlist::getWordByIndex(int index) {
    if (head == nullptr) {
        return "-";
    }
    Node *temp = head;

    int cur_index = 0;
    int is_find = false;
    while (temp != nullptr) {

        if (index == cur_index) {
            is_find = true;
            break;

        }
        temp = temp->next;
        cur_index++;
    }

    if (is_find) {
        return temp->word;
    }

    return "-";
}
