#ifndef YOPRABHU_2_TWO_OR_LESS_H
#define YOPRABHU_2_TWO_OR_LESS_H

#include <map>

class TwoOrLess {
private:
    std::map<int, int> set;
    int number_of_items;

public:
    TwoOrLess();

    std::pair<int*, bool> insert(int data);

    int size();

    int count(int item);

};

#endif
