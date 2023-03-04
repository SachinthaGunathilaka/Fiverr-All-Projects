#include <iostream>
#include <fstream>
#include <string>
#include "Tournament.h"
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "\n1) Print leaderboard of the tournament\n"
            "2) Display every match played by the player\n"
            "3) Display the longest matches\n"
            "4) Delete the players with least points\n"
            "5) Delete the matches with the lowest number of rounds\n"
            "6) Exit" << endl;
}

int getOption() {
    displayMenu();
    int option;
    cout << "\nSelect option : ";
    cin >> option;
    while (option < 1 || option > 6) {
        cout << "Invalid option" << endl;
        cout << "\nSelect option again: ";
        cin >> option;
    }
    return option;
}

int main() {
    Tournament tournament;
    ifstream gamers_file("Gamers.txt");
    ifstream matches_file("Matches.txt");
    string line;

    string game_data[5];
    while (getline(gamers_file, line)) {
        int i = 0;
        stringstream ss(line);
        while (ss.good()) {
            getline(ss, game_data[i++], ';');
        }
        tournament.addGamer(game_data[0], game_data[1], stoi(game_data[2]), stoi(game_data[3]), stoi(game_data[4]));
    }
    gamers_file.close();

    string match_data[8];
    while (getline(matches_file, line)) {
        int i = 0;
        stringstream ss(line);
        while (ss.good()) {
            getline(ss, match_data[i++], ';');
        }
        tournament.addMatch(match_data[0], match_data[1], match_data[2], match_data[3], stoi(match_data[4]),
                            stoi(match_data[5]), stoi(match_data[6]), stoi(match_data[7]));
    }
    matches_file.close();


    while (true) {
        int option = getOption();

        if (option == 1) {
            tournament.printLeaderboard();
        } else if (option == 2) {
            string surname;
            cout << "Enter surname : ";
            cin >> surname;

            tournament.searchPlayer(surname);
        } else if (option == 3) {
            int K;
            cout << "Enter number of matches : ";
            cin >> K;

            tournament.displayLongestMatches(K);
        } else if (option == 4) {
            int M;
            cout << "Enter number of players : ";
            cin >> M;

            tournament.deleteLastPlayers(M);
        } else if (option == 5) {
            tournament.deleteLowestRoundMatches();
        } else {
            break;
        }
    }
}
