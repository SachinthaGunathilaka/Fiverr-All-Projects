/**
 *  The addItemAfter and addItemBefore are implemented according to the given template. But i think they are incorrect.
 *  Because in them we are searching for an item then inserting item that can be the case. But they should have been 
 *  taking as parameter the index instead of the item itself, so that addItemAfter position 2 means means add after index 1 
 *  in that way the testing code will be more clear. Right now the testing provided says add after position 2 but it then 
 *  method that is provided add after a specific value. So this can be something that can be corrected.
 */

#include <iostream>

#include "LinkedList.h"

using namespace std;

// constructor
template<typename T>

LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

// destructor
template<typename T>

LinkedList<T>::~LinkedList() {
    Node<T> *temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

// Add an item to front of list
// return true if successful and false if not
template<typename T>

bool LinkedList<T>::addItemToFront(T item) {
    Node<T> *temp = new Node<T>;
    temp->data = item;
    temp->next = head;
    head = temp;

    if (tail == nullptr) {
        tail = temp;
    }

    return true;
}

// Add an item to rear of list
// return true if successful and false if not
template<typename T>

bool LinkedList<T>::addItemToRear(T item) {
    Node<T> *temp = new Node<T>;
    temp->data = item;
    temp->next = nullptr;

    if (tail != nullptr) {
        tail->next = temp;
    }

    tail = temp;

    if (head == nullptr) {
        head = temp;
    }

    return true;
}

// Add an item after the first occurence of itemToFind
// return true if successful and false if not
template<typename T>
bool LinkedList<T>::addItemAfter(T itemToFind, T itemToAdd) {
    Node<T> *temp = head;
    while (temp != nullptr) {
        if (temp->data == itemToFind) {
            Node<T> *newNode = new Node<T>;
            newNode->data = itemToAdd;
            newNode->next = temp->next;
            temp->next = newNode;

            if (tail == temp) {
                tail = newNode;
            }

            return true;
        }

        temp = temp->next;
    }

    return false;
}

// Add an item before the first occurence of itemToFind
// return true if successful and false if not
template<typename T>
bool LinkedList<T>::addItemBefore(T itemToFind, T itemToAdd) {
    Node<T> *temp = head;
    Node<T> *prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == itemToFind) {
            Node<T> *newNode = new Node<T>;
            newNode->data = itemToAdd;
            newNode->next = temp;

            if (prev != nullptr) {
                prev->next = newNode;
            } else {
                head = newNode;
            }

            return true;
        }

        prev = temp;
        temp = temp->next;
    }

    return false;
}

// Return true if itemToFind is in the list and false if not
template<typename T>

bool LinkedList<T>::contains(T itemToFind) {
    Node<T> *temp = head;

    while (temp != nullptr) {
        if (temp->data == itemToFind) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

// Remove every occurence of item in the list
// return a count of the number of items removed (0 if not found)
template<typename T>

int LinkedList<T>::remove(T itemToRemove) {
    int count = 0;

    Node<T> *temp = head;
    Node<T> *prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == itemToRemove) {
            if (prev != nullptr) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }

            if (tail == temp) {
                tail = prev;
            }

            delete temp;
            temp = prev;
            count++;
        }

        prev = temp;

        if (temp != nullptr) {
            temp = temp->next;
        }
    }

    return count;
}

// Remove the front item from the list
// return the first item. If empty throw exception
template<typename T>
T LinkedList<T>::removeFromFront() {
    if (head == nullptr) {
        throw "List is empty";
    }

    Node<T> *temp = head;
    head = head->next;
    T data = temp->data;

    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }

    return data;
}

// Remove the rear item from the list
// return the last item. If empty throw exception
template<typename T>

T LinkedList<T>::removeFromRear() {
    if (tail == nullptr) {
        throw "List is empty";
    }

    Node<T> *temp = tail;
    Node<T> *prev = nullptr;
    Node<T> *curr = head;

    while (curr != tail) {
        prev = curr;
        curr = curr->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr;
    }

    tail = prev;
    T data = temp->data;

    delete temp;

    if (tail == nullptr) {
        head = nullptr;
    }

    return data;
}

// Return the number of items in the list
template<typename T>

int LinkedList<T>::count() {
    int count = 0;
    Node<T> *temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Return true if the list is empty and false if not
template<typename T>

bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

// helper method to print list
template<typename T>
void LinkedList<T>::printList() {
    Node<T> *temp = head;

    while (temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }

    cout << std::endl;
}

// print function
template<typename T>
void LinkedList<T>::print() {
    // Call printRecursively function with the argument as head of the linked list
    printRecursively(this->head);

}

// helper function to print the linked list recursively
template<typename T>
void LinkedList<T>::printRecursively(Node<T> *node) {

    // Base case
    // If the current node is NULL, print newline and terminate the recursion
    if (node == NULL) {
        printf("\n");
        return;
    }

    // Print value of the node
    printf("%d  ", node->data);

    // Recursive Case
    // Call printRecursively for next node
    printRecursively(node->next);
}
