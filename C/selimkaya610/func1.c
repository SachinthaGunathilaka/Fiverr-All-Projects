# include "func1.h"

// Implementation of the readFile method
int *readFile(char *filename, int *size) {

    static int *numbers = NULL;
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    // Open given file
    fp = fopen(filename, "r");

    // If the file does not found
    if (fp == NULL)
        printf("File Not Found\n");

    int is_size = 1;
    int value_index = 0;

    // Read line by line of the given file
    while ((getline(&line, &len, fp)) != -1) {
        char data[10];
        int char_index = 0;

        // Extract values from the given file
        for (int i = 0; i < strlen(line); ++i) {
            if (line[i] == ',' || line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
                if (char_index == 0)
                    continue;
                data[char_index++] = '\0';

                // Read the size
                if (is_size == 1) {
                    *size = atoi(data);

                    // Dynamically allocate memory according to the size
                    numbers = (int *) malloc(sizeof(int) * (*size));
                    is_size = 0;
                }

                    // Store values in the numbers array
                else {
                    numbers[value_index++] = atoi(data);
                }
                char_index = 0;
            } else {
                data[char_index++] = line[i];
            }
        }
        // Read the last data
        if (char_index != 0) {
            numbers[value_index++] = atoi(data);
        }
    }

    // return numbers array
    return numbers;

}










