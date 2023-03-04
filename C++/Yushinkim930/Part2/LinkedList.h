#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

// making it generic
template <typename T>
class LinkedList 
{
private:
    // head and tail of LinkedList
    Node<T>* head;
    Node<T>* tail;

public:
    // constructor
    LinkedList();
    // destructor
    ~LinkedList();

    // Add an item to front of list
    // return true if successful and false if not
    bool addItemToFront(T item);
    
    // Add an item to rear of list
    // return true if successful and false if not
    bool addItemToRear(T item);

    // Add an item after the first occurence of itemToFind
    // return true if successful and false if not
    bool addItemAfter(T itemToFind, T itemToAdd);

    // Add an item before the first occurence of itemToFind
    // return true if successful and false if not
    bool addItemBefore(T itemToFind, T itemToAdd);

    // Return true if itemToFind is in the list and false if not
    bool contains(T itemToFind);

    // Remove every occurence of item in the list
    // return a count of the number of items removed (0 if not found)
    int remove(T itemToRemove);

    // Remove the front item from the list
    // return the first item. If empty throw exception
    T removeFromFront();

    // Remove the rear item from the list
    // return the rear item. If empty throw exception
    T removeFromRear();

    // return the number of items in the list
    int count();

    // return true if empty and false if not
    bool isEmpty();

    // helper method to print list
    void printList();

    // print function
    void print();

    // helper function to print the linked list recursively
    void printRecursively(Node<T> *);
};

#endif // LINKEDLIST_H