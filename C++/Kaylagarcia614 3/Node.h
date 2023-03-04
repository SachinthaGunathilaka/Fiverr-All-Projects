#ifndef NODE_H
#define NODE_H

#include<string>

using namespace std;

class Node {
public:
    string word;
    int count;
    Node *next;

//    Node();

    Node(const string& word, int count);

    void display();
};

#endif