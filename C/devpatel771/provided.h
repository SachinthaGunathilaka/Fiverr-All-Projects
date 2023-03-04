
#ifndef __PROVIDED_H__
#define __PROVIDED_H__

#include <stdlib.h>
#include <stdio.h>

struct category_tag {
    char * name;
    char ** words;
    size_t n_words;
};
typedef struct category_tag category_t;

struct catarray_tag {
    category_t * arr;
    size_t n;
};
typedef struct catarray_tag catarray_t;

//const char * chooseWord(char * category, catarray_t * cats);
void printWords(catarray_t * cats);


//const char *chooseWord(char *category, catarray_t *cats) {
//    if (cats == NULL)
//        return "cat";
//
//    for (int i = 0; i < cats->n; ++i) {
//        if (strcmp(category, cats->arr[i].name) == 0) {
//            return cats->arr[i].words[0];
//        }
//    }
//
//    return "-1";
//}

//void printWords(catarray_t * cats){
//    for (int i = 0; i < cats->n; ++i) {
//        printf("%s:\n", cats->arr[i].name);
//
//        for (int j = 0; j < cats->arr[i].n_words; ++j) {
//            printf("\t%s\n", cats->arr[i].words[j]);
//        }
//    }
//}



#endif


