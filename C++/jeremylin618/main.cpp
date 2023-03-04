#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"

//#include "ArgumentManager.h"
using namespace std;

int main(int argc, char *argv[]) {
    // *** You need to open files using argumentmanager when submit your assignment ***
   ArgumentManager am(argc, argv);
   ifstream input(am.get("input"));
   ifstream command(am.get("command"));
   ofstream out(am.get("output"));

    // *** Use this if you need to test each input individually, but you need to change back to using argumentmanager when you submit the assignment ***
    // ifstream input("input2.txt");
    // ifstream command("command1.txt");
    // ofstream out("output.txt");


    vector<string> strings;
    string in;
    while (getline(input, in)) {

        // Clean up blank spaces, \n and \r, and skip blank lines
        in.erase(remove(in.begin(), in.end(), '\n'), in.end());
        in.erase(remove(in.begin(), in.end(), '\r'), in.end());
        in.erase(remove(in.begin(), in.end(), ' '), in.end());
        if (in.empty())
            continue;
        strings.push_back(in);


    }

    string cmd;
    vector<string> first_list;
    vector<string> last_list;
    while (getline(command, cmd)) {
        // Clean up blank spaces, \n and \r, and skip blank lines
        cmd.erase(remove(cmd.begin(), cmd.end(), '\n'), cmd.end());
        cmd.erase(remove(cmd.begin(), cmd.end(), '\r'), cmd.end());
        cmd.erase(remove(cmd.begin(), cmd.end(), ' '), cmd.end());
        if (cmd.size() == 0)
            continue;


        int break_pos = cmd.find(':');
        if (break_pos == -1)
            continue;
        if (cmd.substr(0, break_pos) == "first4") {
            first_list.push_back(cmd.substr(break_pos + 1));
        } else if (cmd.substr(0, break_pos) == "last4") {
            last_list.push_back(cmd.substr(break_pos + 1));
        }
    }

    for (const string& line: strings) {
        vector<pair<char, string>> characters;
        vector<string> ids;
        string delimiter = "id:";

        int position = line.find(delimiter);

        if (position == -1)
            continue;
        string char_set = line.substr(0, position);
        string id = line.substr(position + 3);
        ids.push_back(id);


        string current_char_set = char_set;
        while (true) {
            if (!isalpha(current_char_set[0]))
                break;

            char character = current_char_set[0];
            current_char_set = current_char_set.substr(2);

            int start_pos = current_char_set.find(';');

            string num_representation;

            if (start_pos == -1) {
                break;
            }

            num_representation = current_char_set.substr(0, start_pos);
            current_char_set = current_char_set.substr(start_pos + 1);
            characters.push_back(make_pair(character, num_representation));

        }




        string char_replaced_str;
        for (int i = 0; i < id.size(); i++) {
            if (isalpha(id[i])) {
                for (int j = 0; j < characters.size(); j++) {
                    if (characters[j].first == id[i]) {
                        char_replaced_str += characters[j].second;
                        break;
                    }

                }

            } else {
                char_replaced_str += id[i];
            }
        }


        string final_string;

        for (int i = 0; i < char_replaced_str.size(); i++) {
            if (char_replaced_str[i] == '#') {
                final_string += to_string(i);

            } else {
                final_string += char_replaced_str[i];
            }
        }
        bool isvalid = true;

        if (first_list.empty() && last_list.empty()) {
            isvalid = true;
        } else {
            if (!first_list.empty()) {
                bool is_match = false;
                for (const string &element: first_list) {
                    if (final_string.substr(0, element.size()) == element) {
                        is_match = true;
                        break;
                    }
                }
                if (!is_match)
                    isvalid = false;
            }

            if (!last_list.empty()) {
                bool is_match = false;
                for (const string &element: last_list) {
                    if (final_string.substr(final_string.size() - element.size()) == element) {
                        is_match = true;
                        break;
                    }
                }

                if (!is_match)
                    isvalid = false;
            }
        }

        if (isvalid)
            out << final_string << endl;
    }
}
