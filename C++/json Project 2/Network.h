#ifndef JSON_PROJECT_2_NETWORK_H
#define JSON_PROJECT_2_NETWORK_H
#include<iostream>
#include "string"
#include "PodArray.h"
#include "Subscriber.h"
#include "defs.h"

using namespace std;

class Network {
private:
    string name;
    PodArray * podArray;
    Subscriber * subscribers[MAX_SUBS];
    int numSubs;


public:
    Network(string name);
    ~Network();
    bool addPodcast(string podcast, string host);
    bool removePodcast(string podcast);
    bool addEpisode(string podcast, string title, string content);
    bool addSubscriber(string name, string creditcard);
    bool download(string subscriber, string podcast, Podcast **podcast1);
    bool stream(string subscriber, string podcast, int episode, Episode **episode1);
    bool hasSubscriber(string name);
    bool getPodcast(string podcast_title, Podcast** pPodcast);

    void print();
};


#endif
