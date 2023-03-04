#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"

using namespace std;


int main(int argc, char ** argv) {

    // Validate arguments
    if (argc != 3) {
        cout << "usage: ./Bard <input file> <output file>" << endl;
        return 0;
    }

    Linkedlist linkedlist;

    // Read shakespeare-cleaned file and insert words to the linked list
    string filename = "shakespeare-cleaned.txt";
    ifstream infile(filename);
    string line;
    string word;
    unsigned int max_word_len = 0;
    while (getline(infile, line)) {

        std::istringstream iss(line);
        iss >> word;
        linkedlist.insertWord(word);


        if (max_word_len < word.size())
            max_word_len = word.size();

    }


    // Create linked list array and initialize it
    auto *linkedlist_arr = new Linkedlist[max_word_len - 4];
    for (unsigned int i = 0; i < max_word_len - 4; ++i) {
        linkedlist_arr[i] = Linkedlist();
    }

    // Add word in the linkedlist to relevant linked list in the linkedlist_arr
    Node *temp = linkedlist.head;
    while (temp != nullptr) {
        linkedlist_arr[temp->word.size() - 5].insertNode(temp->word, temp->count);
        temp = temp->next;
    }


    // Read input file and handle each query
    unsigned int length;
    int rank;
    ifstream input_infile(argv[1]);
    ofstream outfile(argv[2]);
    while (getline(input_infile, line)) {

        std::istringstream iss(line);
        iss >> length >> rank;

        if (length < 5 || length > max_word_len) {
            outfile << "-" << endl;
        } else {
            linkedlist_arr[length - 5].sort(rank);
            outfile << linkedlist_arr[length - 5].getWordByIndex(rank) << endl;
        }

    }
    outfile.close();


    return 0;
}
