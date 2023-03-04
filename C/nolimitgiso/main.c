#include <stdio.h>

int getQuotient(int a, int b) {
    return a / b;
}

int getRemainder(int a, int b) {
    return a % b;
}

int main() {

    int input;
    printf("Enter an integer between 1 and 32767: ");
    scanf(" %d", &input);

    while (input < 1 || input > 32767){
        printf("Invalid input!\n");
        printf("Enter an integer between 1 and 32767: ");
        scanf(" %d", &input);
    }

    printf("The digits in the number are:\n");
    int digits[5];
    int index = 0;
    while (input != 0) {
        digits[index] = getRemainder(input, 10);
        input = getQuotient(input, 10);
        index++;
    }

    for (int i = index - 1; i >= 0; --i) {
        if (i == 0) {
            printf("%d", digits[i]);
        } else {
            printf("%d  ", digits[i]);
        }
    }

    return 0;
}
