#ifndef JSON_PROJECT_2_PODCAST_H
#define JSON_PROJECT_2_PODCAST_H
#include "string"
#include "Episode.h"
#include "defs.h"

using namespace std;

class Podcast {
private:
    string title;
    string host;
    Episode ** episodes;
    int numEps;

public:
    Podcast(const string &title, const string &host);
    Podcast(const Podcast &p1);
    ~Podcast();
    const string &getTitle() const;

    const string &getHost() const;

    int getNumEpisodes() const;

    bool addEpisode(string title, string content);

    bool getEpisode(int index, Episode** ep);

    bool lessThan(Podcast &pod);

    void print();

};


#endif
