
#include "PodArray.h"

PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;

}


PodArray::~PodArray(){
	for (int i = 0; i < numPods; ++i){
		delete podcasts[i];
	}
	delete [] podcasts;
}

bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

bool PodArray::removePodcast(const string& title, Podcast** pod){
    int i;
    for (i = 0; i < size(); ++i) {
        if(podcasts[i]->getTitle() == title)
            break;
    }

    if(i == size())
        return false;

    *pod = podcasts[i];

    for (int j = i+1; j < size(); ++j) {
        podcasts[j-1] = podcasts[j];
    }
    numPods--;

    delete podcasts[size()];
    return true;

}

bool PodArray::getPodcast(const string& title, Podcast** pod){
    int i;
    for (i = 0; i < size(); ++i) {
        if(podcasts[i]->getTitle() == title){
            break;

        }
    }

    if(i == size())
        return false;


    *pod = podcasts[i];
    return true;

}

bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

int PodArray::size(){
	return numPods;
}

void PodArray::print(){
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
