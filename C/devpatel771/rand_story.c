// Import libraries
#include "rand_story.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *chooseWord(char *category, catarray_t *cats) {
    if (cats == NULL)
        return "cat";

    for (int i = 0; i < cats->n; ++i) {
        if (strcmp(category, cats->arr[i].name) == 0) {
            return cats->arr[i].words[0];
        }
    }

    return "-1";
}

void printWords(catarray_t * cats){
    for (int i = 0; i < cats->n; ++i) {
        printf("%s:\n", cats->arr[i].name);

        for (int j = 0; j < cats->arr[i].n_words; ++j) {
            printf("\t%s\n", cats->arr[i].words[j]);
        }
    }
}


// Function to add a value to a category
void addCategory(char *category, char *value, catarray_t *cats) {

    // Iterate through each category
    for (size_t i = 0; i < cats->n; i++) {
        // Check whether category name matches
        if (strcmp(category, cats->arr[i].name) == 0) {

            // Append new value under the category
            cats->arr[i].n_words++;
            cats->arr[i].words = realloc(cats->arr[i].words, cats->arr[i].n_words * sizeof(*cats->arr[i].words));
            cats->arr[i].words[cats->arr[i].n_words - 1] = value;

            free(category);

            return;
        }
    }


    // If the category does not exist yet create new category
    category_t temp_cat;
    temp_cat.name = category;
    temp_cat.n_words = 1;
    temp_cat.words = malloc(sizeof(temp_cat.words[0]));
    temp_cat.words[0] = value;

    cats->arr = realloc(cats->arr, (cats->n + 1) * sizeof(cats->arr[0]));
    cats->arr[cats->n] = temp_cat;
    cats->n++;

}

// Function to read content of a given filename
char *readFile(char *filename, long *length) {

    // Open file
    char *buffer = 0;
    FILE *f = fopen(filename, "rb");


    // If file exists
    if (f) {

        // Read content to buffer
        fseek(f, 0, SEEK_END);
        *length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(*length);
        if (buffer) {
            fread(buffer, 1, *length, f);
        }
        fclose(f);
    }
        // If file does not exist
    else {
        printf("Input file does not found!\n");
        return NULL;
    }

    return buffer;
}


// Function to get character buffer and read categories and values into catarray_t struct
int readCategories(char *buffer, long length, catarray_t *catarray) {
    int colons = 0, start = 0;
    char category[50], value[50];

    // Iterate through each character in the buffer
    for (int i = 0; i < length; ++i) {

        // Check for new line character / last char of the buffer
        if (buffer[i] == '\n' || i == length - 1) {

            // Ignore empty lines
            if (colons == 0)
                continue;

            // reset colons and value
            colons = 0;
            memset(value, 0, 50);

            // Copy category value from the buffer to value variable
            if (i == length - 1)
                strncpy(value, buffer + start, i - start + 1);

            else
                strncpy(value, buffer + start, i - start);

            // Remove new line char from value
            if (value[strlen(value) - 1] == '\n')
                value[strlen(value) - 1] = 0;


            // Allocate memory for category and value
            char *temp_category = malloc(strlen(category));
            char *temp_value = malloc(strlen(value));

            // Copy values
            strcpy(temp_category, category);
            strcpy(temp_value, value);

            // Add category and its value to catarray
            addCategory(temp_category, temp_value, catarray);
            start = i + 1;


        }

        // Check for new colon char
        if (buffer[i] == ':') {
            // Clear category
            memset(category, 0, 50);

            // Validate formatting
            colons++;
            if (colons == 2) {
                return -1;
            }

            // Copy category from the buffer to category variable
            strncpy(category, buffer + start, i - start);


            start = i + 1;
        }
    }

    return 1;

}


/*
    Function to get character buffer and read story template file and generate result
    Option == 1 => For story-step1
    Option == 2 => For story-step2
    Option == 3 => For story-step3
 */
char *readStoryTemplate(const char *buffer, long length, int option, catarray_t *catarray) {
    // Allocate memory for result
    char *result = malloc(length + 500);

    // Create new category
    category_t used_words;
    used_words.words = malloc(sizeof(used_words.words[0]));
    used_words.n_words = 1;


    /*
        tag => To check whether char pointer is inside a category tag (_categoryTag_)
        result_i => Current index of the result buffer
        word => To store tag
        word_i => Current index of the word
     */
    int result_i = 0;
    int tag = 0;
    char word[30];
    int word_i = 0;

    // Iterate through each character in the buffer
    for (int i = 0; i < length; ++i) {
        // Check for '_' char
        if (buffer[i] == '_') {

            // If pointer is inside a category tag
            if (tag) {

                // Terminate word
                word[word_i] = '\0';

                // Rest tag and word_i
                word_i = 0;
                tag = 0;



                // Choose word by calling chooseWord function
                // According to the given option this will be called differently
                const char *selected_word;

                // For story-step1
                if (option == 1) {
                    selected_word = chooseWord(word, catarray);
                }
                // For story-step2 and story-step3
                else {

                    int cat_number = atoi(word);
                    // If the category tag is not a number
                    if (cat_number == 0) {
                        selected_word = chooseWord(word, catarray);
                        if (selected_word == NULL)
                            return "null err";

                        // For story-step3
                        if (option == 3) {
                            deleteValue(catarray, word, selected_word);
                        }
                    }
                    // If the category tag is a number
                    else {
                        selected_word = used_words.words[used_words.n_words - 1 - cat_number];

                    }
                }

                // Allocate memory for category tag
                char *temp_word = malloc(strlen(word));
                strcpy(temp_word, selected_word);

                // Append that to used_words array (Used for story-step3)
                used_words.words[used_words.n_words - 1] = temp_word;
                used_words.n_words++;
                used_words.words = realloc(used_words.words, used_words.n_words * sizeof(used_words.words[0]));

                strcat(result, selected_word);
                result_i += strlen(selected_word) - 1;

            } else {
                tag = 1;
            }
        } else {
            if (tag) {
                // Add char to word
                word[word_i++] = buffer[i];
            } else {
                // Add char to result
                result[result_i++] = buffer[i];
            }
        }
    }


    for (int i = 0; i < used_words.n_words; ++i) {
        free(used_words.words[i]);
    }
    free(used_words.words);

    // Validate format
    if (tag) {
        return "format err";
    }

    return result;
}


// Function to delete value from a category
void deleteValue(catarray_t *catarray, char *category, const char *value) {

    // Iterate through each category
    for (int i = 0; i < catarray->n; ++i) {

        // Match category name
        if (strcmp(catarray->arr[i].name, category) == 0) {
            int index = -1;

            // Iterate through each value in the category
            for (int j = 0; j < catarray->arr[i].n_words; ++j) {

                // Match value
                if (strcmp(catarray->arr[i].words[j], value) == 0) {
                    index = j;
                }
            }

            // If no match return
            if (index == -1)
                return;

            // Remove value and free the memory
            for (int j = index; j < catarray->arr[i].n_words - 1; ++j) {
                catarray->arr[i].words[j] = catarray->arr[i].words[j + 1];
            }
//            free(catarray->arr[i].words[catarray->arr[i].n_words-1]);
            catarray->arr[i].n_words--;

            break;

        }
    }
}

void freeCatArray(catarray_t * cats){
    for (int i = 0; i < cats->n; ++i) {
        for (int j = 0; j < cats->arr[i].n_words; ++j) {
            free(cats->arr[i].words[j]);

//            printf("\t%s\n", cats->arr[i].words[j]);
        }
        free(cats->arr[i].words);
        free(cats->arr[i].name);
    }

    free(cats->arr);
    free(cats);
}