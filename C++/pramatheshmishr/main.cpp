#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

    // Read File and store in array
    ifstream file("data.csv");
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    double data[100][2];
    int index = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string value1, value2;

        if (getline(ss, value1, ',') && getline(ss, value2, ',')) {
            data[index][0] = atof(value1.c_str());
            data[index][1] = atof(value2.c_str());
            index++;
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    file.close();

    // Perform addition and print the output
    for (int i = 0; i < index; ++i) {
        if (data[i][0] + data[i][1] < 10) {
            cout << "The sum is less than 10" << endl;
        } else {
            cout << "The sum is greater than 10" << endl;
        }
    }
    return 0;
}
