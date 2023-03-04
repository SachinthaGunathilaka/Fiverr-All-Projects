#include <stdio.h>
#include <string.h>
#include "rand_story.h"

int main(int argc, char *argv[] ) {


    // Read file
    long length;
    char * buffer = readFile(argv[1], &length);

    // If file exists
    if (buffer)
    {

        // Call readStoryTemplate function
        char * result = readStoryTemplate(buffer, length, 1, NULL);

        // release buffer memory
        free(buffer);

        // Check for format error
        if(strcmp(result, "format err") == 0){
            printf("No closing _ in the input file.\n");
            return -1;
        }

        // display result
        printf("%s\n", result);
    }
    return 0;
}