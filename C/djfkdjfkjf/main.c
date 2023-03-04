#include <stdio.h>

int main() {


    int myArr[8];
    myArr[0] = 30;

    int n;

    for(n = 0; n < 8; n++)
    {
        myArr[n+1] = myArr[n] - ((n+1) * (n+1));
    }

    for(n = 0; n < 8; n++)
    {
        printf("%d\t", myArr[n]);
    }

    return 0;
}
