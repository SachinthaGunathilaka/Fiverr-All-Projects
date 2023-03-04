#ifndef JSON_PROJECT_2_CLIENT_H
#define JSON_PROJECT_2_CLIENT_H

#include "defs.h"
#include "Client.h"
#include "Network.h"
#include "PodArray.h"

using namespace std;

class Client {
private:
    string name;
    PodArray * podArray;

public:
    Client(const string &name);

    virtual ~Client();

    bool download(Network * network, string podcast);
    bool stream(Network * network, string podcast, int episode);
    bool playLocal(string podcast, int episode);

};


#endif
