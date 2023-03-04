#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
    LinkedList linkedList;
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);
    linkedList.insert(5);

//    cout << linkedList.print() << endl;

    // ROTATE TO HEAD
    //-------------------------------------
//    linkedList.rotateToHead(3);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotateToHead(3);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotateToHead(6);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotateToHead(4);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotateToHead(3);
//    cout << linkedList.print() << endl;


// ROTATE
//-------------------------------------
//    linkedList.rotate(2);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotate(0);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotate(5);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotate(4);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotate(6);
//    cout << linkedList.print() << endl;
//
//    linkedList.rotate(13);
//    cout << linkedList.print() << endl;

// ReverseTail
//-----------------------------------
//    linkedList.reverseTail(2);
//    cout << linkedList.print() << endl;
//
//    linkedList.reverseTail(3);
//    cout << linkedList.print() << endl;
//
//    linkedList.reverseTail(4);
//    cout << linkedList.print() << endl;
//
//    linkedList.reverseTail(5);
//    cout << linkedList.print() << endl;
//
//    linkedList.reverseTail(6);
//    cout << linkedList.print() << endl;


    //PALINDROME
    // --------------------------------------
//    cout << linkedList.palindrome() << endl;
//
//    LinkedList l2;
//    l2.insert(10);
//    l2.insert(20);
//    l2.insert(10);
//    cout << l2.palindrome() << endl;
//
//    LinkedList l3;
//    l3.insert(10);
//    l3.insert(20);
//    l3.insert(20);
//    l3.insert(10);
//    cout << l3.palindrome() << endl;
//
//    LinkedList l4;
//    l4.insert(10);
//    l4.insert(20);
//    l4.insert(30);
//    l4.insert(20);
//    l4.insert(10);
//    cout << l4.palindrome() << endl;
//
//    LinkedList l5;
//    cout << l5.palindrome() << endl;


// DELETE LAST
//    LinkedList linkedList1;
//    linkedList1.insert(7);
//    linkedList1.insert(42);
//    linkedList1.insert(101);
//    linkedList1.insert(42);
//    linkedList1.insert(50);
//    linkedList1.insert(3);
//    linkedList1.insert(7);
//    cout << linkedList1.print() << endl;
//    linkedList1.deleteLast(7);
//    cout << linkedList1.print() << endl;


// DUPLICATES

    LinkedList linkedList1;
    linkedList1.insert(20);
    linkedList1.insert(20);
    linkedList1.insert(50);
    linkedList1.insert(50);
    linkedList1.insert(10);
    linkedList1.insert(20);
    linkedList1.insert(20);
    linkedList1.insert(20);
    linkedList1.insert(10);
    linkedList1.insert(10);
    linkedList1.insert(10);
    cout << linkedList1.print() << endl;
    linkedList1.dedup();
    cout << linkedList1.print() << endl;


    return 0;
}
