#include "Tournament.h"

Tournament::Tournament() {
    gamers = new Gamer *[150];
    matches = new Match *[500];
    num_of_gamers = 0;
    num_of_matches = 0;
}


void Tournament::addGamer(const string &surname, const string &name, int matches, int won, int lost) {
    auto *gamer = new Gamer(surname, name, matches, won, lost);
    gamers[num_of_gamers++] = gamer;
}


void Tournament::displayGamers() {
    for (int i = 0; i < num_of_gamers; ++i) {
        cout << *gamers[i];
    }
}

void
Tournament::addMatch(const string &p1_surname, const string &p1_name, const string &p2_surname, const string &p2_name,
                     int rounds, int p1_points, int p2_points, int duration) {
    auto *match = new Match(p1_surname, p1_name, p2_surname, p2_name, rounds, p1_points, p2_points, duration);
    matches[num_of_matches++] = match;

}

void Tournament::displayMatches() {
    for (int i = 0; i < num_of_matches; ++i) {
        cout << *matches[i];
    }

}

void Tournament::printLeaderboard() {

    cout << left << setw(15) << "\nSurname" << setw(15) << "Name" << setw(10) << "Matches" << setw(7)
         << "Won" << setw(7) << "Lost" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < num_of_gamers - 1; ++i) {
        for (int j = 0; j < num_of_gamers - 1 - i; ++j) {
            if (gamers[j]->getWon() < gamers[j + 1]->getWon()) {
                Gamer *temp = gamers[j];
                gamers[j] = gamers[j + 1];
                gamers[j + 1] = temp;
            }
        }

    }
    displayGamers();
}

void Tournament::searchPlayer(string surname) {
    cout << left << setw(15) << "\nP1 Surname" << setw(15) << "P1 Name" << setw(15) << "P2 Surname"
         << setw(15) << "P2 Name" << setw(10) << "Rounds" << setw(15) << "P1 Points"
         << setw(15) << "P2 Points" << setw(10) << "Duration" << endl;

    cout
            << "--------------------------------------------------------------------------------------------------------------"
            << endl;

    for (int i = 0; i < num_of_matches; ++i) {
        if (matches[i]->getP1Surname() == surname || matches[i]->getP2Surname() == surname) {
            cout << *matches[i];
        }
    }
}

void Tournament::displayLongestMatches(int K) {
    for (int i = 0; i < num_of_matches - 1; ++i) {
        for (int j = 0; j < num_of_matches - 1 - i; ++j) {
            if (matches[j]->getDuration() < matches[j + 1]->getDuration()) {
                auto *temp = matches[j];
                matches[j] = matches[j + 1];
                matches[j + 1] = temp;
            }
        }
    }

    cout << left << setw(15) << "\nP1 Surname" << setw(15) << "P1 Name" << setw(15) << "P2 Surname"
         << setw(15) << "P2 Name" << setw(10) << "Rounds" << setw(15) << "P1 Points"
         << setw(15) << "P2 Points" << setw(10) << "Duration" << endl;

    cout
            << "--------------------------------------------------------------------------------------------------------------"
            << endl;

    for (int i = 0; (i < K and i < num_of_matches); ++i) {
        cout << *matches[i];
    }
}

void Tournament::deleteLastPlayers(int M) {

    for (int i = 0; i < num_of_gamers - 1; ++i) {
        for (int j = 0; j < num_of_gamers - 1 - i; ++j) {
            if (gamers[j]->getWon() < gamers[j + 1]->getWon()) {
                auto *temp = gamers[j];
                gamers[j] = gamers[j + 1];
                gamers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        gamers[num_of_gamers-i-1] = nullptr;
    }

    num_of_gamers -= M;

    cout << "Delete " << M << " number of gamers with least points successfully" << endl;
}

void Tournament::deleteLowestRoundMatches() {

    for (int i = 0; i < num_of_matches - 1; ++i) {
        for (int j = 0; j < num_of_matches - 1 - i; ++j) {
            if (matches[j]->getRounds() < matches[j + 1]->getRounds()) {
                auto *temp = matches[j];
                matches[j] = matches[j + 1];
                matches[j + 1] = temp;
            }
        }
    }

    int lowest_rounds = matches[num_of_matches-1]->getRounds();

    int i = 0;
    while (true){
        if(matches[num_of_matches - i-1]->getRounds() == lowest_rounds){
            matches[num_of_matches - i-1] = nullptr;
            i++;
        }
        else
            break;
    }

    num_of_matches -= i;

    cout << "Delete " << i << " number of matches with " << lowest_rounds << " rounds successfully" << endl;

}

