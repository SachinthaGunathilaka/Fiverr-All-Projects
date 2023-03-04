#include <iostream>

using namespace std;


template<class T>
class Bst {

    struct node {
        T value;
        struct node *right;
        struct node *left;
    };

public:
    Bst();

    ~Bst();

    void Insert(T &val);

    void PreOrderTraversal();

    void InOrderTraversal();

    void PostOrderTraversal();

    int size();

    bool lookup(T val);

    void calculateSpeedTemp(float & total_speed, float & total_temp) {


        return calculateSpeedTemp(root, total_speed, total_temp);

    }

    void calculateSpeedTemp(struct node *node, float &total_speed, float &total_temp) {
        if (node != NULL) {

            total_speed += node->value->GetSpeed() * 3.6;
            total_temp += node->value->GetTemperature();
            calculateSpeedTemp(node->left, total_speed, total_temp);
            calculateSpeedTemp(node->right, total_speed, total_temp);
        }

    }

    void calculateSolarRadiation(float & total_radiation) {

        return calculateSolarRadiation(root, total_radiation);

    }

    void calculateSolarRadiation(struct node *node, float &total_radiation) {
        if (node != NULL) {

            if (node->value->GetSolarRadiation() >= 100) {
                total_radiation += node->value->GetSolarRadiation() / 6000;
            }

            calculateSolarRadiation(node->left, total_radiation);
            calculateSolarRadiation(node->right, total_radiation);
        }

    }


private:
    struct node *root;
    int treeSize;

    void Insert(struct node **node, T &val);

    bool lookup(struct node *node, T val);

    void PreOrderTraversal(struct node *node);

    void InOrderTraversal(struct node *node);

    void PostOrderTraversal(struct node *node);

    void deleteTree(struct node *node);
};

template<class T>
Bst<T>::Bst() {
    this->root = NULL;
    this->treeSize = 0;
}

template<class T>
Bst<T>::~Bst() {
    deleteTree(this->root);
}

template<class T>
int Bst<T>::size() {
    return this->treeSize;
}

template<class T>
void Bst<T>::Insert(T &val) {
//    cout << *val;
    Insert(&(this->root), val);
}

template<class T>
void Bst<T>::Insert(struct node **node, T &val) {

    if (*node == NULL) {
        struct node *tmp = new struct node;
        tmp->value = val;

//        cout << *val;
//        cout << *tmp->value << endl;
        tmp->left = NULL;
        tmp->right = NULL;
        *node = tmp;

        this->treeSize++;
    } else {

//        cout << *val;

        if (val > (*node)->value) {
            Insert(&(*node)->right, val);
        } else {
            Insert(&(*node)->left, val);
        }
    }


}

template<class T>
void Bst<T>::InOrderTraversal() {
    InOrderTraversal(this->root);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

template<class T>
void Bst<T>::InOrderTraversal(struct node *node) {
    if (node != NULL) {
        InOrderTraversal(node->left);
        std::cout << *node->value << ", ";
        InOrderTraversal(node->right);
    }
}

template<class T>
void Bst<T>::PreOrderTraversal() {
    PreOrderTraversal(this->root);
    std::cout << std::endl;
}

template<class T>
void Bst<T>::PreOrderTraversal(struct node *node) {
    if (node != NULL) {
        std::cout << node->value << ", ";
        InOrderTraversal(node->left);
        InOrderTraversal(node->right);
    }
}

template<class T>
void Bst<T>::PostOrderTraversal() {
    PostOrderTraversal(this->root);
    std::cout << std::endl;
}

template<class T>
void Bst<T>::PostOrderTraversal(struct node *node) {
    if (node != NULL) {
        InOrderTraversal(node->left);
        InOrderTraversal(node->right);
        std::cout << node->value << ", ";
    }
}


template<class T>
void Bst<T>::deleteTree(struct node *node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template<class T>
bool Bst<T>::lookup(T val) {
    return lookup(this->root, val);
}

template<class T>
bool Bst<T>::lookup(struct node *node, T val) {
    if (node == NULL) {
        return false;
    } else {
        if (val == node->value) {
            return true;
        }

        if (val > node->value) {
            return lookup(node->right, val);
        } else {
            return lookup(node->left, val);
        }
    }

}