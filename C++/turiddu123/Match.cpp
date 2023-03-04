#include "Match.h"

Match::Match(const string &p1Surname, const string &p1Name, const string &p2Surname, const string &p2Name, int rounds,
             int p1Points, int p2Points, int duration) : p1_surname(p1Surname), p1_name(p1Name), p2_surname(p2Surname),
                                                         p2_name(p2Name), rounds(rounds), p1_points(p1Points),
                                                         p2_points(p2Points), duration(duration) {}

const string &Match::getP1Surname() const {
    return p1_surname;
}

const string &Match::getP1Name() const {
    return p1_name;
}

const string &Match::getP2Surname() const {
    return p2_surname;
}

const string &Match::getP2Name() const {
    return p2_name;
}

int Match::getRounds() const {
    return rounds;
}

int Match::getP1Points() const {
    return p1_points;
}

int Match::getP2Points() const {
    return p2_points;
}

int Match::getDuration() const {
    return duration;
}

ostream &operator<<(ostream &os, const Match &match) {
    os << left << setw(15) << match.p1_surname << setw(15) << match.p1_name << setw(15) << match.p2_surname
       << setw(15) << match.p2_name << setw(10) << match.rounds << setw(15) << match.p1_points
       << setw(15) << match.p2_points << setw(10)  << match.duration << endl;
    return os;
}
