#ifndef NODE_H
#define NODE_H

// make it generic
template <typename T>

// defining node as a struct having a data of T and a next pointer
struct Node {
    T data;
	Node<T>* next;
};

#endif // NODE_H