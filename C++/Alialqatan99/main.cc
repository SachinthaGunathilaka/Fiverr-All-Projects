#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string read_file(string filename);
string upper(string word);
void replace(string &text, string replacement, vector<string> words_to_sensor,
             bool case_insensitive);
bool matches(string s1, string s2, bool case_insensitive);

int main(int argc, char *argv[]) {
    vector<string> words_to_sensor;
    bool case_insensitive = false;
    bool verbose = false;
    string replacement = "CENSORED";
    bool is_stdin = true;
    vector<string> filenames;

    int c;
    while ((c = getopt(argc, argv, "ivr:c:")) != -1) {
        switch (c) {
        case 'i':
            case_insensitive = true;
            break;
        case 'v':
            verbose = true;
            break;
        case 'c':
            words_to_sensor.push_back(optarg);
            break;
        case 'r':
            replacement = optarg;
            break;
        }
    }

    if (argc > optind) {
        is_stdin = false;
        for (int i = optind; i < argc; i++) {
            filenames.push_back(argv[i]);
        }
    }

    for (string filename : filenames) {
        if (verbose)
            cout << "Reading " << filename << "\n";
        string text = read_file(filename);
        replace(text, replacement, words_to_sensor, case_insensitive);
        cout << text << "\n";
    }

    if (is_stdin) {
        if (verbose)
            cout << "Reading standard input"
                 << "\n";
        stringstream buffer;
        buffer << cin.rdbuf();
        string text = buffer.str();
        replace(text, replacement, words_to_sensor, case_insensitive);
        cout << text << "\n";
    }

    return 0;
}

string read_file(string filename) {
    ifstream fin(filename);
    stringstream buffer;
    buffer << fin.rdbuf();
    fin.close();
    return buffer.str();
}

void replace(string &text, string replacement, vector<string> words_to_sensor,
             bool case_insensitive) {
    size_t i = 0;
    int begin = -1, end = -1;
    while (i < text.length()) {
        if (!isalpha(text[i]) && begin != -1) {
            string word = text.substr(begin, end - begin + 1);
            for (string word_to_sensor : words_to_sensor) {
                if (matches(word, word_to_sensor, case_insensitive)) {
                    text.replace(begin, word.length(), replacement);
                }
            }
            begin = -1;
            end = -1;
        }
        if (isalpha(text[i]) && begin == -1)
            begin = i;
        if (begin != -1)
            end = i;
        i++;
    }
}

string upper(string word) {
    string uppercase = word;
    for (auto &c : uppercase) {
        c = toupper(c);
    }
    return uppercase;
}

bool matches(string s1, string s2, bool case_insensitive) {
    return case_insensitive ? upper(s1) == upper(s2) : s1 == s2;
}
