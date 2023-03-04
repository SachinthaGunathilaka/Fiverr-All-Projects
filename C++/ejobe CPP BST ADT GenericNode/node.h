#include<iostream>

using namespace std;

// Generic Node class
template<class T>
class Node {
private:
    Node<T> *left; // left node

    // data
    T data1;
    T data2;
    Node<T> *right; // right node

public:

    // constructor
    Node(T d1, T d2) {
        data1 = d1;
        data2 = d2;
        left = right = NULL;
    }

    // set left node
    void SetLeft(Node<T> *l) {
        left = l;
    }

    // get left node
    Node<T> *GetLeft() {
        return left;
    }

    // set data to the node
    void SetData(T d1, T d2) {
        data1 = d1;
        data2 = d2;
    }

    // get data1 (name)
    T GetData1() {
        return data1;
    }

    // get data2 (birthday)
    T GetData2() {
        return data2;
    }

    // set right node
    void SetRight(Node<T> *r) {
        right = r;
    }

    // get right node
    Node<T> *GetRight() {
        return right;
    }

    // check whether there exist a left child
    bool IsLeft() {
        if (left == NULL)
            return false;
        else
            return true;
    }

    // check whether there exist a right child
    bool IsRight() {
        if (right == NULL)
            return false;

        return true;
    }
};