#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

    if (argc != 3) {
        cout << "Invalid number of arguments" << endl;
        return 0;
    }

    char data[100];

    string in_filename = argv[1];
    string out_filename = argv[2];
    bool status = true;

    ifstream infile(in_filename);
    ofstream outfile(out_filename);

    while (true){

        if (!infile.is_open()) {
            cout << "Unable to open input file" << endl;

            cout << "Enter filename: ";
            cin >> in_filename;
            infile.clear();
            infile.open(in_filename);

            continue;
        }

        break;
    }

    while (true){

        if (!outfile.is_open()) {
            cout << "Unable to open output file" << endl;

            cout << "Enter filename: ";
            cin >> out_filename;
            outfile.clear();
            outfile.open(out_filename);
            continue;
        }

        break;
    }

    int num_of_quiz_scores, num_of_homework_scores, num_of_exam_scores;
    infile >> num_of_quiz_scores >> num_of_homework_scores >> num_of_exam_scores;

    if (infile.fail() && infile.eof()) {
        cout << "Empty input file" << endl;
        outfile << "Empty input file" << endl;
        return 0;
    }



    return 0;
}
