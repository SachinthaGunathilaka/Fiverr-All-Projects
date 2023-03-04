#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

typedef struct node *NODE;

void inorder(NODE root);

NODE returnNewNode(int data);

void insert(NODE *root, NODE newNode);

void splay(NODE *root, NODE newNode);

void leftRotationPro(NODE *root, NODE parentOfNewNode);

void rightRotationPro(NODE *root, NODE parentOfNewNode);

void leftRotation(NODE *parentNode);

void rightRotation(NODE *parentNode);


int main(void) {
    FILE *infile = fopen("mydata.txt", "r");
    NODE root = NULL; // root of the BST

    // My dataset locates in a text file. reading the file and inserting data into the BST
    while (!feof(infile)) {
        int data;
        fscanf(infile, "%d", &data);
        insert(&root, returnNewNode(data));
    }

    fclose(infile);

    puts("\n \t -------- in-order traversal ------\n");
    inorder(root);
    puts("\n");

    return 0;
}


void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

NODE returnNewNode(int data) {
    NODE newNode = malloc(sizeof(struct node));
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->data = data;
    return newNode;
}

void insert(NODE *root, NODE newNode) {
    NODE temp = *root;
    NODE parent = NULL;

    while (temp != NULL) {
        parent = temp;

        if (newNode->data > temp->data)
            temp = temp->right;

        else if (newNode->data < temp->data)
            temp = temp->left;
    }

    newNode->parent = parent;

    if (parent == NULL)// if the tree is empty
        *root = newNode;
    else if (newNode->data > parent->data)
        parent->right = newNode;
    else if (newNode->data < parent->data)
        parent->left = newNode;

    splay(root, newNode);
}

// AKA. ZIG ( without parent attribute in the structure )
void rightRotation(NODE *parentNode) {
    NODE leftChild = (*parentNode)->left;
    (*parentNode)->left = leftChild->right;
    leftChild->right = *parentNode;
}

// AKA. ZAG ( without parent attribute in the structure )
void leftRotation(NODE *parentNode) {
    NODE rightChild = (*parentNode)->right;
    (*parentNode)->right = rightChild->left;
    rightChild->left = *parentNode;
}


// AKA. ZIG ( with parent attribute in the structure )
void rightRotationPro(NODE *root, NODE parentOfNewNode) {
    NODE leftChild = parentOfNewNode->left;
    parentOfNewNode->left = leftChild->right;

    if (leftChild->right != NULL)
        leftChild->right->parent = parentOfNewNode;

    leftChild->parent = parentOfNewNode->parent;

    //if the new node is at root position now
    if (parentOfNewNode->parent == NULL)
        *root = leftChild;

    else if (parentOfNewNode == parentOfNewNode->parent->right)
        parentOfNewNode->parent->right = leftChild;

    else
        parentOfNewNode->parent->left = leftChild;

    leftChild->right = parentOfNewNode;
    parentOfNewNode->parent = leftChild;

}

// AKA. ZAG ( with parent attribute in the structure )
void leftRotationPro(NODE *root, NODE parentOfNewNode) {
    NODE rightChild = parentOfNewNode->right;
    parentOfNewNode->right = rightChild->left;

    if (rightChild->left != NULL) {
        rightChild->left->parent = parentOfNewNode;
    }

    rightChild->parent = parentOfNewNode->parent;

    //if the new node is at root position now
    if (parentOfNewNode->parent == NULL)
        *root = rightChild;

    else if (parentOfNewNode->parent->left == parentOfNewNode)
        parentOfNewNode->parent->left = rightChild;

    else
        parentOfNewNode->parent->right = rightChild;

    rightChild->left = parentOfNewNode;
    parentOfNewNode->parent = rightChild;
}


void splay(NODE *root, NODE newNode) {
    while (newNode->parent != NULL) {
        if (newNode->parent == *root) {
            puts("ok1");
            if (newNode == newNode->parent->left) {
                rightRotationPro(root, newNode->parent);
                //puts("ok2");
            } else {
                leftRotationPro(root, newNode->parent);
            }
            //puts("ok3");
        } else {
            puts("ok4");
            NODE parent = newNode->parent;
            NODE grandParent = parent->parent;

            //both are left children
            if (newNode->parent->left == newNode && parent->parent->left == parent) {
                rightRotationPro(root, parent);
                rightRotationPro(root, grandParent);
            }

                //both are right children
            else if (newNode->parent->right == newNode && parent->parent->right == parent) {
                leftRotationPro(root, parent);
                leftRotationPro(root, grandParent);
            } else if (newNode->parent->right == newNode && parent->parent->left == parent) {
                leftRotationPro(root, grandParent);
                rightRotationPro(root, parent);
            } else if (newNode->parent->left == newNode && parent->parent->right == parent) {
                rightRotationPro(root, parent);
                leftRotationPro(root, grandParent);
            }
        }
    }
}



















