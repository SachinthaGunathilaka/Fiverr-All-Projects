#include "LinkedList.cpp"

using namespace std;

// For testing
int main() {

    // Create object of LinkedList
    LinkedList<int> linkedList;

    // Add elements to the linked list
    linkedList.addItemToRear(10);
    linkedList.addItemToRear(20);
    linkedList.addItemToRear(30);
    linkedList.addItemToRear(40);

    // Call print function
    linkedList.print();


    return 0;
}
