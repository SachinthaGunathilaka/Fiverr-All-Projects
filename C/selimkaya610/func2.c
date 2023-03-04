#include "func2.h"

// createList method implementation
struct Node *createList(struct Node *head, int *data, int size) {

    // Iterate through each value in data and insert to the linked list
    for (int i = 0; i < size; ++i) {
        struct Node *node = (struct Node *) malloc(sizeof(struct Node));
        node->data = data[i];
        node->next = head;
        head = node;
    }

    return head;
}