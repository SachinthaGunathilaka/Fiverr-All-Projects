#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"


class Linkedlist {

public:
    Node *head;
    int sorted_upto;

    Linkedlist() {
        head = nullptr;
        sorted_upto = 0;
    }

    void insertWord(const string &word);

    void insertNode(const string &word, int count);

    void printList();

    void sort(int sort_level);

    void swap(Node &node1, Node &node2);

    string getWordByIndex(int index);


};

#endif
