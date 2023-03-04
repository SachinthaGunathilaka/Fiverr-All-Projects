#include "two_or_less.h"

TwoOrLess::TwoOrLess() {
    number_of_items = 0;
}

std::pair<int*, bool> TwoOrLess::insert(int data) {

    int * temp;
    *temp = data;
    auto it = set.find(data);
    std::pair<int*, bool> result;
    result.second = false;
    result.first = temp;

    if (it != set.end()) {
        if (it->second < 2) {
            it->second = it->second + 1;
            number_of_items++;
            result.second = true;

        }

    } else {
        set.insert(std::pair<int, int>(data, 1));
        number_of_items++;

        result.second = true;

    }

    return result;

}

int TwoOrLess::size() {
    return number_of_items;
}

int TwoOrLess::count(int item) {
    if (set.find(item) == set.end())
        return 0;

    return set.at(item);
}
