#include <iostream>
#include <vector>

using namespace std;

// Node class
template<class T, class U>
class Node {
public:

    T key;
    vector<U> values; // To hold all the values for the key
    Node *left;
    Node *right;

    Node() {
    }

    // Constructor
    Node(T key, const U &value) {
        this->key = key;
        this->right = nullptr;
        this->left = NULL;
        this->values.push_back(value);
    }
};

// Iterator class
template<class T, class U>
class Iterator {
public:
    using pointer = Node<T, U> *;
    using reference = Node<T, U> &;

    Iterator(pointer ptr) : m_ptr(ptr) {}

    // Iterator operator overloading
    reference operator*() const { return *m_ptr; }

    Iterator &operator++() {
        m_ptr++;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

    friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

public:
    pointer operator->() { return m_ptr; }

private:
    pointer m_ptr;
};


// Dictionary class
template<class T, class U>
class Dictionary {

private:
    Node<T, U> *root;
    int size_;

    // Recursive function to insert key value pair
    Node<T, U> *insertRecur(Node<T, U> *node, T key, const U &value) {
        // If the key is not exists
        if (node == nullptr) {
            Node<T, U> *newNode = new Node<T, U>(key, value);
            return newNode;
        }

        // If the key already exists
        if (key == node->key) {
            node->values.push_back(value);
        } else if (key < node->key)
            node->left = insertRecur(node->left, key, value);
        else
            node->right = insertRecur(node->right, key, value);
        return node;
    }

    // Recursive function to display the dictionary
    void displayDictionaryRecur(Node<T, U> *node) {
        if (node != nullptr) {
            displayDictionaryRecur(node->left);
            cout << "\t" << node->key << " : ";
            for (const string &value: node->values) {
                cout << value << "\t";
            }
            cout << endl;
            displayDictionaryRecur(node->right);
        }
    }

    // Function to get node with minimum value in the right sub tree
    Node<T, U> *minValueNode(Node<T, U> *node) {
        Node<T, U> *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Recursive function to remove key from the dictionary
    Node<T, U> *eraseByKeyRecur(Node<T, U> *node, T key) {
        // If the dictionary is empty
        if (node == nullptr) return node;

        // Traverse left subtree
        if (key < node->key)
            node->left = eraseByKeyRecur(node->left, key);

            // Traverse right subtree
        else if (key > node->key)
            node->right = eraseByKeyRecur(node->right, key);

            // If the key found
        else {
            // If left child of the relevant node is empty
            if (node->left == NULL) {
                Node<T, U> *temp = node->right;
                free(node);
                return temp;
            }
            // If right child of the relevant node is empty
            else if (node->right == nullptr) {
                Node<T, U> *temp = node->left;
                free(node);
                return temp;
            }

            // If the node has 2 children
            Node<T, U> *temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = eraseByKeyRecur(node->right, temp->key);
        }
        return node;
    }

    // Recursive function to find the key
    Iterator<T, U> findRecur(Node<T, U> *node, T key) {
        if (node == nullptr) return nullptr;

        // Traverse left subtree
        if (key < node->key)
            return findRecur(node->left, key);

        // Traverse right subtree
        else if (key > node->key)
            return findRecur(node->right, key);

        // Return an Iterator
        return Iterator<T, U>(node);

    }

public:
    // Constructor
    Dictionary() {
        this->root = nullptr;
        this->size_ = 0;
    }

    // Function to insert key value pair
    void insert(T key, U value) {
        root = insertRecur(root, key, value);
        size_++;
    }

    // Function to display the dictionary
    void displayDictionary() {
        cout << "Size of the dictionary: " << size() << endl;
        displayDictionaryRecur(root);
    }

    // Function to get size
    int size() {
        return size_;
    }

    // Function to check whether the dictionary is empty
    bool empty() {
        return size_ == 0;
    }

    // Function to remove key from the dictionary
    void erase(T key) {
        size_ -= findRecur(root, key)->values.size();
        root = eraseByKeyRecur(root, key);
    }

    // Function to remove key from the dictionary using an iterator
    void erase(Iterator<T, U> iterator) {
        size_ -= findRecur(root, iterator->key)->values.size();
        root = eraseByKeyRecur(root, iterator->key);
    }

    // Function to display all the values for a key using an iterator
    void displayValues(Iterator<T, U> iterator) {
        cout << "\t" << iterator->key << " : ";
        for (const string &value: iterator->values) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Function to get Iterator at the start of the bst
    Iterator<T, U> begin() { return Iterator<T, U>(root); }

    // Function to get Iterator at the end of the bst
    Iterator<T, U> end() {
        Node<T, U> *temp = root;

        while (temp != nullptr && temp->right != nullptr) {
            temp = temp->right;
        }

        return Iterator<T, U>(temp);
    }

    // Function to get an Iterator for a key
    Iterator<T, U> find(T key) {
        return findRecur(root, key);
    }


};

// Main function for testing
int main() {
    Dictionary<string, string> dictionary;

    cout << "\nBefore Inserting Entries" << endl;
    cout << "Is empty : " << (dictionary.empty() ? "Yes" : "No") << endl;
    dictionary.displayDictionary();

    dictionary.insert("John", "America");
    dictionary.insert("Mary", "Japan");
    dictionary.insert("Carlton", "Chili");
    dictionary.insert("Chris", "India");
    dictionary.insert("Hamilton", "Canada");
    dictionary.insert("Jordan", "Australia");
    dictionary.insert("Mary", "Australia");
    dictionary.insert("Mark", "New zealand");
    dictionary.insert("Jessy", "China");
    dictionary.insert("John", "Germany");
    dictionary.insert("Mary", "Brazil");

    cout << "\nAfter Inserting Entries" << endl;
    cout << "Is empty : " << (dictionary.empty() ? "Yes" : "No") << endl;
    dictionary.displayDictionary();

    dictionary.erase("Chris");
    cout << "\nAfter Removing Entry 'Chris' using key" << endl;
    dictionary.displayDictionary();

    cout << "\nAfter Removing Entry 'John' using iterator" << endl;
    dictionary.erase(dictionary.find("John"));
    dictionary.displayDictionary();


    cout << "\nFind Begin Entry" << endl;
    dictionary.displayValues(dictionary.begin());

    cout << "\nFind Entry 'Jessy'" << endl;
    dictionary.displayValues(dictionary.find("Jessy"));

    cout << "\nFind End Entry" << endl;
    dictionary.displayValues(dictionary.end());

    cout << "\nFind Invalid Entry " << endl;
    dictionary.displayValues(dictionary.find("Henry"));

}
