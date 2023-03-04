#ifndef JSON_PROJECT_2_EPISODE_H
#define JSON_PROJECT_2_EPISODE_H

#include<iostream>
#include "string"

using namespace std;
class Episode {
private:
    string name;
    string content;
    string podcast;
    int number;

public:
    Episode(const string &podcast, int number, const string &name, const string &content);
    Episode(Episode & episode);
    void play();
    void print();
};


#endif
