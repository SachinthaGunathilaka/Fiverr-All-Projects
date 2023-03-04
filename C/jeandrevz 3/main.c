
// Include libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// Global variables
int rows, cols;
char *map;
int ant1_row, ant1_col, ant2_row, ant2_col;
char ant1_dir, ant2_dir;


// Function to move the Ant1 according to the given specifications
void moveAnt1() {

    // If the ant is in a neutral cell
    if (map[ant1_row * cols + ant1_col] == '0') {
        // Highlight the current cell
        map[ant1_row * cols + ant1_col] = '2';

        // If the current direction is ^
        if (ant1_dir == '^') {

            // Change ant direction
            ant1_dir = '>';

            // Validate the move
            if (ant1_col != cols - 1 && ((ant1_col + 1) != ant2_col)) {
                ant1_col++;
            }
        }

            // If the current direction is >
        else if (ant1_dir == '>') {
            ant1_dir = 'v';

            if (ant1_col != rows - 1 && ((ant1_row + 1) != ant2_row)) {
                ant1_row++;
            }
        }
            // If the current direction is v
        else if (ant1_dir == 'v') {
            ant1_dir = '<';

            if (ant1_col != 0 && ((ant1_col - 1) != ant2_col)) {
                ant1_col--;
            }
        }
            // If the current direction is <
        else {
            ant1_dir = '^';

            if (ant1_row != 0 && ((ant1_row - 1) != ant2_row)) {
                ant1_row--;
            }
        }
    }
        // If the ant is in a highlighted cell
    else {

        // Mark the current cell as a neutral cell
        map[ant1_row * cols + ant1_col] = '0';

        // If the current direction is ^
        if (ant1_dir == '^') {
            ant1_dir = '<';

            if (ant1_col != 0 && ((ant1_col - 1) != ant2_col)) {
                ant1_col--;
            }
        }
            // If the current direction is <
        else if (ant1_dir == '<') {
            ant1_dir = 'v';

            if (ant1_col != rows - 1 && ((ant1_row + 1) != ant2_row)) {
                ant1_row++;
            }
        }
            // If the current direction is v
        else if (ant1_dir == 'v') {
            ant1_dir = '>';

            if (ant1_col != cols - 1 && ((ant1_col + 1) != ant2_col)) {
                ant1_col++;
            }
        }
            // If the current direction is >
        else {
            ant1_dir = '^';

            if (ant1_row != 0 && ((ant1_row - 1) != ant2_row)) {
                ant1_row--;
            }
        }
    }
}

// Function to move the ant2 randomly
void moveAnt2() {


    // If the current cell is neutral, highlight it
    if (map[ant2_row * cols + ant2_col] == '0') {
        map[ant2_row * cols + ant2_col] = '3';
    }
        // If the current cell is highlighted cell, mark it as neutral
    else {
        map[ant2_row * cols + ant2_col] = '0';
    }


    // Randomly choose a direction and move
    // If the move is not valid, choose direction again randomly
    while (1) {
        int direction = rand() % (4);


        if (direction == 0) {
            ant2_dir = '>';
            if (ant2_col != cols - 1 && ((ant2_col + 1) != ant1_col)) {
                ant2_col++;
                break;
            }
        } else if (ant2_dir == '>') {
            ant2_dir = 'v';

            if (ant2_col != rows - 1 && ((ant2_row + 1) != ant1_row)) {
                ant2_row++;
                break;

            }
        } else if (ant2_dir == 'v') {
            ant2_dir = '<';

            if (ant2_col != 0 && ((ant2_col - 1) != ant1_col)) {
                ant2_col--;
                break;

            }
        } else {
            ant2_dir = '^';

            if (ant2_row != 0 && ((ant2_row - 1) != ant1_row)) {
                ant2_row--;
                break;

            }
        }
    }


}


// Function to display the map
void display() {

    // Iterate through each row

    for (int i = 0; i < rows + 2; ++i) {
        // Iterate though each column
        for (int j = 0; j < cols + 2; ++j) {
            char icon = ' ';

            // Display stars
            if (i == 0 || i == rows + 1 || j == 0 || j == cols + 1) {
                printf("*");
                continue;
            }


            if (i == ant1_row + 1 && j == ant1_col + 1) {
                icon = ant1_dir;
            } else if (i == ant2_row + 1 && j == ant2_col + 1) {
                icon = ant2_dir;
            }

            if (map[(i - 1) * cols + (j - 1)] == '1')
                printf("\33[42m%c\33[0m", icon);


            else if (map[(i - 1) * cols + (j - 1)] == '2')
                printf("\33[41m%c\33[0m", icon);

            else if (map[(i - 1) * cols + (j - 1)] == '3')
                printf("\33[44m%c\33[0m", icon);

            else
                printf("%c", icon);

        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {


    // If the arguments are not given correctly, display correct order of the arguments
    if (argc < 4) {
        printf("usage : ./ant <filename> <steps> <delay>\n");
        return 0;
    }


    int steps = atoi(argv[2]);
    int delay_time = atoi(argv[3]);


    // Read map file
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    int line_no = 0;
    char *token;


    while ((getline(&line, &len, fp)) != -1) {
        token = strtok(line, " ");

        if (line_no == 0) {
            rows = atoi(token);
            token = strtok(NULL, " ");
            cols = atoi(token);

            map = (char *) malloc(sizeof(char) * rows * cols);

        } else if (line_no == 1) {
            ant1_row = atoi(token);
            token = strtok(NULL, " ");
            ant1_col = atoi(token);
            token = strtok(NULL, " ");
            ant1_dir = token[0];

        } else if (line_no == 2) {
            ant2_row = atoi(token);
            token = strtok(NULL, " ");
            ant2_col = atoi(token);
            token = strtok(NULL, " ");
            ant2_dir = token[0];

        } else {
            int col_index = 0;
            while (token != NULL) {

                map[(line_no - 3) * cols + col_index] = token[0];
                token = strtok(NULL, " ");

                col_index++;
            }
        }

        line_no++;


    }

    // Automate the moves of ants
    for (int i = 0; i < steps; ++i) {
        display();

        sleep(delay_time);
        moveAnt1();
        moveAnt2();
    }


    fclose(fp);
    if (line)
        free(line);

    srand(time(NULL));


    return 0;
}
