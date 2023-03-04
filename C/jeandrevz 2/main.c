// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct node {
    int x_position;
    int player_row;
    int player_col;
    struct node *next;
};

struct node *head = NULL;


//insert link at the first location
void insertFirst(int x_position, int player_row, int player_col) {
    //create a link
    struct node *link = (struct node *) malloc(sizeof(struct node));

    link->x_position = x_position;
    link->player_row = player_row;
    link->player_col = player_col;

    //point it to old first node
    link->next = head;

    //point first to new first node
    head = link;
}

//delete first item
struct node *deleteFirst() {
    //save reference to first link
    struct node *tempLink = head;

    //mark next to first link as first
    head = head->next;

    //return the deleted link
    return tempLink;
}

//is list empty
int isEmpty() {
    return head == NULL;
}

// Global variables
int map_row, map_col, player_row, player_col, goal_row, goal_col;
char *map;
int num_of_blocks = 0;


// Function to display the map
void display() {

    // Iterate through each row
    for (int i = 0; i < map_row + 2; ++i) {
        // Iterate though each column
        for (int j = 0; j < map_col + 2; ++j) {
            // Display stars
            if (i == 0 || i == map_row + 1 || j == 0 || j == map_col + 1)
                printf("*");

                // Display player position by char 'P'
            else if (i == player_row + 1 && j == player_col + 1)
                printf("\33[34mP\33[0m");

                // Display goal position by char 'G'
            else if (i == goal_row + 1 && j == goal_col + 1)
                printf("\33[33mG\33[0m");

                // Display blocks
            else if (map[(i - 1) * map_col + (j - 1)] == 'X') {
                if (head != NULL && head->x_position == (i - 1) * map_col + (j - 1)) {
                    printf("\33[41mX\33[0m");

                } else {
                    printf("X");
                }

            }
                // Display spaces
            else
                printf(" ");
        }
        printf("\n");
    }

    // Display menu
    printf("Press w to go up\n"
           "Press s to do down\n"
           "Press a to go left\n"
           "Press d to go right\n"
           "Press u to undo\n");

}

// Function to check validity of the arguments
int checkArguments() {

    // If player and goal is in same position throw an error
    if (player_row == goal_row && player_col == goal_col) {
        printf("Player and the Goal cannot be in same position\n");
        return 0;
    }
        // Check for invalid position of the player
    else if (player_row < 0 || player_row >= map_row || player_col < 0 || player_col >= map_col) {
        printf("Invalid position of the Player.\n");
        return 0;
    }
        // Check for invalid position of the goal
    else if (goal_row < 0 || goal_row >= map_row || goal_col < 0 || goal_col >= map_col) {
        printf("Invalid position of the Goal.\n");
        return 0;
    }

    return 1;
}

// Function to get input from the user
char getInput() {
    char input;
    scanf("%c", &input);

    // Get input until user enter valid input
    while (input != 'w' && input != 's' && input != 'a' && input != 'd' && input != 'u') {
        scanf(" %c", &input);
    }

    return input;
}

// Function to generate random block
int generateRandomBlock() {

    // Generate random number
    int max_blocks = map_col * map_row - 2 - num_of_blocks;
    int position = (rand() % (max_blocks));

    int correct_pos = 0;

    // Find free position of the map (Position with space)
    for (int i = 0; i < map_row; ++i) {
        for (int j = 0; j < map_col; ++j) {
            int flag = 1;

            if (i == player_row && j == player_col)
                flag = 0;

            if (i == goal_row && j == goal_col)
                flag = 0;

            if (map[i * map_col + j] == 'X')
                flag = 0;

            if (flag)
                position--;

            if (position == -1) {
                // Block the selected entry in the map
                map[correct_pos] = 'X';
                num_of_blocks++;

                return correct_pos;
            }

            correct_pos++;

        }
    }

    return correct_pos;
}

// Function to check whether player or goal is blocked
int isLose() {
    // Check whether player is blocked
    if (((map[(player_row + 1) * map_col + player_col] == 'X') || player_row == map_row - 1) &&
        ((map[(player_row - 1) * map_col + player_col] == 'X') || player_row == 0) &&
        ((map[player_row * map_col + player_col + 1] == 'X') || player_col == map_col - 1) &&
        ((map[player_row * map_col + player_col - 1] == 'X') || (player_col == 0))) {

        return 1;
    }

    // Check whether goal is blocked
    if (((map[(goal_row + 1) * map_col + goal_col] == 'X') || goal_row == map_row - 1) &&
        ((map[(goal_row - 1) * map_col + goal_col] == 'X') || goal_row == 0) &&
        ((map[goal_row * map_col + goal_col + 1] == 'X') || goal_col == map_col - 1) &&
        ((map[goal_row * map_col + goal_col - 1] == 'X') || (goal_col == 0))) {

        return 2;
    }

    return 0;
}


// Main function
int main(int argc, char *argv[]) {

    // If the arguments are not given correctly, display correct order of the arguments
    if (argc < 2) {
        printf("usage : ./escape <filename>\n");
        return 0;
    }

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    int first_line = 1;
    char *token;
    while ((getline(&line, &len, fp)) != -1) {
        token = strtok(line, " ");
        int index = 0, first, second;
        char type;

        while (token != NULL) {

            if (first_line) {
                if (index == 0)
                    map_row = atoi(token);
                else {
                    map_col = atoi(token);
                    first_line = 0;

                    map = (char *) malloc(sizeof(char) * map_row * map_col);


                }

            } else {
                if (index == 0)
                    first = atoi(token);
                else if (index == 1)
                    second = atoi(token);
                else {
                    type = token[0];

                    if(type  == 'P'){
                        player_row = first;
                        player_col = second;
                    }
                    else if(type == 'G'){
                        goal_row = first;
                        goal_col = second;
                    }
                    else if(type == 'X')
                        map[map_col * first + second] = 'X';
                }


            }


            index++;
            token = strtok(NULL, " ");
        }


    }



    fclose(fp);
    if (line)
        free(line);


    srand(time(NULL));


    // Display map with the menu
    display();

    // Infinite loop
    while (1) {

        int prev_player_row = player_row;
        int prev_player_col = player_col;
        // Get input from user
        char input = getInput();

        if(input == 'u'){
            if(head != NULL){
                player_row = head->player_row;
                player_col = head->player_col;
                map[head->x_position] = ' ';
                deleteFirst();
            }
            display();
            continue;
        }

        int flag = 0;
        // Move up
        if (input == 'w') {
            if (player_row != 0 && map[(player_row - 1) * map_col + player_col] != 'X') {
                player_row -= 1;
                flag = 1;
            }
        }
            // Move down
        else if (input == 's') {
            if (player_row != map_row - 1 && map[(player_row + 1) * map_col + player_col] != 'X') {
                player_row += 1;
                flag = 1;
            }
        }
            // Move left
        else if (input == 'a' && map[player_row * map_col + player_col - 1] != 'X') {
            if (player_col != 0) {
                player_col -= 1;
                flag = 1;

            }
        }
            // Move right
        else if (input == 'd' && map[player_row * map_col + player_col + 1] != 'X') {
            if (player_col != map_col - 1) {
                player_col += 1;
                flag = 1;

            }
        }

        // Generate random block entry if the given user move is valid
        if (flag) {
            int x_pos = generateRandomBlock();
            insertFirst(x_pos, prev_player_row, prev_player_col);
        }

        // Check whether the user is won
        if (player_row == goal_row && player_col == goal_col) {
            display();
            printf("You win!\n");
            break;
        }
            // If player is blocked
        else if (isLose() == 1) {
            display();
            printf("Player is Closed!\n");
            break;
        }
            // If goal is blocked
        else if (isLose() == 2) {
            display();
            printf("Goal is Closed!\n");
            break;
        }

        // Display the map again
        display();

    }

    // Deallocate the memory used for map
    free(map);
    return 0;
}
