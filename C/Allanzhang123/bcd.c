#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int bcd(int bcd_value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= 0x0909);
        int bcd_value = l;

        printf("%d\n", bcd(bcd_value));
    }

    return 0;
}

// given a  BCD encoded value between 0 .. 99
// return corresponding integer
int bcd(int bcd_value) {

    // PUT YOUR CODE HERE
    int bit = 0, result = 0;
    for (int i = 15; i >= 0; i--) {

        if((i != 15) && ((i+1)%8 == 0)){
            result *= 10;
            result += bit;
            bit = 0;
        }

        bit = bit << 1;
        if (bcd_value & (1 << i)) {
            bit |= 1;
        }
    }

    result *= 10;
    result += bit;

    return result;

}
