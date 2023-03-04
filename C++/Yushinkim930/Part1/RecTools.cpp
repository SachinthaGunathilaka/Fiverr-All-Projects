// Include RecTools.h file
#include "RecTools.h"

/*
    Function to calculate factorial value
    arg : n -> integer value
*/
int RecTools::fact(int n) {
    // Base case (If n is less than 2 return 1)
    if (n < 2) {
        return 1;
    }

    // Recursive call
    // Call fact function for n-1 and multiplied by n
    return n * fact(n - 1);
}


/*
    Function to calculate Fibonacci value
    arg : x -> integer value
*/
int RecTools::fib(int x) {

    // Base case 1
    // If x is less than 0, return 0
    if (x < 0)
        return 0;

    // Base case 2
    // If x is less than 2, return x
    if (x < 2)
        return x;

    // Recursive call
    // Call fib function for x-1 and x-2 and get the summation of 2 results.
    return fib(x - 1) + fib(x - 2);
}
