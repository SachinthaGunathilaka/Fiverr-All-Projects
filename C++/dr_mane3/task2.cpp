#include <iostream>

using namespace std;

int main() {
    int numbers[5][3] = {{1, 6, 3}, {5, 3, 2}, {8, 7, 4}, {5, 3, 2}, {12, 43, 6}};

    int max = numbers[0][0];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (numbers[i][j] > max)
                max = numbers[i][j];
        }
    }

    cout << "Largest number : " << max << endl;

    int min = numbers[0][0];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (numbers[i][j] < min)
                min = numbers[i][j];
        }
    }

    cout << "Smallest number : " << min << endl;


    return 0;
}
