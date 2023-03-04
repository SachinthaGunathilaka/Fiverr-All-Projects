#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(string name_, int value_)
{
  name = name_;
  value = value_;
}

int Card::getValue() const
{
  return value;
}

string Card::getName() const
{
  return name;
}
