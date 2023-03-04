#include "func3.h"


// displayList method implementation
void displayList(struct Node * head) {
    struct Node *ptr = head;
    printf("\n[  ");

    // Traverse through the linked list and display the value
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next; // go to next node
    }

    printf("]\n");
}