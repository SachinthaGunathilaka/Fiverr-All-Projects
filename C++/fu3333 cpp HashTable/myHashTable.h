#include<list>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <functional>


using namespace std;

template<typename HashedObj>
class myHashTable {
public:
    explicit myHashTable(int size = 101) {
        for (int i = 0; i < 10; ++i) {
            auto *temp = new list<HashedObj>;
            theLists.push_back(*temp);
        }
        currentSize = 0;
        capacity = size;
    }

    void printTable() {
        for (int i = 0; i < 10; ++i) {
            for (typename std::list<HashedObj>::iterator it = theLists.at(i).begin();
                 it != theLists.at(i).end(); ++it) {
                std::cout << it->getKey() << ":" << it->getValue() << "  ";
            }
            cout << endl;
        }
    }

    size_t strToHashValue(const std::string &str) const {
        size_t hashVal = 0;
        for (char ch: str)
            hashVal = 3 * hashVal + ch;
        return hashVal%10;
    }

    int universalHash(int x, int A, int B, int M) {
        int DIGS = 31;
        int mersennep = (1 << DIGS) - 1;

        long long hashVal = static_cast<long long>( A ) * x + B;
        hashVal = ((hashVal >> DIGS) + (hashVal & mersennep));
        if (hashVal >= mersennep)
            hashVal -= mersennep;

        return static_cast<int>( hashVal ) % M;
    }

    bool contains(HashedObj x)  {
        size_t index = strToHashValue(x.getKey());
        cout << index << endl;
        for (typename std::list<HashedObj>::iterator it = theLists.at(index).begin();
             it != theLists.at(index).end(); ++it) {
            if(it->getKey() == x.getKey() && it->getValue() == x.getValue())
                return true;
        }
        return false;
    }

    void makeEmpty();


    bool insert(const HashedObj &x) const {
        std::list<int>::iterator it;
        theLists[0].insert(theLists[0].begin(), x);
        return true;
    }

//    bool insert(HashedObj &&x)

    bool remove(const HashedObj &x);


private:
    vector<list<HashedObj>> theLists;
    int currentSize;
    int capacity;

    void rehash();

};


