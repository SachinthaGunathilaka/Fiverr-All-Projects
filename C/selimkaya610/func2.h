#ifndef _FUNC2_H
#define _FUNC2_H

#include<stdio.h>
#include<stdlib.h>


// struct for Node
struct Node {
    int data;
    struct Node *next;
};



// createList method declaration
struct Node * createList(struct Node *head, int * data, int size);

#endif