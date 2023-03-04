#include <iostream>
#include "Dealer.h"
#include "Card.h"
#include <vector>

using namespace std;

void Dealer::addCard(Card *newCard)
{
  dealer1.push_back(*newCard);
}

void Dealer::outputDealer()
{
  for (int i = 0; i < dealer1.size(); i++)
  {
    cout << "Card: " << dealer1[i].getName() << " , Value: " << dealer1[i].getValue() << endl;
  }
}

int Dealer::getTotal()
{
  int total = 0;
  for (int i = 0; i < dealer1.size(); i++)
  {
    total += dealer1[i].getValue();
  }
  return total;
}