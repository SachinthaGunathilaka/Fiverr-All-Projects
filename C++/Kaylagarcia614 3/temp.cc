#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"

using namespace std;


int main() {

    Linkedlist linkedlist;


    string filename = "shakespeare-cleaned.txt";
    ifstream infile(filename);

    string line;
    string word;

    int max_word_len = 0;
    while (getline(infile, line)) {

        std::istringstream iss(line);
        iss >> word;
        linkedlist.insertWord(word);


        if (max_word_len < word.size())
            max_word_len = word.size();

    }


    auto *linkedlist_arr = new Linkedlist[max_word_len - 4];

    for (int i = 0; i < max_word_len - 4; ++i) {
        linkedlist_arr[i] = Linkedlist();

    }

    Node *temp = linkedlist.head;
    while (temp != nullptr) {
        linkedlist_arr[temp->word.size() - 5].insertNode(temp->word, temp->count);
        temp = temp->next;
    }

//    for (int i = 0; i < max_word_len - 4; ++i) {
//        linkedlist_arr[i].sort();
//    }
//
//
//    for (int i = 0; i < max_word_len - 4; ++i) {
//        cout << "\nWords with length " << (i + 5) << endl;
//        linkedlist_arr[i].printList();
//
//    }
//
////    linkedlist.sort();
//    linkedlist.printList();
//
    int length;
    int rank;



    string input_filename = "input.txt";
    string output_filename = "output.txt";
    ifstream input_infile(input_filename);

    linkedlist_arr[1].printList();


    ofstream outfile(output_filename);
    while (getline(input_infile, line)) {

        std::istringstream iss(line);
        iss >> length >> rank;

        if(length < 5 || length > max_word_len){
            outfile << "-" << endl;
        } else{
            cout << "-------------------------------------\n" << endl;
            linkedlist_arr[length-5].sort(rank);
            outfile << linkedlist_arr[length - 5].getWordByIndex(rank) << endl;
            linkedlist_arr[length-5].printList();

        }

    }
    outfile.close();


    return 0;
}
