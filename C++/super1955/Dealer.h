#include "Card.h"
#include <vector>

#ifndef Dealer_h
#define Dealer_h

class Dealer
{
  private:
    vector<Card> dealer1;
  public:
    void addCard(Card *newCard);
    void outputDealer();
    int getTotal();
};

#endif
