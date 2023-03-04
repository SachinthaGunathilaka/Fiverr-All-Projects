#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"

using namespace std;


int main() {

    BST bst, *root = NULL;

    ifstream file;
    file.open("Summary.txt");


    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 0;
    }

    char ch;
    string word;
    int num_of_sentences = 0;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            word += tolower(ch);
        } else {
            if (ch == '.') {
                num_of_sentences++;
            }
            if (word.size() == 0)
                continue;
            root = bst.Insert(root, word);
            word = "";
        }
    }


    ofstream outputFile("output.txt");


    outputFile << setw(40) << "STATISTICAL SUMMARY" << endl;
    BST::generateStatistics(root);
    BST::displayStatistics(num_of_sentences, outputFile);

    outputFile << "\n" << setw(40) << "STYLE WARNINGS\n" << endl;
    outputFile << "WORDS USED TOO OFTEN: ( WORDS OF MORE THAN 3 LETTERS THAT ARE USED MORE THAN 5%\n"
            "OF THE TOTAL NUMBER OF WORDS OF MORE THAN 3 LETTERS )\n" << endl;

    BST::displayWordsUsedTooOften(root, outputFile);
    BST::displayStyleWarnings(root, num_of_sentences, outputFile);

    outputFile << "\n" << setw(40) << "INDEX OF UNIQUE WORDS\n" << endl;
    outputFile << "\t" << 'A' << endl;
    BST::displayUniqueWords(root, outputFile);



    outputFile.close();



    return 0;
}