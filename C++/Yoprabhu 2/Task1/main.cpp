#include <iostream>
#include "two_or_less.h"
#include<set>
#include <cassert>
#include <stdio.h>

using namespace std;

void ASSERT_EQ(int data1, int data2) {
    if (data1 == data2) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Failed Actual : " << data1 << " Expected : " << data2 << std::endl;

    }

}

int main() {

    // TwoOrLess thing1;

    // ASSERT_EQ(thing1.size(), 0);
    // ASSERT_EQ(thing1.count(0), 0);

    // thing1.insert(0);
    // ASSERT_EQ(thing1.size(), 1);
    // ASSERT_EQ(thing1.count(0), 1);

    // thing1.insert(1);
    // ASSERT_EQ(thing1.size(), 2);
    // ASSERT_EQ(thing1.count(1), 1);
    // ASSERT_EQ(thing1.count(0), 1);

    // thing1.insert(0);
    // ASSERT_EQ(thing1.size(), 3);
    // ASSERT_EQ(thing1.count(0), 2);

    // thing1.insert(0);
    // ASSERT_EQ(thing1.size(), 3);
    // ASSERT_EQ(thing1.count(0), 2);

    // thing1.insert(4);
    // ASSERT_EQ(thing1.size(), 4);
    // ASSERT_EQ(thing1.count(4), 1);
    // ASSERT_EQ(thing1.count(0), 2);

    // thing1.insert(4);
    // thing1.insert(4);
    // thing1.insert(4);
    // thing1.insert(4);
    // ASSERT_EQ(thing1.size(), 5);
    // ASSERT_EQ(thing1.count(4), 2);
    // ASSERT_EQ(thing1.count(1), 1);
    // ASSERT_EQ(thing1.count(0), 2);


    TwoOrLess thing2;
    auto p = thing2.insert(4);
    // cout << "a " << *p.first << endl;
    ASSERT_EQ(p.second, true);
    ASSERT_EQ(*p.first, 4);

    auto p2 = thing2.insert(4);
    ASSERT_EQ(p2.second, true);
    ASSERT_EQ(*p2.first, 4);

    auto p3 = thing2.insert(4);
    ASSERT_EQ(p3.second, false);

    auto p4 = thing2.insert(10);
    ASSERT_EQ(p4.second, true);
    ASSERT_EQ(*p4.first, 10);

    return 0;
}
