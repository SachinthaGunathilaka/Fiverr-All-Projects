#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rand_story.h"


int main(int argc, char *argv[]) {

    // Allocate memory for catarray
    catarray_t *catarray = malloc(sizeof(*catarray));
    long cat_len, template_len;

    // Read category file
    char *cat_buffer, *template_buffer;

    // Extract command line arguments
    int no_reuse = 0;
    int cat_file_taken = 0;
    for (int i = 1; i < argc; ++i) {
        if(strcmp(argv[i], "-n") == 0){
            no_reuse = 1;
        } else if(!cat_file_taken){
            cat_buffer = readFile(argv[i], &cat_len);
            cat_file_taken = 1;
        }
        else{
            template_buffer = readFile(argv[i], &template_len);
        }
    }

    // If category file does not exist
    if (!cat_buffer) {
        printf("Categories file does not exists!\n");
        return -1;
    }

    // If template file does not exist
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

    int option = no_reuse ? 3 : 2;
    char * result = readStoryTemplate(template_buffer, template_len, option, catarray);

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



    return 0;
}