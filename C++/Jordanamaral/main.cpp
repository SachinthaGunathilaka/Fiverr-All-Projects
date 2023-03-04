#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void getFileName(string &);

void processFile(const string &, string);

void printResults(const string &, int);

int main() {
    string filename, search_word;
    getFileName(filename);

    cout << "Enter string to search : ";
    getline(cin, search_word);

    processFile(filename, search_word);


    return 0;
}

void getFileName(string &filename) {
    cout << "Enter filename : ";
    getline(cin, filename);

    while (filename.empty()) {
        cout << "Filename cannot be empty. Enter filename : ";
        getline(cin, filename);
    }
}

void processFile(const string &filename, string search_word) {
    string line;
    ifstream infile(filename);
    int occurrences = 0;
    cout << "\nLine contains the word \'" << search_word << "\' are : " << endl;
    while (getline(infile, line)) {
        for (int i = 0; i < line.size(); ++i) {
            line[i] = tolower(line[i]);
        }


        int start = 0;
        bool flag = false;

        int find_index = line.find(search_word, start);
        while (find_index != std::string::npos) {
            occurrences++;
            flag = true;
            start = find_index + 1;
            find_index = line.find(search_word, start);

        }

        if (flag)
            cout << "\t" << line << endl;
    }

    printResults(search_word, occurrences);
}

void printResults(const string &search_word, int occurrences) {
    cout << "\nNumber of occurrences of word \'" << search_word << "\'" << " : " << occurrences << endl;
}
