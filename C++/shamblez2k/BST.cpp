#include "BST.h"


int BST::words = 0;
int BST::u_words = 0;
int BST::u_words_3_l = 0;
int BST::total_w_len = 0;
int BST::warning_u_words = 0;
int BST::words_3_l = 0;
char BST::letter = 'A';

BST::BST()
        : word(""), left(NULL), right(NULL), count(1) {
}

BST::BST(string given_word) : word(std::move(given_word)), count(1) {
    left = right = NULL;
}

BST *BST::Insert(BST *root, string word) {
    if (!root) {
        return new BST(word);
    }

    if (word == root->word) {
        root->count++;
    } else if (word > root->word) {
        root->right = Insert(root->right, word);
    } else {
        root->left = Insert(root->left, word);
    }

    return root;
}


//void BST::Inorder(BST *root) {
//    if (!root) {
//        return;
//    }
//    Inorder(root->left);
//    cout << *root << endl;
//    Inorder(root->right);
//}

ostream &operator<<(ostream &os, const BST &bst) {
    char letter;
    letter = toupper(bst.word[0]);
    os << letter;
    for (int i = 1; i < bst.word.size(); ++i) {
        os << bst.word[i];
    }
    return os;
}

void BST::generateStatistics(BST *root) {
    if (!root) {
        return;
    }

    u_words++;
    words += root->count;
    if (root->word.size() > 3) {
        words_3_l += root->count;
        u_words_3_l++;

    }

    total_w_len += root->word.size() * root->count;

    generateStatistics(root->left);
    generateStatistics(root->right);
}

void BST::displayStatistics(int num_of_sentences, ofstream & outputFile) {

    outputFile << "\nTOTAL NUMBER OF WORDS: " << words << "\n" <<
         "TOTAL NUMBER OF “UNIQUE” WORDS: " << u_words << "\n" <<
         "TOTAL NUMBER OF “UNIQUE” WORDS OF MORE THAN THREE LETTERS: " << u_words_3_l << "\n" <<
         "AVERAGE WORD LENGTH: " << total_w_len / words << " characters\n" <<
         "AVERAGE SENTENCE LENGTH: " << words / num_of_sentences << " words" << endl;

}

void BST::displayWordsUsedTooOften(BST *root, ofstream & outputFile) {

    if (!root) {
        return;
    }

    if ((root->word.size() > 3) && (root->count > (words_3_l / 20))) {
        warning_u_words++;
        outputFile << "\t" << warning_u_words << ") " << *root << endl;
    }

    displayWordsUsedTooOften(root->left, outputFile);
    displayWordsUsedTooOften(root->right, outputFile);
}

void BST::displayStyleWarnings(BST *root, int num_of_sentences, ofstream & outputFile) {

    if (words / num_of_sentences > 10) {
        outputFile << "\nAVERAGE SENTENCE LENGTH TOO LONG – " << words / num_of_sentences << " words" << endl;
    }
    if (total_w_len / words > 5) {
        outputFile << "AVERAGE WORD LENGTH TOO LONG – " << total_w_len / words << " characters" << endl;
    }
}


void BST::displayUniqueWords(BST *root, ofstream & outputFile) {
    BST::letter = 'A';
    displayUniqueWordsRecursive(root, outputFile);
}
void BST::displayUniqueWordsRecursive(BST *root, ofstream & outputFile) {
    if (!root) {
        return;
    }


    displayUniqueWordsRecursive(root->left, outputFile);
    if (letter != toupper(root->word[0])) {
        letter = toupper(root->word[0]);
        outputFile << "\n\t" << letter << endl;
    }
    outputFile << root->word << endl;
    displayUniqueWordsRecursive(root->right, outputFile);
}





