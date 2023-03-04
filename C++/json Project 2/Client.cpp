#include "Client.h"


Client::Client(const string &name) : name(name) {
    podArray = new PodArray();
}

Client::~Client() {
    delete podArray;

}

bool Client::download(Network *network, string podcast) {
    Podcast **temp_podcast;
    if (network->download(name, podcast, temp_podcast)) {
        podArray->addPodcast(*temp_podcast);
        return true;
    }

    return false;
}

bool Client::stream(Network *network, string podcast, int episode) {
    Episode *temp_episode;
    if (network->stream(name, podcast, episode, &temp_episode)) {
        temp_episode->play();
        return true;
    }

    return false;
}

bool Client::playLocal(string podcast, int episode) {
    Podcast *temp_podcast;
    for (int i = 0; i < podArray->size(); ++i) {
        if(podArray->getPodcast(podcast, &temp_podcast)){
            Episode *temp_episode;
            if(temp_podcast->getEpisode(episode,&temp_episode)){
                temp_episode->play();
                return true;
            }
            else{
                cout << "no such episode" << endl;

            }

        }
        else{
            cout << "no such podcast" << endl;
        }
    }
    return false;
}
