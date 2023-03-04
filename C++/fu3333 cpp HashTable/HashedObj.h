#include<iostream>
#include<string>

using namespace std;
class HashedObj {
private:
    string key;
    size_t value;

public:
    HashedObj(const std::string & key, const size_t & value);
    string getKey();
    size_t getValue();
};
