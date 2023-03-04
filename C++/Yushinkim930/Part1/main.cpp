#include <iostream>
#include "RecTools.h"

using namespace std;

// For Testing
int main() {

    // Create object of RecTools
    RecTools recTools;


    // Test fact function
    cout << "\nFactorial 0 = " << recTools.fact(0) << endl;
    cout << "Factorial 1 = " << recTools.fact(1) << endl;
    cout << "Factorial 2 = " << recTools.fact(2) << endl;
    cout << "Factorial 5 = " << recTools.fact(5) << endl;

    cout << endl;

    // Test Fib function
    cout << "Fibonacci -1 = " << recTools.fib(-1) << endl;
    cout << "Fibonacci 0  = " << recTools.fib(0) << endl;
    cout << "Fibonacci 0  = " << recTools.fib(1) << endl;
    cout << "Fibonacci 2  = " << recTools.fib(2) << endl;
    cout << "Fibonacci 3  = " << recTools.fib(3) << endl;
    cout << "Fibonacci 4  = " << recTools.fib(4) << endl;
    cout << "Fibonacci 5  = " << recTools.fib(5) << endl;
    cout << "Fibonacci 6  = " << recTools.fib(6) << endl;

    return 0;
}
