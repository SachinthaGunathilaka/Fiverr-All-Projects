#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10;
    int b = 20;

    cout << "Before swap value of a : " << a << endl;
    cout << "Before swap Value of b : " << b << endl;


    swap(a, b);

    cout << "\nAfter swap value of a : " << a << endl;
    cout << "After swap value of b : " << b << endl;
    return 0;
}
