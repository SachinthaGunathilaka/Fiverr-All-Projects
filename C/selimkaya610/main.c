#include "func1.h"
//#include "func2.h"
#include "func3.h"
#include "func4.h"

// Main method
int main(int argc, char *argv[]) {
    int size;

    // Check for validity of the arguments
    if (argc != 3) {
        printf("Invalid arguments\n");
        return 0;
    }

    // Initialize head node to NULL
    struct Node *head = NULL;

    // read the values to numbers array from given file
    int *numbers = readFile(argv[2], &size);

    // Create linked list using numbers array
    head = createList(head, numbers, size);

    // Display linked list
    displayList(head);

    // Sort the linked list
    sortList(head, size);

    // Display sorted linked list
    displayList(head);

    return 0;
}