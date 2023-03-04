#ifndef Card_h
#define Card_h

using namespace std;

class Card
{
  private:
    string name;
    int value;
  public:
    Card(string name_, int value_);
    int getValue() const;
    string getName() const;
};

#endif
