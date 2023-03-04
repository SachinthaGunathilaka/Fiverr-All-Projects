// Filename: bst.cpp
// 
// Contains the class BST that represents a binary search tree. This contains some basic operations, such as insert, delete, find, and printing in various traversal orders
// 
// C. Seshadhri, Jan 2020

#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Default constructor sets head and tail to null
BST::BST() {
    root = NULL;
}

// Insert(int val): Inserts the int val into tree, at the head of the list. Note that there may be multiple copies of val in the list. Just calls the recursive function
// Input: Int to insert into the BST
// Output: Void, just inserts new Node
void BST::insert(int val) {
    Node *to_insert = new Node(val); // create a new Node with the value val
    if (root == NULL) // tree is currently empty
        root = to_insert; // make new node the root
    else
        insert(root, to_insert); // make call to recursive insert, starting from root
}

// insert(Node* start, Node* to_insert): Inserts the Node to_insert into tree rooted at start. We will always call with start being non-null. Note that there may be multiple copies of val in the list. 
// Input: Int to insert into the subtree
// Output: Void, just inserts new Node
void BST::insert(Node *start, Node *to_insert) {
    if (start == NULL) // in general, this should not happen. We never call insert from a null tree
        return;
    if (to_insert->key <= start->key) // inserted node has smaller (or equal) key, so go left
    {
        if (start->left == NULL) {
            start->left = to_insert; // make this node the left child
            to_insert->parent = start; // set the parent pointer
            return;
        } else // need to make recursive call
        {
            insert(start->left, to_insert);
            return;
        }
    } else // inserted node has larger key, so go right
    {
        if (start->right == NULL) {
            start->right = to_insert; // make this node the right child
            to_insert->parent = start; // set the parent pointer
            return;
        } else // need to make recursive call
        {
            insert(start->right, to_insert);
            return;
        }
    }
}

// find(int val): Finds a Node with key "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node with val, at it traverses down the tree
Node *BST::find(int val) {
    return find(root, val); // call the recursive function starting at root
}

// find(Node* start, int val): Recursively tries to find a Node with key "val", in subtree rooted at val
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node with val, at it traverses down the tree
Node *BST::find(Node *start, int val) {
    if (start == NULL || start->key == val) // tree is empty or we found val
        return start;
    if (val < start->key) // val is smaller, so go left
        return find(start->left, val);
    else // val is larger, so go right
        return find(start->right, val);
}

// minNode(Node* start): gets the minimum Node in subtree rooted at start
// Input: Pointer to subtree root
// Output: pointer to the minimum node in the subtree
Node *BST::minNode(Node *start) {
    if (start == NULL) // typically, this should not happen. But let's return the safe thing
        return NULL;
    if (start->left == NULL) // Base case: we have found the minimum
        return start;
    else
        return minNode(start->left); // recursive call in left subtree
}

// maxNode(Node* start): gets the maximum Node in subtree rooted at start
// Input: Pointer to subtree root
// Output: pointer to the maximum node in the subtree
Node *BST::maxNode(Node *start) {
    if (start == NULL) // typically, this should not happen. But let's return the safe thing
        return NULL;
    if (start->right == NULL) // Base case: we have found the maximum
        return start;
    else
        return maxNode(start->right); // recursive call in left subtree
}

// deleteNode(int val): Delete a Node with key val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node *BST::deleteKey(int val) {
    return deleteNode(find(val)); // get a node with the value and delete that node
}

// deleteNode(Node* to_delete): Delete the input node, and return pointer to the deleted node. The node will be isolated from the tree, to prevent memory leaks
// Input: Node to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. 
Node *BST::deleteNode(Node *to_delete) {
    if (to_delete == NULL) // val not present in tree, so return NULL
        return NULL;

    bool isRoot = (to_delete == root) ? true : false; // determine if node to delete is root
    bool isLeftChild = false;
    if (!isRoot) // if this is not the root
        isLeftChild = (to_delete->parent->left == to_delete) ? true
                                                             : false; // determine if node is left child of parent. Note that line throws error iff to_delete is root

    bool isDeleted = false; // convenient flag for writing code

    // if to_delete's left child is NULL, then we can splice this node off. We set the appropriate
    // pointer of the parent to the right child of to_delete
    if (to_delete->left == NULL) {
        if (isRoot) // if deleting root, then we reset root
        {
            root = to_delete->right;
            if (root != NULL)
                root->parent = NULL; // set parent to be NULL
        } else {
            if (isLeftChild) // node is left child of parent
                to_delete->parent->left = to_delete->right; // setting left child of parent to be right child of node
            else // node is right child of parent
                to_delete->parent->right = to_delete->right; // setting right child of parent to be right child of node
            if (to_delete->right != NULL) // to_delete is not a leaf
                to_delete->right->parent = to_delete->parent; // update parent of the child of the deleted node, to be parent of deleted node
        }
        isDeleted = true; // delete is done
    }
    // suppose node is not deleted yet, and it's right child is NULL. We splice off as before, by setting parent's child pointer to to_delete->left
    if (!isDeleted && to_delete->right == NULL) {
        if (isRoot) // if deleting root, then we reset root
        {
            root = to_delete->left;
            if (root != NULL)
                root->parent = NULL; // set parent to be NULL
        } else {
            if (isLeftChild) // node is left child of parent
                to_delete->parent->left = to_delete->left; // setting left child of parent to be left child of node
            else // node is right child of parent
                to_delete->parent->right = to_delete->left; // setting right child of parent to be left child of node
            if (to_delete->left != NULL) // to delete is not a leaf
                to_delete->left->parent = to_delete->parent; // update parent of the child of deleted node, to be parent of deleted node
        }
        isDeleted = true; // delete is done
    }
    if (isDeleted) // so node has been deleted
    {
        to_delete->left = to_delete->right = NULL;
        return to_delete;
    }

    // phew. The splicing case is done, so now for the recursive case. Both children of to_delete are not null, so we replace the data in to_delete by the successor. Then we delete the successor node
    // first, get the minimum node of right subtree
    Node *succ = minNode(to_delete->right);
    to_delete->key = succ->key;
//     cout << "Replacing with "+to_string(succ->key) << endl;
    return deleteNode(
            succ); // make recursive call on succ. Note that succ has one null child, so this recursive call will terminate without any other recursive calls
}


// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void BST::deleteBST() {
    deleteBST(root);
}

// Deletes every Node in subtree rooted at startto prevent memory leaks.
// Input: Node* start
// Output: Void, just deletes every Node of the list
void BST::deleteBST(Node *start) {
    if (start == NULL) // tree is already empty
        return;
    deleteBST(start->left); // delete left subtree
    deleteBST(start->right); // delete right subtree
    delete (start); // delete node itself
}

// Prints tree in order. Calls the recursive function from the root
// Input: None
// Output: string that has all elements of the tree in order
string BST::printInOrder() {
    return printInOrder(root);
}

// Prints tree Preorder. Calls the recursive function from the root
// Input: None
// Output: string that has all elements of the tree pre order
string BST::printPreOrder() {
    return printPreOrder(root);
}

// Prints tree Postorder. Calls the recursive function from the root
// Input: None
// Output: string that has all elements of the tree post order
string BST::printPostOrder() {
    return printPostOrder(root);
}

// Prints rooted subtree tree in order, by making recursive calls
// Input: None
// Output: string that has all elements of the rooted tree in order
string BST::printInOrder(Node *start) {
    if (start == NULL) // base case
        return ""; // return empty string
    string leftpart = printInOrder(start->left);
    string rightpart = printInOrder(start->right);
    string output = to_string(start->key);
    if (leftpart.length() != 0) // left part is empty
        output = leftpart + " " + output; // append left part
    if (rightpart.length() != 0) // right part in empty
        output = output + " " + rightpart; // append right part

    return output;
}

// Prints rooted subtree tree preorder, by making recursive calls
// Input: None
// Output: string that has all elements of the rooted tree preorder
string BST::printPreOrder(Node *start) {
    if (start == NULL) // base case
        return ""; // return empty string
    string leftpart = printPreOrder(start->left);
    string rightpart = printPreOrder(start->right);
    string output = to_string(start->key);
    if (leftpart.length() != 0) // left part is empty
        output = output + " " + leftpart; // append left part
    if (rightpart.length() != 0) // right part in empty
        output = output + " " + rightpart; // append right part
    return output;
}

// Prints rooted subtree tree postorder, by making recursive calls
// Input: None
// Output: string that has all elements of the rooted tree in post order
string BST::printPostOrder(Node *start) {
    if (start == NULL) // base case
        return ""; // return empty string
    string leftpart = printPostOrder(start->left);
    string rightpart = printPostOrder(start->right);
    string output = to_string(start->key);
    if (rightpart.length() != 0) // right part is empty
        output = rightpart + " " + output; // append left part
    if (leftpart.length() != 0) // left part in empty
        output = leftpart + " " + output; // append right part
    return output;
}


// Get the least common ancestor of val1 and val2. Calls the recursive function from the root
// Input: int val1, int val2
// Output: the least common ancestor of val1 and val2
Node *BST::lca(int val1, int val2) {

    // If the tree is empty or either one of the value is not present in the tree, return NULL
    if (root == nullptr || find(val1) == nullptr || find(val2) == nullptr)
        return nullptr;

    // Calls the recursive function from the root
    return lca(root, val1, val2);

}


// Get the least common ancestor of val1 and val2 by making recursive calls
// Input: int val1, int val2
// Output: the least common ancestor of val1 and val2
Node *BST::lca(Node *root, int val1, int val2) {

    // If current node is NULL or equal to val1 or val2 return that node
    if (root == nullptr || root->key == val1 || root->key == val2)
        return root;

    // Call lca for left child of the current node
    Node *left_lca = lca(root->left, val1, val2);
    // Call lca for right child of the current node
    Node *right_lca = lca(root->right, val1, val2);

    // If result of left child and result of right child are not NULL, return current node
    if (left_lca && right_lca)
        return root;

    // If result of left child is NULL, return right child
    if (left_lca == NULL)
        return right_lca;

        // If result of right child is NULL, return left child
    else
        return left_lca;
}

int BST::width() {
    /*
     * level : Set of nodes at the same distance from root
     * width : Size of the largest level
     */
    int width = 0;
    int level = 0;

    // Create empty Queue
    queue<Node *> queue_;

    // If the tree is empty
    if (root == nullptr) {
        return 0;
    }

    // Initially add root node to the queue
    queue_.push(root);

    // This loop will run until queue is empty
    while (!queue_.empty()) {
        // Number of elements in the queue is the level
        level = queue_.size();

        // Compare width with the current level and calculate the width
        if (width < level)
            width = level;

        //If variable nodesInLevel contains more than one node
        //then, for each node, we'll add left and right child of the node to the queue

        // This loop will execute until level is greater than 0
        while (level > 0) {

            // Get top node
            Node *current = queue_.front();
            queue_.pop();

            // If its left child is not NULL add it to the queue
            if (current->left != NULL) {
                queue_.push(current->left);
            }

            // If its right child is not NULL add it to the queue
            if (current->right != NULL) {
                queue_.push(current->right);
            }

            // Decrement level by 1
            level--;
        }
    }

    // Return width
    return width;

}
