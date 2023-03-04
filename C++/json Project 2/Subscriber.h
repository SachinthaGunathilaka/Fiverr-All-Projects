#ifndef JSON_PROJECT_2_SUBSCRIBER_H
#define JSON_PROJECT_2_SUBSCRIBER_H
#include "string"
#include<iostream>

using namespace std;

class Subscriber {

private:
    string name;
    string creditcard;

public:
    Subscriber(const string name, const string creditcard);
    bool matches(const string &name);

    const string &getName() const;
    void print();


};


#endif
