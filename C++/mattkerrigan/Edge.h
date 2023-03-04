#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Edge class
class Edge {

private:
    // Attributes
    string start; // start vertex
    string end; // destination vertex
    double weight; // weight of the edge

public:
    // Constructors
    Edge() {
    }

    Edge(string s, string e, double w) {
        start = s;
        end = e;
        weight = w;
    }

    // Getter methods
    const string &getStart() const {
        return start;
    }

    const string &getEnd() const {
        return end;
    }

    double getWeight() const {
        return weight;
    }

    // method to output an Edge
    friend ostream &operator<<(ostream &out, const Edge &e) {
        out << e.start << "-" << e.end << ": " << e.weight << endl;
        return out;
    }
};