/*It is possible that this code might contain a typo. It is
unlikely but make sure to check your code to ensure it works*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include "ArgumentManager.h"

using namespace std;
struct Node {
    string username;
    int id;
    char grade;
    int score;
    Node *next;
};


class linkedList {
private:
    Node *head;
public:
    int count;

    linkedList() {
        head = nullptr;
        count = 0;
    }

    void addNodeAtPos(string _username, int _id, char _grade, int _score, int pos) {
        Node *prev = new Node();
        Node *curr = new Node();
        Node *newNode = new Node();
        newNode->username = _username;
        newNode->id = _id;
        newNode->grade = _grade;
        newNode->score = _score;

        int tempPos = 0;

        curr = head;
        if (head != NULL) {
            while (curr->next != NULL && tempPos != pos) {
                prev = curr;
                curr = curr->next;
                tempPos++;
            }
            if (pos == 0) {
                addAtHead(_username, _id, _grade, _score);
            } else if (curr->next == NULL && pos == tempPos + 1) {
                addAtBack(_username, _id, _grade, _score);
            } else if (pos > tempPos + 1) {
                cout << " Position is out of bounds " << endl;

            } else {
                count++;
                prev->next = newNode;
                newNode->next = curr;
            }
        } else {
            if (pos != 0)
                return;
            head = newNode;
            newNode->next = NULL;
            count++;

        }
    }

    void addAtBack(string _username, int _id, char _grade, int _score) {
        count++;

        //1. allocate node
        Node *newNode = new Node();

        //2. assign data element
        newNode->username = _username;
        newNode->id = _id;
        newNode->grade = _grade;
        newNode->score = _score;

        //3. assign null to the next of new node
        newNode->next = NULL;

        //4. Check the Linked List is empty or not,
        //   if empty make the new node as head
        if (head == NULL) {
            head = newNode;
        } else {

            //5. Else, traverse to the last node
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            //6. Change the next of last node to new node
            temp->next = newNode;
        }
    }

    void addAtHead(string _username, int _id, char _grade, int _score) {
        count++;

        Node *new_node = new Node;
        new_node->username = _username;
        new_node->id = _id;
        new_node->grade = _grade;
        new_node->score = _score;
        new_node->next = head;
        head = new_node;
    }

    void print(ofstream &outputFile) {
        Node *current = head;
        while (current != nullptr) {

            outputFile << "[id:" << current->id << ";username:" << current->username << ";score:" << current->score
                       << ";grade:" << current->grade << "]";

            if (current->next != nullptr)
                outputFile << endl;
            current = current->next;
        }
    }

    bool searchAndUpdate(string _username, int _id, char _grade, int _score) {
        Node *current = head;
        while (current != nullptr) {
            if (current->id == _id) {
                current->username = _username;
                current->grade = _grade;
                current->score = _score;
                return true;
            }

            if (current->username == _username)
                return true;
            current = current->next;
        }

        return false;
    }

    void removeNode(int option, const string &str_value, int int_value, char char_value) {

        while (true) {
            Node *prev = head;
            Node *current = head->next;

            bool status = false;
            if (option == 1 && prev->username == str_value) {
                status = true;
            } else if (option == 2 && prev->id == int_value) {
                status = true;
            } else if (option == 3 && prev->grade == char_value) {
                status = true;
            } else if (option == 4 && prev->score == int_value) {
                status = true;
            }

            if (status) {
                head = head->next;
            } else {
                while (current != NULL) {

                    if (option == 1 && current->username == str_value) {
                        break;
                    } else if (option == 2 && current->id == int_value) {
                        break;
                    } else if (option == 3 && current->grade == char_value) {
                        break;
                    } else if (option == 4 && current->score == int_value) {
                        break;
                    } else {
                        prev = current;
                        current = current->next; // go to next value
                    }
                }
                if (current == NULL) {
                    break;
                } else {
                    prev->next = current->next; // unlink the node you remove
                    delete current; // delete the node
                }
            }


        }
    }


    void sort(int option) {
        int swapp, i;
        struct Node *ptr1;
        struct Node *lptr = NULL;

        /* Checking for empty list */
        if (head == NULL)
            return;

        do {
            swapp = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {

                if (option == 1 && ptr1->username > ptr1->next->username) {
                    swap(ptr1, ptr1->next);
                    swapp = 1;
                } else if (option == 2 && ptr1->id > ptr1->next->id) {
                    swap(ptr1, ptr1->next);
                    swapp = 1;
                } else if (option == 3 && ptr1->grade > ptr1->next->grade) {
                    swap(ptr1, ptr1->next);
                    swapp = 1;
                } else if (option == 4 && ptr1->score < ptr1->next->score) {
                    swap(ptr1, ptr1->next);
                    swapp = 1;
                }

                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapp);
    }

    void swap(Node *a, Node *b) {

        string temp_username = a->username;
        int temp_id = a->id;
        char temp_grade = a->grade;
        int temp_score = a->score;

        a->username = b->username;
        a->id = b->id;
        a->score = b->score;
        a->grade = b->grade;

        b->username = temp_username;
        b->id = temp_id;
        b->score = temp_score;
        b->grade = temp_grade;

    }
};

int main(int argc, char *argv[]) {

    ArgumentManager am(argc, argv);
    ifstream inputFile(am.get("input"));
    ifstream commandFile(am.get("command"));
    ofstream outputFile(am.get("output"));

//    ifstream inputFile("input9.txt");
//    ifstream commandFile("command9.txt");
//    ofstream outputFile("output9.txt");

    string inStr; //input string
    int idIndex, userIndex, scoreIndex, gradeIndex = 0;

    linkedList linkedList;

    while (getline(inputFile, inStr)) {

        //Lines 20 & 21: Removing '\n' and '\r' from inStr
        inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
        inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());

        //Getting the first index of each substring that is found from inStr
        idIndex = inStr.find("id:");
        userIndex = inStr.find("username:");
        scoreIndex = inStr.find("score:");
        gradeIndex = inStr.find("grade:");

        //If there is a missing attribute, continue
        if (idIndex == -1 || userIndex == -1 || scoreIndex == -1 || gradeIndex == -1) {
            continue;
        }

        //Check to see if attributes are in order by doing something like:
        if (idIndex > userIndex || userIndex > scoreIndex || scoreIndex > gradeIndex) {
            continue;
        }

        //Continue to parse inStr
        int id = stoi(inStr.substr(idIndex + 3, 4));
        string username = inStr.substr(userIndex + 9, inStr.find(';', userIndex) - userIndex - 9);
        int score = stoi(inStr.substr(scoreIndex + 6, inStr.find(';', scoreIndex) - scoreIndex - 6));
        char grade = inStr[gradeIndex + 6];

        //Input into linked list
        bool is_exists = linkedList.searchAndUpdate(username, id, grade, score);
        if (!is_exists)
            linkedList.addAtBack(username, id, grade, score);
    }

    //Read from commandFile
    while (getline(commandFile, inStr)) {

        //Lines 20 & 21: Removing '\n' and '\r' from inStr
        inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
        inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());

        if (inStr.substr(0, inStr.find(' ')) == "Add") {

            int position = stoi(inStr.substr(inStr.find('(') + 1, inStr.find(')') - inStr.find('(') - 1));

//            cout << position << " " << linkedList.count << endl;
            if (position > linkedList.count)
                continue;
            //Getting the first index of each substring that is found from inStr
            idIndex = inStr.find("id:");
            userIndex = inStr.find("username:");
            scoreIndex = inStr.find("score:");
            gradeIndex = inStr.find("grade:");

            //If there is a missing attribute, continue
            if (idIndex == -1 || userIndex == -1 || scoreIndex == -1 || gradeIndex == -1) {
                continue;
            }

            //Check to see if attributes are in order by doing something like:
            if (idIndex > userIndex || userIndex > scoreIndex || scoreIndex > gradeIndex) {
                continue;
            }

            //Continue to parse inStr
            int id = stoi(inStr.substr(idIndex + 3, 4));
            string username = inStr.substr(userIndex + 9, inStr.find(';', userIndex) - userIndex - 9);
            int score = stoi(inStr.substr(scoreIndex + 6, inStr.find(';', scoreIndex) - scoreIndex - 6));
            char grade = inStr[gradeIndex + 6];

            //Input into linked list

            bool is_exists = linkedList.searchAndUpdate(username, id, grade, score);
            if (!is_exists)
                linkedList.addNodeAtPos(username, id, grade, score, position);
        }

        if (inStr.substr(0, inStr.find(' ')) == "Remove") {
            idIndex = inStr.find("id:");
            userIndex = inStr.find("username:");
            scoreIndex = inStr.find("score:");
            gradeIndex = inStr.find("grade:");


            if (userIndex != -1) {

                string username = inStr.substr(userIndex + 9, inStr.find(')', userIndex) - userIndex - 9);

                linkedList.removeNode(1, username, 0, ' ');

            } else if (idIndex != -1) {
                cout << "r" << endl;
                int id = stoi(inStr.substr(idIndex + 3, 4));
                cout << id << endl;

                linkedList.removeNode(2, "", id, ' ');
            } else if (gradeIndex != -1) {
                char grade = inStr[gradeIndex + 6];
                linkedList.removeNode(3, "", 0, grade);
            } else if (scoreIndex != -1) {

                int score = stoi(inStr.substr(scoreIndex + 6, inStr.find(')', scoreIndex) - scoreIndex - 6));
                linkedList.removeNode(4, "", score, ' ');
            }


        }

        if (inStr.substr(0, inStr.find(' ')) == "Sort") {

            string condition = inStr.substr(inStr.find('(') + 1, inStr.find(')') - inStr.find('(') - 1);

            if (condition == "username") {
                linkedList.sort(1);
            } else if (condition == "id") {
                linkedList.sort(2);
            } else if (condition == "grade") {
                linkedList.sort(3);
            } else if (condition == "score") {
                linkedList.sort(4);
            }

        }
    }

    linkedList.print(outputFile);

    //Perform commands on linked list
    //Output to outputFile

    return 0;
}