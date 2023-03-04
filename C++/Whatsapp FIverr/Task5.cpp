/* pallindrome: checks a string to see if it is a pallindrome.
*
*  Examples:
*
*  Able was I 'ere I saw Elba.
*  Madam, I'm Adam.
*  A man, a plan, a canal, Panama.
*  Racecar

*  First, create a clean version of the string.
*  	- convert all characters to lower case.
*  	- remove all punctuation.
*
*  Second, create a reverse version of the string.
*   - use reverse and swap from our lab assignment
        *   so first make a copy of the string and pass in
        *   the copy to reverse.
*
*  Third
*  	- compare the two strings
*  		if they are the same, palindrome.
*  		else, not palindrome.
*/
#include <iostream>
#include <vector>
// ToDo: Add include files.
using namespace std;

string removePunct(string str);
// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton removed.

string convertToLower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

    // ToDo: Declare two vectors of strings to save the input strings: palindromes, not_palindromes.
    vector<string> palindromes, not_palindromes;

    // ToDo: Implement a loop to read in the palindrome strings using getline until
    // the user quits. The user will enter the sentence "quit" to exit the loop.
    // ToDo: In the loop, call the isPalindrome function on the input string and
    // store it in the palindromes vector if true and the notPalindromes vector if
    // false.

    string sentence;
    while (1){
        cout << "Enter your palindrome or type quit: " << endl;
        getline(cin, sentence);

        sentence = convertToLower(sentence);
        sentence = removePunct(sentence);


        if(sentence == "quit")
            break;
        if(isPalindrome(sentence))
            palindromes.push_back(sentence);
        else
            not_palindromes.push_back(sentence);


    }


    // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
    // heading and the list that are not palindromes under a Not Palindrome heading.
    // The display function should print a tab character before printing the string.
    cout << "Palindromes:" << endl;
    display(palindromes);

    cout << "NOT Palindromes:" << endl;
    display(not_palindromes);


    return 0;
}

string removePunct(string str) {
    string result = "";
    for (int i = 0; i < str.size(); ++i) {
        if(isalpha(str[i])){
           result += str[i];
        }
    }

    return result;
}

string convertToLower(string str){
    string result = "";
    for (int i = 0; i < str.size(); ++i) {
        result += tolower(str[i]);
    }

    return result;
}

string reverse(string str){
    string result = "";
    for (int i = str.size()-1; i >= 0 ; --i) {
        result += str[i];
    }

    return result;
}

void display(vector<string> vstrings){
    for (string sentence:vstrings){
        cout << "\t" << sentence << endl;
    }
}

bool isPalindrome(string str){
    return reverse(str) == str;
}

