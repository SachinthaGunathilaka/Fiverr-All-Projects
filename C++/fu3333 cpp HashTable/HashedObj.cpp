#include "HashedObj.h"


HashedObj::HashedObj(const string &key, const size_t &value) {
    this->key = key;
    this->value = value;
}

string HashedObj::getKey() {
    return key;
}

size_t HashedObj::getValue() {
    return value;
}

