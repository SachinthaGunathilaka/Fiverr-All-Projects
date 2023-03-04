#include "Network.h"

Network::Network(string name) {
    this->name = name;
    numSubs = 0;
    podArray = new PodArray();
}

Network::~Network() {
}

bool Network::addPodcast(string podcast, string host) {
    Podcast * podcast1 = new Podcast(podcast, host);
    if (podArray->addPodcast(podcast1))
        return true;
    return false;
}

bool Network::removePodcast(string podcast) {
    Podcast **podcast1;
    if (podArray->removePodcast(podcast, podcast1))
        return true;
    return false;
}

bool Network::addEpisode(string podcast, string title, string content) {
    Podcast * temp_podcast;


    for (int i = 0; i < podArray->size(); ++i) {
        if (podArray->getPodcast(podcast, &temp_podcast)) {
            temp_podcast->addEpisode(title, content);
//            temp_podcast->print();

            return true;
        }

    }
    return false;
}

bool Network::addSubscriber(string name, string creditcard) {
    if (numSubs == MAX_SUBS)
        return false;

    Subscriber * subscriber = new Subscriber(name, creditcard);
    subscribers[numSubs] = subscriber;
    numSubs++;

    return true;
}


bool Network::download(string subscriber, string podcast_title, Podcast **podcast) {
    if (!hasSubscriber(subscriber)) {
        cout << "No such subscriber" << endl;
        return false;
    }

    Podcast *tempPodcast;
    bool isPodcastExist = false;
    for (int i = 0; i < podArray->size(); ++i) {
        if (podArray->getPodcast(podcast_title, &tempPodcast))
            isPodcastExist = true;

    }

    if (!isPodcastExist) {
        cout << "No such podcast" << endl;
        return false;
    }

    *podcast = tempPodcast;
    return true;
}

bool Network::stream(string subscriber, string podcast_title, int episode, Episode **episode1) {
    if (!hasSubscriber(subscriber)) {
        cout << "No such subscriber" << endl;
        return false;
    }

    Podcast *tempPodcast;
    bool isPodcastExist = false;
    for (int i = 0; i < podArray->size(); ++i) {
        if (podArray->getPodcast(podcast_title, &tempPodcast))
            isPodcastExist = true;

    }

    if (!isPodcastExist) {
        cout << "No such podcast" << endl;
        return false;
    }

    if (tempPodcast->getEpisode(episode, episode1)) {
        return true;
    }

    cout << "No such episode" << endl;
    return false;
}

bool Network::hasSubscriber(string subscriber) {
    for (int i = 0; i < numSubs; ++i) {
        if (subscriber == subscribers[i]->getName())
            return true;
    }

    return false;
}

void Network::print() {
    cout << "\nNetwork Name : " << name << endl;
    cout << "Subscribers => " << endl;
    if (numSubs == 0)
        cout << "No Subscribers found" << endl;

    else {
        for (int i = 0; i < numSubs; ++i) {
            subscribers[i]->print();
        }
    }


    cout << "Podcasts => " << endl;
    if(podArray->size() == 0)
        cout << "No podcasts found" << endl;

    else{
        podArray->print();
    }
    cout << endl;

}

bool Network::getPodcast(string podcast_title, Podcast **pPodcast) {

    if (podArray->getPodcast(podcast_title, pPodcast)) {
        return true;
    }
    cout << "Podcast not found" << endl;
    return false;

}
