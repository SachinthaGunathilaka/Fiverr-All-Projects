#ifndef __RAND_STORY_H__
#define __RAND_STORY_H__

#include "provided.h"

//any functions you want your main to use
void addCategory(char *category, char *value, catarray_t *cats);

char *readFile(char *filename, long * length);

int readCategories(char * buffer, long length, catarray_t * catarray);

char * readStoryTemplate(const char * buffer, long length, int option, catarray_t * catarray);

void deleteValue(catarray_t * catarray, char * category, const char * value);

void freeCatArray(catarray_t * cats);


#endif
