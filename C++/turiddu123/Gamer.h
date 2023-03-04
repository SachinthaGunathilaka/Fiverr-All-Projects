#ifndef GAMER_H
#define GAMER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Gamer {
private:
    string surname;
    string name;
    int matches;
    int won;
    int lost;

public:
    Gamer(const string &surname, const string &name, int matches, int won, int lost);

    const string &getSurname() const;

    const string &getName() const;

    int getMatches() const;

    int getWon() const;

    int getLost() const;

    friend ostream &operator<<(ostream &os, const Gamer &gamer);
};


#endif
