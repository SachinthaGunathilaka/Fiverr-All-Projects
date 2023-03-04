#include<iostream>
#include<set>
#include<map>

using namespace std;


set<string> only_once(map<string, int> word_counts) {
    set<string> result;

    for (const auto &kv: word_counts) {

        if (kv.second == 1)
            result.insert(kv.first);

    }

    return result;
}


bool cmp(pair<string, int> &a,
         pair<string, int> &b) {
    return a.second < b.second;
}


multimap<int, string> count_to_words(map<string, int> word_counts) {


    multimap<int, string> result;
    for (const auto &kv: word_counts) {
        result.insert({kv.second, kv.first});
    }


    return result;

}


map<int, set<string>> count_to_set(map<string, int> word_counts) {
    map<int, set<string>> result;

    for (const auto &kv: word_counts) {

        auto it = result.find(kv.second);

        if (it != result.end()) {

            it->second.insert(kv.first);
//            result.insert({kv.second, temp});


        } else {
            set<string> temp;
            temp.insert(kv.first);
            result.insert({kv.second, temp});

        }

    }

    return result;

}

int main() {
    const map<string, int> word_counts1 = {
            {"josh",     2},
            {"smart",    1},
            {"cse",      8},
            {"ferret",   1},
            {"politics", 0},
            {"C++",      1},
    };

    set<string> result1 = only_once(word_counts1);

    for (string data: result1) {
        cout << data << " ";
    }

    cout << endl;


    const map<string, int> word_counts2 = {
            {"josh",     2},
            {"smart",    1},
            {"cse",      8},
            {"ferret",   1},
            {"politics", 0},
            {"C++",      1},
    };

  
    multimap<int, string> result2 = count_to_words(word_counts2);

    for (const auto &kv: result2) {
        cout << kv.first << " " << kv.second << endl;
    }


    const map<string, int> word_counts3 = {
            {"josh",     2},
            {"smart",    1},
            {"cse",      8},
            {"ferret",   1},
            {"politics", 0},
            {"C++",      1},
    };


    map<int, set<string>> result3 = count_to_set(word_counts3);

    for (const auto &kv: result3) {
        cout << kv.first << " ";
        for (const auto &kv2: kv.second) {
            cout << kv2 << " ";
        }
        cout << endl;

    }
    return 0;
}