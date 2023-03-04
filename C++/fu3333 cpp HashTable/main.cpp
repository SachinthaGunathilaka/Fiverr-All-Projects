#include "myHashTable.h"
#include "HashedObj.h"
#include <iostream>

int main() {
    myHashTable<HashedObj> hashTable(101);
    const HashedObj h("hi", 10);
//    hashTable.insert(h);
//    hashTable.printTable();
    cout << hashTable.contains(h);









    return 0;
}
