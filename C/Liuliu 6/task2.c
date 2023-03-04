#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char text[256], line[256];
    int index, length;

    printf("> ");
    scanf(" %[^\n]s", line);

    char *pt;
    pt = strtok (line,",");
    strcpy(text, pt);
    pt = strtok (NULL,",");
    index = atoi(pt);
    pt = strtok (NULL,",");
    length = atoi(pt);

    if(index > strlen(text))
        return 0;

    int i;
    for (i = index; ((i < index+length-1) && (i < strlen(text))) ; ++i) {
        printf("%c", text[i]);
    }
    printf("\n");

    return 0;
}
