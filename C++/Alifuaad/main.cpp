#include <iostream>

using namespace std;

int main() {
    double base, height;
    cout << "Enter positive value for base : ";
    cin >> base;

    cout << "Enter positive value for height : ";
    cin >> height;

    if(base < 0 || height < 0){
        cout << "One of the dimensions is negative" << endl;
    }
    else{
        double area = 0.5 * base * height;
        cout << "Area : " << area;
    }

    return 0;
}
