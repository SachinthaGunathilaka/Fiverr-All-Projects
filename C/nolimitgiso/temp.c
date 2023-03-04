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
    int divider;
    while (input != 0) {

        divider = 10;
        while (divider <= input)
            divider *= 10;


        if (divider != 10) {
            printf("%d  ", getQuotient(input, divider / 10));

        } else{
            printf("%d", getQuotient(input, divider / 10));
        }
        input = getRemainder(input, divider / 10);
    }

    while (divider > 10) {
        if (divider == 100) {
            printf("0");
        } else {
            printf("0  ");
        }
        divider /= 10;
    }
    printf("\n");
    return 0;
}
