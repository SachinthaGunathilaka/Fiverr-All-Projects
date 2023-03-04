#include<iostream>
#include "bst.h"
using namespace std;

int main(){
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(12);
    bst.insert(2);
    bst.insert(30);
    bst.insert(7);

//    cout << bst.printInOrder() << endl;
//    cout << bst.printPreOrder() << endl;
//    cout << bst.printPostOrder() << endl;


    /*
                  10
              5         20
          2      7   12     30

       */


    if(bst.lca(100, 10) != nullptr){
        cout << bst.lca(10, 50)->key << endl;

    } else
        cout << "Null"<< endl;


    cout << bst.width() << endl;


    return 0;
}