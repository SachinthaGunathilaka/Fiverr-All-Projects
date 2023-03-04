#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<iomanip>
#include <fstream>


using namespace std;

class BST {
    int count;
    string word;
    BST *left, *right;

    static int words, words_3_l, u_words, u_words_3_l, total_w_len, warning_u_words;
    static char letter;

public:
    BST();

    BST(string word);

    BST *Insert(BST *, string);

//    void Inorder(BST*);

    static void generateStatistics(BST *root);

    static void displayStatistics(int num_of_sentences, ofstream & outputFile);

    static void displayWordsUsedTooOften(BST *root, ofstream & outputFile);

    static void displayStyleWarnings(BST *root, int num_of_sentences, ofstream & outputFile);

    static void displayUniqueWordsRecursive(BST *root, ofstream & outputFile);

    static void displayUniqueWords(BST *root, ofstream & outputFile);

    friend ostream &operator<<(ostream &os, const BST &bst);

};


#endif
