#include <iomanip>
#include <string>
#include <iostream>
#include "node.h"


template<class T>
class BST {

public:

    Node<T> *root; // root node


    // method definitions
    void Inorder(Node<T> *r);

    bool Insert(T data1, T data2);

    void Search(Node<T> *r, T data1);

    void Edit(Node<T> *r, T data1, T data2);

    bool Delete(T data);

    void print(Node<T> *node);

    // constructor
    BST() {
        root = NULL;
    }
};


// traverse through the binary tree in order
template<class T>
void BST<T>::Inorder(Node<T> *r) {
    if (r->IsLeft())
        Inorder(r->GetLeft());
    print(r);

    if (r->IsRight())
        Inorder(r->GetRight());
}

// Insert data to the binary tree
template<class T>
bool BST<T>::Insert(T data1, T data2) {
    Node<T> *node = new Node<T>(data1, data2);

    // If there are no nodes in the binary tree
    if (root == NULL) {
        root = node;
        return true;
    }


    Node<T> *ptr = root;

    // Loop until ptr is null
    while (ptr != NULL) {

        // If node already exists
        if (ptr->GetData1() == data1) {
            return false;
        }
        // Traerse left
        else if (ptr->GetData1() > data1) {
            if (!ptr->IsLeft()) {
                ptr->SetLeft(node);
                break;
            }
            ptr = ptr->GetLeft();
        }
        // traverse right
        else if (ptr->GetData1() < data1) {
            if (!ptr->IsRight()) {
                ptr->SetRight(node);
                break;
            }
            ptr = ptr->GetRight();
        }
    }
    return true;
}

// Search a node
template<class T>
void BST<T>::Search(Node<T> *r, T data1) {

    // At the end of the binary tree
    if (r == NULL) {
        cout << "Person not found" << endl;
    }
    // If node found
    else if (r->GetData1() == data1) {
        print(r); // display it
    }
    // traverse left
    else if (r->GetData1() > data1) {
        Search(r->GetLeft(), data1);
    }
    // traverse right
    else {
        Search(r->GetRight(), data1);
    }
}

// delete a node
template<class T>
bool BST<T>::Delete(T data1) {
    if (root == NULL) {
        return -1;
    }

    Node<T> *ptr = root;
    Node<T> *parent = NULL;

    while (ptr) {
        if (ptr->GetData1() == data1) {
            break;
        } else if (ptr->GetData1() > data1) {
            parent = ptr;
            ptr = ptr->GetLeft();
        } else if (ptr->GetData1() < data1) {
            parent = ptr;
            ptr = ptr->GetRight();
        }
    }

    if (ptr == NULL) {
        return false;
    }

    while (1) {
        // If node is a leaf
        if (!ptr->IsLeft() && !ptr->IsRight()) {
            if (parent == NULL) {
                root = NULL;
            } else {
                if (parent->GetLeft() == ptr)
                    parent->SetLeft(NULL);
                else
                    parent->SetRight(NULL);
            }

            delete ptr;
            break;
        }
        // If only left child exists
        else if (ptr->IsLeft() && !ptr->IsRight()) {
            if (parent == NULL) {
                root = ptr->GetLeft();
                delete ptr;
                break;
            } else {
                if (parent->GetLeft() == ptr) {
                    parent->SetLeft(ptr->GetLeft());
                    delete ptr;
                    break;
                } else if (parent->GetRight() == ptr) {
                    parent->SetRight(ptr->GetLeft());
                    delete ptr;
                    break;
                }
            }
        }
        // If only right child is exists
        else if (!ptr->IsLeft() && ptr->IsRight()) {
            if (parent == NULL) {
                root = ptr->GetRight();
                delete ptr;
                break;
            } else {
                if (parent->GetLeft() == ptr) {
                    parent->SetLeft(ptr->GetRight());
                    delete ptr;
                    break;
                } else if (parent->GetRight() == ptr) {
                    parent->SetRight(ptr->GetRight());
                    delete ptr;
                    break;
                }
            }
        }

        // if both childs exists

        // get in order successor
        Node<T> *succ = ptr->GetRight();
        Node<T> *succparent = ptr;

        while (succ->IsLeft()) {
            succparent = succ;
            succ = succ->GetLeft();
        }

        ptr->SetData(succ->GetData1(), succ->GetData2());
        succ->SetData(ptr->GetData1(), ptr->GetData2());

        ptr = succ;
        parent = succparent;
    }
    return true;
}

// Display a node
template<class T>
void BST<T>::print(Node<T> *node) {
    cout << "Name : " << setw(20) << fixed << left << node->GetData1() << " Birth Day : " << node->GetData2() << endl;

}

// Editing a node
template<class T>
void BST<T>::Edit(Node<T> *r, T data1, T data2) {
    // at the end of the bst
    if (r == NULL) {
        cout << "Person not found" << endl;
    }
    // if node found replace by new values
    else if (r->GetData1() == data1) {
        r->SetData(data1, data2);
        cout << "Person edited successfully" << endl;
    } else if (r->GetData1() > data1) {
        Search(r->GetLeft(), data1);
    } else {
        Search(r->GetRight(), data1);
    }
}
