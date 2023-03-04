
#include <stdio.h>
#include <stdlib.h>
#include "rand_story.h"

int main(int argc, char *argv[]) {

    // Allocate memory for catarray
    catarray_t *catarray = malloc(sizeof(*catarray));

    // Read file
    long length;
    char *buffer = readFile(argv[1], &length);

    // If file exists
    if (buffer) {

        // Call readCategories function
        int status = readCategories(buffer, length, catarray);

        // Check for format error
        if (status == -1) {
            printf("Invalid format of the input file!\n");
            return -1;
        }

        // Call printWords function
        printWords(catarray);
    }


    freeCatArray(catarray);
    free(buffer);
    return 0;
}