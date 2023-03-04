#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class Match {
private:
    string p1_surname;
    string p1_name;
    string p2_surname;
    string p2_name;
    int rounds;
    int p1_points;
    int p2_points;
    int duration;

public:
    Match(const string &p1Surname, const string &p1Name, const string &p2Surname, const string &p2Name, int rounds,
          int p1Points, int p2Points, int duration);

    const string &getP1Surname() const;

    const string &getP1Name() const;

    const string &getP2Surname() const;

    const string &getP2Name() const;

    int getRounds() const;

    int getP1Points() const;

    int getP2Points() const;

    int getDuration() const;

    friend ostream &operator<<(ostream &os, const Match &match);


};


#endif
