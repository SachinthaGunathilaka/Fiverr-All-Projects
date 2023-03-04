#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>


using namespace std;
int main() {
    string filename = "numbers.txt";
    ifstream infile(filename);

    double number, total, max_number;
    int count = 0, negative_count = 0;
    while (infile >> number)
    {
        count++;
        total += number;

        if(number < 0)
            negative_count++;

        if(max_number < number){
            max_number = number;
        }
    }

    infile.close();

    cout << "Total result: " << total << endl;
    cout << "Numbers added: " << count << endl;
    cout << "Average number: " << fixed << setprecision(2) << total/count << endl;
    cout << "Maximum number: " << max_number << endl;
    cout << "Negative numbers: " << negative_count << endl;


    ofstream MyFile("total.txt");

    MyFile << total << endl;
    MyFile.close();

    return 0;
}
