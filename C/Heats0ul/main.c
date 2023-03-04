#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


void printGrid(char grid[4][4]) {
    printf(" ――――――――――――――\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("│  %c  ", grid[i][j]);
        }
        printf("│\n");
        printf(" ――――――――――――――\n");
    }
}

void placeChar(char grid[4][4], char ch, int *i, int *j, int *index, char *dir) {

    if (*j == 0 && (strcmp(dir, "l") == 0 || strcmp(dir, "lu") == 0 || strcmp(dir, "ld") == 0)) {
        return;
    }

    if (*j == 3 && (strcmp(dir, "r") == 0 || strcmp(dir, "ru") == 0 || strcmp(dir, "rd") == 0)) {
        return;
    }

    if (*i == 0 && (strcmp(dir, "u") == 0 || strcmp(dir, "lu") == 0 || strcmp(dir, "ru") == 0)) {
        return;
    }

    if (*i == 3 && (strcmp(dir, "d") == 0 || strcmp(dir, "ld") == 0 || strcmp(dir, "rd") == 0)) {
        return;
    }

    *index += 1;
    if (strcmp(dir, "l") == 0)
        *j -= 1;

    else if (strcmp(dir, "r") == 0)
        *j += 1;

    else if (strcmp(dir, "u") == 0)
        *i -= 1;

    else if (strcmp(dir, "d") == 0)
        *i += 1;

    else if (strcmp(dir, "lu") == 0) {
        *j -= 1;
        *i -= 1;
    } else if (strcmp(dir, "ld") == 0) {
        *j -= 1;
        *i += 1;
    } else if (strcmp(dir, "ru") == 0) {
        *i -= 1;
        *j += 1;
    } else if (strcmp(dir, "rd") == 0) {
        *i += 1;
        *j += 1;
    }

    grid[*i][*j] = ch;
}

void placeWordTemplate(char grid[4][4], const char *word, int start_i, int start_j, char *dir1, char *dir2) {
    int i = start_i, j = start_j, index = 1;

    grid[i][j] = word[0];
    while (index < strlen(word)) {
        int turn = rand() % 2;

        if (turn == 0)
            placeChar(grid, word[index], &i, &j, &index, dir1);

        else
            placeChar(grid, word[index], &i, &j, &index, dir2);

    }

}


void placeWordL1(char grid[4][4], const char *word) {
    int turn = rand() % 2;
    if (turn == 0) {
        placeWordTemplate(grid, word, 0, 0, "r", "d");
    } else {
        placeWordTemplate(grid, word, 3, 0, "r", "u");
    }
}


void placeWordL2(char grid[4][4], const char *word) {

    int turn = rand() % 2;
    if (turn == 0) {
        placeWordTemplate(grid, word, 0, 3, "l", "d");
    } else {
        placeWordTemplate(grid, word, 3, 3, "l", "u");
    }
}


void placeWordL3(char grid[4][4], const char *word) {
    int start = rand() % 4;
    if (start == 0) {

        int turn = rand() % 2;
        if (turn == 0) {
            placeWordTemplate(grid, word, 0, 0, "rd", "u");
        } else {
            placeWordTemplate(grid, word, 0, 0, "rd", "l");
        }

    }

    else if(start == 1){
        int turn = rand() % 2;
        if (turn == 0) {
            placeWordTemplate(grid, word, 0, 3, "ld", "u");
        } else {
            placeWordTemplate(grid, word, 0, 3, "ld", "r");
        }
    }

    else if(start == 2){
        int turn = rand() % 2;
        if (turn == 0) {
            placeWordTemplate(grid, word, 3, 0, "ru", "l");
        } else {
            placeWordTemplate(grid, word, 3, 0, "ru", "d");
        }
    }

    else{
        int turn = rand() % 2;
        if (turn == 0) {
            placeWordTemplate(grid, word, 3, 3, "lu", "r");
        } else {
            placeWordTemplate(grid, word, 3, 3, "lu", "d");
        }
    }



}

int loadWords(char words[500][10], char * filename){

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    int i = 0;


    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("File does not exists\n");
        exit(EXIT_FAILURE);

    }

    while (getline(&line, &len, fp) != -1) {
        int j = 0;
        while (isalpha(line[j]) && strlen(line) > j){
            words[i][j] = toupper(line[j]);
            j++;
        }

        words[i][j] = 0;
        i++;
    }

    fclose(fp);
    if (line)
        free(line);

    return i;
}

void fillGrid(char grid[4][4], char * word, int level){
    if(level == 1)
        placeWordL1(grid, word);
    else if(level == 2)
        placeWordL2(grid, word);
    else
        placeWordL3(grid, word);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(grid[i][j] == 32){
                int rand_char = rand() % 26;
                grid[i][j] = 'A' + rand_char;
            }
        }
    }
}


int main() {

    printf("\n----------------------\n");
    printf("WELCOME TO PUZZLE GAME\n");
    printf("----------------------\n");

    srand(time(0));

    char words[500][10];
    char filename[20];

    char option;

    int valid;
    do {
        valid = 1;
        printf("\n1) Set 1\n"
               "2) Set 2\n"
               "3) Set 3\n\n"
               "Select Word Set : ");

        scanf(" %c", &option);

        if(option == '1'){
            strcpy(filename, "word_set_1.txt");
        }
        else if(option == '2'){
            strcpy(filename, "word_set_2.txt");
        }
        else if(option == '3'){
            strcpy(filename, "word_set_3.txt");
        }
        else{
            valid = 0;
            printf("Invalid input\n");
        }
    } while (valid == 0);


    valid = 1;
    int level;
    do {
        valid = 1;
        printf("\n1) Level 1\n"
               "2) Level 2\n"
               "3) Level 3\n\n"
               "Select The Level : ");

        scanf(" %c", &option);

        if(option == '1'){
            level = 1;
        }
        else if(option == '2'){
            level = 2;
        }
        else if(option == '3'){
            level = 3;
        }
        else{
            valid = 0;
            printf("Invalid input\n");
        }
    } while (valid == 0);


    time_t start_time;
    start_time = time(NULL);
    int total_time = 5;
    int points = 0;



    while (1){


        char grid[4][4] = {{' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '}};

        int word_count = loadWords(words, filename);
        int random_index = rand() % word_count;

        fillGrid(grid, words[random_index], level);

        while (1){
            int current_time = time(NULL);
            long int remaining_time = total_time*60 - (current_time - start_time);
            if(remaining_time < 0){
                printf("\nTime Over\n");
                printf("\nTotal Points   : %d\n\n", points);


                return 0;
            }

            printf("\nRemaining Time : %ld seconds\n", remaining_time);
            printf("Total Points   : %d\n\n", points);

            printGrid(grid);

            printf("\nGuess the word : ");
            char guess[20];
            scanf(" %s", guess);

            if(strcasecmp(guess, words[random_index]) == 0){
                printf("Correct Guess!\n");
                points++;
                break;
            }
            else{
                printf("Incorrect Guess!\n");
            }

        }

    }
    return 0;
}
