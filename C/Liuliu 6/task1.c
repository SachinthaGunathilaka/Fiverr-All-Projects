#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[256];
    int counts[26][3] = {0};
    char sorted_text[256] = "";

    printf("> ");
    scanf(" %[^\n]s", text);

    int position = 0;
    int i;
    for (i = 0; i < strlen(text); ++i) {
        if (isalpha(text[i])) {
            sorted_text[strlen(sorted_text)] = text[i];

            counts[text[i] - 'a'][1]++;
            counts[text[i] - 'a'][0] = text[i];

            if (counts[text[i] - 'a'][2] == 0){
                counts[text[i] - 'a'][2] = position++;
            }
        }
    }

    sorted_text[strlen(sorted_text)] = '\0';

    int j;
    for (i = 0; i < 25; ++i) {
        for (j = i; j < 25-i; ++j) {
            if((counts[j][1] > counts[j+1][1]) || (counts[j][1] == counts[j+1][1] && counts[j][2] > counts[j+1][2])){
                int temp = counts[j][0];
                counts[j][0] = counts[j+1][0];
                counts[j+1][0] = temp;

                temp = counts[j][1];
                counts[j][1] = counts[j+1][1];
                counts[j+1][1] = temp;

                temp = counts[j][2];
                counts[j][2] = counts[j+1][2];
                counts[j+1][2] = temp;
            }
        }
    }

    for (i = 0; i < 26; ++i) {
        if(counts[i][1] != 0)
            printf("%c: %d\n", counts[i][0], counts[i][1]);
    }

    for (i = 0; i < strlen(sorted_text); ++i) {
        for (j = 0; j < strlen(sorted_text)-1 - i; ++j) {
            if(sorted_text[j] > sorted_text[j+1]){
                char temp = sorted_text[j];
                sorted_text[j] = sorted_text[j+1];
                sorted_text[j+1] = temp;


            }
        }
    }

    printf("%s", sorted_text);



    return 0;
}
