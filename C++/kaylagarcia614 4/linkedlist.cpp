// Filename: linkedlist.cpp
// 
// Contains the class LinkedList that represents a linked list. This contains some basic operations, such as insert, delete, find, length
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020, Oct 2020

#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Default constructor sets head and tail to null
LinkedList::LinkedList() {
    head = NULL;
}

// Insert(int val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
void LinkedList::insert(int val) {
    Node *to_add = new Node; // creates new Node
    to_add->data = val; // sets the data to hold input val

    to_add->next = head; // make to_add point to existing head
    head = to_add; // set head to to_add
}

// find(int val): Finds a Node with data "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node *LinkedList::find(int val) {
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    while (curr != NULL) //looping over list
    {
        if (curr->data == val) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node *LinkedList::deleteNode(int val) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) // loop over list, starting from head
    {
        if (curr->data == val) // we found Node with val, so break
            break;
        //otherwise, proceed list
        prev = curr; // move prev by one Node
        curr = curr->next; // move curr by one Node
    }
    // at this point, curr points to Node with val. If curr is null, then val is not in the list.
    if (curr == NULL) // val not found
        return NULL;
    // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
    // Otherwise, we delete the Node after prev.
    if (prev == NULL) // we need to delete head
        head = head->next; // delete head
    else // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    return curr;
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void LinkedList::deleteList() {
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    Node *temp = NULL;

    // curr will loop over list. At every iteration, we first store a pointer to the next Node, and then delete the current Node.
    while (curr != NULL) { // Looping over list
        temp = curr->next; // store pointer to next Node in the list
        delete (curr); // delete the current Node
        curr = temp; // update curr to proceed through list
    }
    head = NULL;
    return;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string LinkedList::print() {
    string list_str = ""; // string that has list
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will loop over list. It prints the content of curr, and then moves curr to next Node.
    while (curr != NULL) { // looping over list
        list_str = list_str + to_string(curr->data) + " "; //append string with current Node's data
        curr = curr->next; // proceed through list
    }
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back(); // remove the last (extra) space from string
    return list_str;
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LinkedList::length() {
    int length = 0; // initialize length to zero
    Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list

    while (curr != NULL) { // looping over list
        length++; // increment length
        curr = curr->next; // proceed to next Node
    }
    return length;
}

// Find entry with val, and rotate it to the head of the linked list
// Input: int val that needs to be rotated to the head. If val is not in the list, make no change
// Output: void, just achieves the rotation
void LinkedList::rotateToHead(int val) {
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL) { // looping over list
        if (curr->data == val)
            break;

        prev = curr;
        curr = curr->next; // proceed to next Node
    }

    if (curr == NULL || prev == NULL)
        return;

    Node *final = head;
    while (final->next != NULL) {
        final = final->next;
    }


    prev->next = NULL;
    final->next = head;
    head = curr;
}

// Rotates the linked list
// Input: Int
// Output: None, the list is rotated by the input argument 
void LinkedList::rotate(int pos) {
    if (!head)
        return;

    pos = pos % length();

    if (pos == 0)
        return;

    pos = length() - pos;

    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    for (int i = 0; i < pos; ++i) {
        prev = curr;
        curr = curr->next;
    }


    Node *final = head;
    while (final->next != NULL) {
        final = final->next;
    }

    prev->next = NULL;
    final->next = head;
    head = curr;

}

// Reverse last val entries in linked list
// Input: int val for number of entries to be reversed. If val is more than length of list, reverse the whole list
// Output: void, just achieves the rervesal
void LinkedList::reverseTail(int val) {

    if (val >= length()) {
        Node *temp = NULL;
        Node *prev = NULL;
        Node *current = head;
        while (current != NULL) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
        return;
    }

    Node *curr = head;
    for (int i = 0; i < length() - val - 1; i++)
        curr = curr->next;

    Node *next;
    Node *prev = NULL;
    while (curr->next != NULL) {
        next = curr->next->next;
        curr->next->next = prev;
        prev = curr->next;
        curr->next = next;
    }

    curr->next = prev;

}

// Check if linked list forms a palindrome
// Input: none
// Output: boolean. true if palindrome, false otherwise

bool LinkedList::palindrome() {
    if (length() < 2)
        return true;

    Node *curr = head;
    vector<int> stack;
    while (curr != NULL) {
        stack.push_back(curr->data);
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < length() / 2; ++i) {
        if (curr->data != stack[stack.size() - 1])
            return false;

        curr = curr->next;
        stack.pop_back();
    }

    return true;

}

// Remove the last occurrence of the argument val from the list
// Input: int to be found
// Output: Pointer to the node removed. If no node removed (if val is not in list), return NULL
Node *LinkedList::deleteLast(int val) {
    Node *curr = head;
    int position = -1;
    int index = 0;
    while (curr != NULL) {
        if (curr->data == val)
            position = index;

        index++;
        curr = curr->next;
    }

    if (position == -1)
        return NULL;

    curr = head;
    Node *prev = NULL;
    index = 0;
    while (curr != NULL) { // looping over list
        if (index == position)
            break;

        prev = curr;
        curr = curr->next; // proceed to next Node
        index++;
    }

    if (prev == NULL) // we need to delete head
        head = head->next; // delete head
    else // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    return curr;
}

// Remove all duplicates from linked list. After deduplication, all elements only appear once in list
// Input: none
// Output: none, list has all duplicates removed
void LinkedList::dedup() {
    struct Node *curr = head, *comparing_node, *dup;

    while (curr != NULL && curr->next != NULL) {
        comparing_node = curr;

        while (comparing_node->next != NULL) {
            if (curr->data == comparing_node->next->data) {
                comparing_node->next = comparing_node->next->next;
            } else
                comparing_node = comparing_node->next;
        }
        curr = curr->next;
    }
}
