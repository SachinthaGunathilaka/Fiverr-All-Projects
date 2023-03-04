#include <iostream>
#include "Dealer.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


// Method to get option from user (Hit or Stand)
char getOption() {
    cout << "\n\t> (H)it or (S)tand ? ";
    char option;

    cin >> option;
    option = toupper(option);

    // If the user enter invalid input ask again
    while (option != 'H' && option != 'S') {
        cout << "\t  Invalid selection" << endl;
        cout << "\n\t> (H)it or (S)tand ? ";
        cin >> option;
        option = toupper(option);

    }

    return option;
}

int main() {

    // Initialize the Card deck
    const Card deck[52] = {Card("AC", 1), Card("AD", 1), Card("AS", 1), Card("AH", 1), Card("2C", 2), Card("2D", 2),
                           Card("2S", 2), Card("2H", 2), Card("3C", 3), Card("3D", 3), Card("3S", 3), Card("3H", 3),
                           Card("4C", 4), Card("4D", 4), Card("4S", 4), Card("4H", 4), Card("5C", 5), Card("5D", 5),
                           Card("5S", 5), Card("5H", 5), Card("6C", 6), Card("6D", 6), Card("6S", 6), Card("6H", 6),
                           Card("7C", 7), Card("7D", 7), Card("7S", 7), Card("7H", 7), Card("8C", 8), Card("8D", 8),
                           Card("8S", 8), Card("8H", 8), Card("9C", 9), Card("9D", 9), Card("9S", 9), Card("9H", 9),
                           Card("10C", 10), Card("10D", 10), Card("10S", 10), Card("10H", 10), Card("JC", 10),
                           Card("JD", 10), Card("JS", 10), Card("JH", 10), Card("QC", 10), Card("QD", 10),
                           Card("QS", 10), Card("QH", 10), Card("KC", 10), Card("KD", 10), Card("KS", 10),
                           Card("KH", 10)};
    srand(time(NULL));


    int min_players, max_players, player_count;

    // Get minimum number of players
    cout << "Enter the minimum number of players : ";
    cin >> min_players;

    // Get maximum number of players
    cout << "Enter the maximum number of players : ";
    cin >> max_players;

    // Randomly generate the number of players between given user inputs
    player_count = min_players + rand() % (max_players - min_players);


    // Define an array to hold the number of wins by each user
    int *players_wins = new int[player_count]{0};

    // Define an array to hold the bets by each user
    double bets[player_count];

    string play_again;

    // Loop until user wants to exit
    do {
        // Define an array to hold the total of each hand
        int *players_total = new int[player_count]{0};

        // Randomly select 2 cards for dealer
        Dealer Dealer1;
        int RandCard1 = rand() % 52;
        Card *c1 = new Card(deck[RandCard1]);
        int RandCard2 = rand() % 52;
        Card *c2 = new Card(deck[RandCard2]);

        // Add 2 cards to dealers hand
        Dealer1.addCard(c1);
        Dealer1.addCard(c2);

        // Run the game for each player
        for (int i = 0; i < player_count; ++i) {
            cout << "\nPlayer " << i + 1 << endl;

            // Get input from user for the bet
            cout << "\t> Enter your bet -> ";
            cin >> bets[i];

            char hit_stay;

            // Randomly select card from the deck
            int randCard = rand() % 52;
            Card *card = new Card(deck[randCard]);

            // For the card selected card to the player
            cout << "\t> Your first card is      -> " << card->getName() << endl;
            // Show the dealers first card
            cout << "\t> Dealer's first  card is -> " << c1->getName() << endl;
            players_total[i] += card->getValue();

            // Ask from the user whether he wants to stand or hit
            hit_stay = getOption();

            // This loop runs until the user wants to Stand
            while (hit_stay == 'H') {
                int randCard = rand() % 52;
                Card *card = new Card(deck[randCard]);

                cout << "\t> Dealing a card -> " << card->getName() << endl;
                players_total[i] += card->getValue();

                hit_stay = getOption();

            }
        }

        // Show the dealer's hand and total
        cout << "\n\nDealer's Hand" << endl;
        cout << "-------------------------" << endl;
        Dealer1.outputDealer();
        cout << "Dealer's hand total is " << Dealer1.getTotal() << endl;


        // Display whether the player win or loose
        for (int i = 0; i < player_count; ++i) {
            cout << "\nPlayer" << i + 1 << "\'s hand total is " << players_total[i] << endl;

            // If the player wins
            if (players_total[i] > Dealer1.getTotal()) {
                cout << "Player" << i + 1 << " won bet of " << bets[i] << endl;
                players_wins[i]++;
            }
                // If the player lost
            else if (players_total[i] < Dealer1.getTotal()) {
                cout << "Player" << i + 1 << " lost bet of " << bets[i] << endl;
            }
                // If the game drawn
            else {
                cout << "Player" << i + 1 << " does not win or loose" << endl;
            }
        }

        // Ask from the user whether he wants to play again
        cout << "\nDo you want to play again (Y)es / (N)o ? ";
        cin >> play_again;
    } while (play_again == "y" || play_again == "Y");


    // At the end show the number of wins by each user
    cout << endl;
    for (int i = 0; i < player_count; ++i) {
        cout << "Player" << i + 1 << " wins -> " << players_wins[i] << endl;
    }
} 