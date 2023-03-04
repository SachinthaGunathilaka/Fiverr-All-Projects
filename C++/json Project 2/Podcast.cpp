//
// Created by sachi on 10/7/2021.
//

#include "Podcast.h"

Podcast::Podcast(const string &title, const string &host) : title(title), host(host) {
    this->episodes = new Episode*[MAX_EPS];
    this->numEps = 0;
}

Podcast::Podcast(const Podcast &p1) {
    this->title = p1.title;
    this->host = p1.host;
    this->numEps = p1.numEps;
    this->episodes = new Episode*[MAX_EPS];
    for (int i = 0; i < numEps; ++i) {
        episodes[i] = new Episode(*p1.episodes[i]);
    }
}

const string &Podcast::getTitle() const {
    return title;
}

const string &Podcast::getHost() const {
    return host;
}

int Podcast::getNumEpisodes() const {
    return numEps;
}

bool Podcast::addEpisode(string ep_title, string content) {
    if(numEps == MAX_EPS)
        return false;

    Episode * episode = new Episode(title, numEps+1, ep_title, content);
    episodes[numEps] = episode;
    numEps++;

    return true;

}

bool Podcast::getEpisode(int index, Episode **ep) {
    // Index is taken from 0
    if(index < 0 || index >= numEps)
        return false;

    *ep = episodes[index];
    return true;
}

bool Podcast::lessThan(Podcast &pod) {
    if (this->title.compare(pod.title) < 0) {
        return true;
    }
    return false;
}

void Podcast::print() {
    cout << "\nPodcast => " << "Title : " << title << ", " << "Host : " << host << endl;
    cout << "Episodes => " << endl;
    if(numEps == 0){
        cout << "No episodes found\n" << endl;
        return;
    }

    for (int i = 0; i < numEps; ++i) {
        episodes[i]->print();
    }
    cout << endl;
}

Podcast::~Podcast() {
    for (int i = 0; i < numEps; ++i){
        delete episodes[i];
    }
    delete [] episodes;
}

