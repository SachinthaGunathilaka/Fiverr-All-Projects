#include "Gamer.h"

Gamer::Gamer(const string &surname, const string &name, int matches, int won, int lost) : surname(surname), name(name),
                                                                                          matches(matches), won(won),
                                                                                          lost(lost) {}

const string &Gamer::getSurname() const {
    return surname;
}

const string &Gamer::getName() const {
    return name;
}

int Gamer::getMatches() const {
    return matches;
}

int Gamer::getWon() const {
    return won;
}

int Gamer::getLost() const {
    return lost;
}


ostream &operator<<(ostream &os, const Gamer &gamer) {
    os << left << setw(15) << gamer.surname << setw(15) << gamer.name << setw(10) << gamer.matches << setw(7)
       << gamer.won << setw(7) << gamer.lost << setw(10) << endl;
    return os;
}

