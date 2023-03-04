#include <stdio.h>

int main() {
    int year;

    do{
        printf("Enter year: ");
        scanf(" %d", &year);

    } while (year < 1980 || year > 2020);

    for (int number = 1790; number < year; number+=4) {
        printf("%d\n", number);
    }
    return 0;
}
