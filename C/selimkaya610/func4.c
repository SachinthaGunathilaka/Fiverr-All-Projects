#include "func4.h"

// sortList method implementation
void sortList(struct Node *head, int size) {

    // Define nodes for current and next Nodes
    struct Node *current;
    struct Node *next;

    // Use bubble sort method to sort the linked list
    for (int i = 0; i < size - 1; i++) {
        current = head;
        next = head->next;

        for (int j = 1; j < size; j++) {

            // If the adjacent values are not in sorting order swap the values
            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }

            // go to next node
            current = current->next;
            next = next->next;
        }
    }
}