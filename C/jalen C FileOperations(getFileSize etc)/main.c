// C program to find the size of file
#include <stdio.h>
#include<dirent.h>
#include<string.h>
#include <sys/stat.h> // mkdir
#include <stdlib.h>
#include <time.h>

// function to find the size of the file
long int findSize(char file_name[]) {
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    return res;
}

// Display main menu function
void displayMainMenu() {
    printf("\n1. Select file to process\n"
           "2. Exit the program\n");
}


// display secondary menu function
void displaySecondaryMenu() {
    printf("\nWhich file you want to process?\n"
           "Enter 1 to pick the largest file\n"
           "Enter 2 to pick the smallest file\n"
           "Enter 3 to specify the name of a file\n");
}

// function for get user input
int getUserInput(int low, int high, char *title) {
    int option;
    printf("%s", title);
    scanf(" %d", &option);
    while (option < low || option > high) {
        printf("Invalid Option\n");
        printf("%s", title);
        scanf(" %d", &option);
    }
    return option;
}


// Main function
int main() {
    int option = 1;
    while (option != 2) {
        displayMainMenu();
        option = getUserInput(1, 2, "\nEnter a choice 1 or 2 : ");
        // If user want to select file for process
        if (option == 1) {
            char filename[50];
            while (1) {
                strcpy(filename, "");
                displaySecondaryMenu();
                int option2 = getUserInput(1, 3, "\nEnter a choice from 1 to 3 : ");

                // Process the largest file
                if (option2 == 1) {
                    DIR *d;
                    struct dirent *dir;
                    d = opendir(".");
                    if (d) {
                        long int largest_file_size = 0;
                        while ((dir = readdir(d)) != NULL) {
                            // compare file size
                            if (strncmp("movies_", dir->d_name, 7) == 0) {
                                long int file_size = findSize(dir->d_name);
                                if (file_size > largest_file_size) {
                                    largest_file_size = file_size;
                                    strcpy(filename, dir->d_name);
                                }
                            }
                        }

                        closedir(d);
                    }
                    break;
                }

                // Process the smallest file
                if (option2 == 2) {
                    DIR *d;
                    struct dirent *dir;
                    d = opendir(".");
                    if (d) {
                        long int smallest_file_size = 9223372036854775807;
                        while ((dir = readdir(d)) != NULL) {
                            if (strncmp("movies_", dir->d_name, 7) == 0) {
                                long int file_size = findSize(dir->d_name);
                                if (file_size < smallest_file_size) {
                                    smallest_file_size = file_size;
                                    strcpy(filename, dir->d_name);
                                }
                            }
                        }

                        closedir(d);
                    }
                    break;
                }

                // process for user given file
                if (option2 == 3) {
                    printf("Enter the complete file name : ");
                    scanf("%s", filename);

                    FILE *fp;
                    fp = fopen(filename, "r");
                    if (fp == NULL) {
                        printf("The file %s was not found. Try again\n", filename);
                        continue;
                    }

                    fclose(fp);
                    break;
                }
            }

            // If there are no files start with "movies_"
            if (strcmp(filename, "") == 0) {
                printf("No file start with movies_\n");
                break;
            }

            printf("\nNow processing the chosen file named %s\n", filename);

            // Generate random number
            srand(time(0));
            char random_num[20];
            sprintf(random_num, "%d", rand() % (99999 + 1));
            char dir_name[] = "Bembir.movies.";
            strcat(dir_name, random_num);

            // Create directory with "-rwxr-x---" permission
            mkdir(dir_name, 0750);
            printf("\nCreated directory with name %s\n", dir_name);


            FILE *fp;
            char *line = NULL;
            size_t len = 0;
            char title[50];
            int year;
            fp = fopen(filename, "r");
            if (fp == NULL)
                printf("An error occurred during reading the file");

            int years[1000];
            int year_count = 0;
            int movie_count = 0;

            // Iterate through each line in the given file
            while ((getline(&line, &len, fp)) != -1) {
                movie_count++;

                if (movie_count == 1)
                    continue;

                // Extract title and the year
                char *data = strtok(line, ",");
                strcpy(title, data);
                data = strtok(NULL, ",");
                year = atoi(data);

                int isFind = 0;

                // Check whether the file is created for relevant year
                for (int i = 0; i < year_count; ++i) {

                    // If the file is already created
                    if (years[i] == year) {
                        char year_[20];
                        sprintf(year_, "%d", year);
                        char year_char[50];
                        snprintf(year_char, sizeof(year_char), "%s/%s.txt", dir_name, year_);

                        // Append the title to the file
                        FILE *fp_w = fopen(year_char, "a");
                        fprintf(fp_w, "%s\n", title);
                        fclose(fp_w);
                        isFind = 1;

                    }
                }

                // If the file is not created
                if (isFind == 0) {
                    char year_[20];
                    sprintf(year_, "%d", year);
                    char year_char[50];
                    snprintf(year_char, sizeof(year_char), "%s/%s.txt", dir_name, year_);

                    // Create the file with "-rw-r-----" permission
                    FILE *fp_w = fopen(year_char, "w");
                    chmod(year_char, 0650);

                    // Add title to the file
                    fprintf(fp_w, "%s\n", title);
                    fclose(fp_w);

                    // Add year to the years array
                    years[year_count] = year;
                    year_count++;
                }
            }
            fclose(fp);

        }

    }

    return 0;
}