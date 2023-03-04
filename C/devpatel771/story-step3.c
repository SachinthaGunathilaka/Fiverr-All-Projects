#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rand_story.h"


int main(int argc, char *argv[]) {

    // Allocate memory for catarray
    catarray_t *catarray = malloc(sizeof(*catarray));
    long cat_len, template_len;

    // Read category file
    char *cat_buffer = readFile(argv[1], &cat_len);
    // Read story template file
    char *template_buffer = readFile(argv[2], &template_len);

    // If category file not exists
    if (!cat_buffer) {
        printf("Categories file does not exists!\n");
        return -1;
    }

    // If template file not exists
    if (!template_buffer) {
        printf("Story template file does not exists!\n");
        return -1;
    }

    // Call readCategories function
    int status = readCategories(cat_buffer, cat_len, catarray);

    // Validate format of the input files
    if(status == -1){
        printf("Invalid format of the input file!\n");
        return -1;
    }

    // Call readStoryTemplate function
    char * result = readStoryTemplate(template_buffer, template_len, 2, catarray);

    // Validate format of story template file
    if(strcmp(result, "format err") == 0){
        printf("No closing _ in the input file.\n");
        return -1;
    }
    if(strcmp(result, "null err") == 0){
        printf("Category does not exists.\n");
        return -1;
    }

    // Display result
    printf("%s\n", result);

    freeCatArray(catarray);
    free(cat_buffer);
    free(template_buffer);
    free(result);



    return 0;
}