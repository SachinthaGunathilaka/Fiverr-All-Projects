#include "../Bst.h"


void Print(int& value)
{
    cout << value << " ";
}

int main()
{



    Bst<int> BST;
    BST.Insert(42);
    BST.Insert(16);
    BST.Insert(28);
    BST.Insert(2);
    BST.Insert(23);

//    Bst<int> BST2(BST);

//    BST.CopyTree(BST2, BST);

//    BST2.InOrderTraversal(Print);



    cout << "In Order: ";
    BST.InOrderTraversal();


    cout <<"\nPre Order: ";
    BST.PreOrderTraversal();

    cout <<"\nPost Order: ";
    BST.PostOrderTraversal();

//    Bst<int> BST2;
//    BST2 = BST;
//
//    cout <<"\nAnother BST: ";
//    BST2.InOrderTraversal(Print);
//
//    cout <<"\nDestroying 2nd Tree....";
//    BST2.DestroyTree();
////    BST2.InOrderTraversal(Print);
//
//    int number;
//    while (number != -1)
//    {
//    cout << "\n\nPlease search a number from the first tree (-1 to exit)" <<endl;
//    cin >> number;
//
//    if(BST.Search(number))
//    {
//        cout << "Number found!" << endl;
//    }
//    else
//    {
//        cout << "Number not found!" << endl;
//    }
//    cout << "Tree: ";
//    BST.InOrderTraversal(Print);
//    }

    return 0;
}
