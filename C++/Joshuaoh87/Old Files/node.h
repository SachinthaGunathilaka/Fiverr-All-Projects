#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

using namespace std;

template<class T>
struct node {
    T value;
    struct node *right;
    struct node *left;

    node<T>()= default;
};


#endif // NODE_H_INCLUDED
