#include "Episode.h"
Episode::Episode(const string &podcast, int number, const string &name, const string &content) : name(name),
                                                                                                 content(content),
                                                                                                 podcast(podcast),
                                                                                                 number(number) {}

void Episode::play() {
    cout << podcast << ", " << name << ", " << number << ", " << content << endl;
}

Episode::Episode(Episode &episode) {
    this->name = name;
    this->content = content;
    this->podcast = podcast;
    this->number = number;
}

void Episode::print() {
    cout << "Episode => " << "Name : " << name << ", " << "Ep Number : " << number << endl;
}
