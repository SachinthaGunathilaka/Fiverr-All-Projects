#include <stdio.h>

int main() {
    int number;

    printf("Enter an unsigned int: ");
    scanf(" %d", &number);

    printf("Before bits are reversed:\n\t%d = ", number);
    for (int i = 15; i >= 0; --i) {
        printf("%d", (number >> i) & 1);
    }

    printf("\n");
    int reversed = 0;

    for (int i = 0; i < 16; i++) {
        if (number & (1 << i))
            reversed |= (1 << (15 - i));
    }

    printf("After bits are reversed:\n\t%d = ", reversed);
    for (int i = 15; i >= 0; --i) {
        printf("%d", (reversed >> i) & 1);
    }
    printf("\n");
    return 0;
}
