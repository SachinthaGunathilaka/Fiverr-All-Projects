#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

// Define some terms
const int TERMSIZE = 9000;
const int ADJACENT = 5;

int main() {
    // Define some variables
    string ifilename, ofilename;
    ifstream fIn;
    ofstream fOut;
    int n;


    // Create MyString array to hold all the terms
    MyString terms[TERMSIZE];
    // Create MyString array to hold all the words
    MyString word[ADJACENT];

    // Initialise termCount and wordCount to 0
    int termCount = 0;
    int wordCount = 0;

    // Get source data file name from user
    cout << "Enter the source date file name: ";
    cin >> ifilename;

    // Get number of adjacent words from user
    cout << "How many Adjacent words in a phrase, enter 1-5: ";
    cin >> n;

    // If user enter invalid value ask again
    while (n < 1 || n > 5) {
        cout << "Please enter value between 1 - 5 : " << endl;
        cin >> n;
    }

    // Get the output file name from user
    cout << "Enter the phase frequency file name: ";
    cin >> ofilename;

    // Open the input file for read
    fIn.open(ifilename);

    // Read first n - 1 words from the file and store in word Array
    int j = 0;
    while (!fIn.eof() && (j < (n - 1))) {
        // store word in the word array
        fIn >> word[j];
        // Remove non-alphanumeric characters from word and convert it to upper case
        word[j++].ToUpper();
        // Increment wordCount
        wordCount++;
    }

    // Read the whole file word by word
    while (!fIn.eof()) {
        // Read next word to l
        // ast element of the word array
        fIn >> word[n - 1];
        // Remove non-alphanumeric characters from word and convert it to upper case
        word[n - 1].ToUpper();

        // If the word is empty ignore that word
        if (word[n - 1].Length() == 0)
            continue;

        // Initialize the next term to empty string
        terms[termCount] = MyString();
        for (int k = 0; k < n; ++k) {
            // Generate next term and store it in the terms array
            terms[termCount] = terms[termCount] + word[k];

            // Rotate left the word array by 1
            if (k != n - 1)
                word[k] = word[k + 1];
        }

        // Increment the termCount and wordCount
        termCount++;
        wordCount++;

        // Linear search through each element in the terms array
        for (int l = 0; l < termCount - 1; ++l) {
            // If the term already exist in the array
            if (terms[l] == terms[termCount - 1]) {
                terms[l]++; // Increment the frequency of the term by 1
                termCount--;
                break;
            }
        }

    }
    fIn.close();


    // Selection sort of the terms array
    int min_idx; // To hold the index of the next minimum term

    // Iterate through each term in the terms array
    for (int i = 0; i < termCount - 1; i++) {
        // Find the minimum term in unsorted array
        min_idx = i;
        for (j = i + 1; j < termCount; j++)
            if ((terms[j] > terms[min_idx]))
                min_idx = j;

        // Swap the minimum term with the current term
        MyString temp = terms[min_idx];
        terms[min_idx] = terms[i];
        terms[i] = temp;
    }

    // Open output file to write
    fOut.open(ofilename);

    // Write the number of words and number of unique terms to output file
    fOut << "The file: " << ifilename << " contains " << wordCount << " Words." << endl;
    fOut << "There are " << termCount << " unique terms.\n" << endl;

    // Write each term to output file with the frequency.
    for (int k = 0; k < termCount; ++k) {
        fOut << terms[k] << endl;
    }


    return 0;
}
