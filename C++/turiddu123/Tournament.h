#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Gamer.h"
#include "Match.h"


class Tournament {
private:
    Gamer ** gamers;
    Match ** matches;
    int num_of_gamers;
    int num_of_matches;
public:
    Tournament();

    void addGamer(const string &, const string &, int, int, int);
    void addMatch(const string &, const string &, const string &, const string &, int rounds, int p1_points,int  p2_points, int duration);

    void displayGamers();
    void displayMatches();
    void printLeaderboard();
    void searchPlayer(string);
    void displayLongestMatches(int);
    void deleteLastPlayers(int);
    void deleteLowestRoundMatches();



};


#endif
