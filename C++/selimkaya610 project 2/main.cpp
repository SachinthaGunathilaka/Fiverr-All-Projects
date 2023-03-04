#include <iostream>

using namespace std;

struct coordinate {
    double x;
    double y;
    double z;
};

void square(double &a) {
    a = a * a;
}

void square_struct(struct coordinate &coord) {
    square(coord.x);
    cout << "X coordinate-squared:" << endl;
    cout << "The coordinates (x,y,z) are (";
    cout << coord.x << "," << coord.y << "," << coord.z << ")" << endl;


    square(coord.y);
    cout << "Y coordinate-squared:" << endl;
    cout << "The coordinates (x,y,z) are (";
    cout << coord.x << "," << coord.y << "," << coord.z << ")" << endl;

    square(coord.z);
    cout << "Z coordinate-squared:" << endl;
    cout << "The coordinates (x,y,z) are (";
    cout << coord.x << "," << coord.y << "," << coord.z << ")" << endl;
}

int main() {

    struct coordinate coord;
    cout << "Input the (x,y,z) coord. of the location:" << endl;
    cin >> coord.x;
    cin >> coord.y;
    cin >> coord.z;

    cout << "The coordinates (x,y,z) are (";
    cout << coord.x << "," << coord.y << "," << coord.z << ")" << endl;

    while (true) {
        square_struct(coord);

        cout << "Input the (x,y,z) coord. of the location:" << endl;

        cin >> coord.x;
        cin >> coord.y;
        cin >> coord.z;
        cout << "The new value of coordinates (x,y,z) are (";
        cout << coord.x << "," << coord.y << "," << coord.z << ")" << endl;

    }
    return 0;
}
