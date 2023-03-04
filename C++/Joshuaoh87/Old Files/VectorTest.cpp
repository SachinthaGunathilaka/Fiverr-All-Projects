#include "Vector.h"
#include <iostream>

using namespace std;


int main()
{
    // Create the vector
    Vector<int> integerVector;      // construct a vector
    cout << "Vector successfully created" << endl;

    integerVector.Add(13);          // add to vector
    integerVector.Add(14);
    integerVector.Add(15);
    cout <<"The elements in the vector are: " << endl;
        for(int i = 0; i < integerVector.GetSize(); i++)
    {
       cout << integerVector.at(i) << endl;;
    }


    cout << "The size of the vector is " << integerVector.GetSize() << endl;                // get the size
    cout << "The capacity of the vector is " << integerVector.GetAllocation() << endl;      // get the initial capacity

    integerVector.Add(16);
    integerVector.Add(17);

    cout << "The new capacity of the vector is " << integerVector.GetAllocation() << endl;  // testing the Resize() function


        cout << "The element at position 3" << " is " << integerVector.at(3) << endl;


    Vector<int> integerVector2;
    integerVector2 = integerVector;         // copy constructor

    cout << "\n======== INTEGER VECTOR 2 ========" <<endl;
        for(int i = 0; i < integerVector2.GetSize(); i++)        // testing the copy constructor function
    {
        cout << "The element at position " << i << " is " << integerVector.at(i) << endl;
    }
    cout << "Size of vector2 is " << integerVector2.GetSize() << endl;
    cout << "\nAfter removing element 3" << endl;

    integerVector2.Remove(3);
            for(int i = 0; i < integerVector2.GetSize(); i++)        // testing the Remove function
    {
        cout << "The element at position " << i << " is " << integerVector.at(i) << endl;
    }
    cout << "Size of vector is " << integerVector2.GetSize() << endl;


    cout << "The element at position 0 is " << integerVector2[0] << endl;       // testing overloaded [] operator

    Vector<int> integerVector3;
    integerVector3 = integerVector2;
    cout << "\n====== INTEGER VECTOR 3 ======" << endl;
    for(int i = 0; i < integerVector3.GetSize(); i++)        // testing the overloaded = operator
    {
        cout << "The element at position " << i << " is " << integerVector.at(i) << endl;
    }

    integerVector3.Clear();                                  // testing Clear() function
    cout << "\nProceeding to clear integerVector3....." << endl;
    cout << "Size of integerVector3 is now " << integerVector3.GetSize() <<endl;
    cout << "Capacity of integerVector3 is now " << integerVector3.GetAllocation() <<endl;

    return 0;
}
