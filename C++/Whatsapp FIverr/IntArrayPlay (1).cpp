/* Working with arrays and functions
 * Author:
 * Last modified on:
 * Known bug
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int CAPACITY=20;
extern int No_of_elements=0;

// displayArray -  display the array on a single line separated by blanks.
// @param: int array[] is an array of integers
// @param: int numberOfElements
void displayArray(int array[],int numElements){


    // For loop to go through all elements in the array
	for (int i = 0; i < numElements; i++)
		cout << array[i] << " ";

	cout << endl;





}


//ToDo: Declare a function fillArray that fills an int array with values entered
//by the user. Stop reading when the user inputs -1 or you reach CAPACITY.
// fillArray - read a list of positive integers ending with -1 or until CAPACITY
// @param: int array[] is an array of integers when leaving this function
// @param: int& numElements is the number of Elements in the array when done
// @returns void.
void fillArray(int array[], int numElements ){
  int element; // Each user inserted element

	cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;

	// For loop to get all user entered values for the array. Can go up to 20 values can be entered because that is the capacity of the array.
	for (int i = 0; i < CAPACITY; i++)
	{
		cin >> element;

		// If statement to get the array to only be filled with positive integers
		if (element < -1)
		{
			numElements--;
			continue; // Breaks any negative iterations of the loop
		}

		// If statement to stop reading elements into the array if the user inputs -1
		else if (element == -1)
		{
                        numElements--;
			break; // Jumps out of the for loop
		}

		else
		{
			// Copies the user input value into the array if all conditions are met
			array[i] = element;
			numElements += 1;
		}
	}
        No_of_elements=numElements;
  }








//ToDo: Declare a function isArraySorted that determines if an array is in order
// isArraySorted - goes thru the elements checking to see if they are in order
// @param: int array[] is an array
// @param: int numElements
// @returns: true if the array is in sorted order, false otherwise

bool isArraySorted(int arr[], int numElements)
{
    // Array has one or no element or the
    // rest are already checked and approved.
    if (numElements == 1 ||  numElements == 0)
        return true;

    // Unsorted pair found (Equal values allowed)
    if (arr[numElements - 1] < arr[numElements - 2])
        return false;

    // Last pair was sorted
    // Keep on checking
    return isArraySorted(arr, numElements - 1);
}

//ToDo: Declare a function that finds the insert position for a given value
//in an ordered array.
// findPosition - looks thru an ordered array to find the position of
// the value to insert. All values before are less than the target value.
// Value after should be greater than the target value. [No need to sort]
// @param: int array[] is an ordered array
// @param: int numElements
// @param: int value to insert
// @return index of the position where the element should be inserted

int findPosition(int arr[], int numElements, int value)
{
    // Traverse the array
    for (int i = 0; i < numElements; i++)

        // If K is found
        if (arr[i] == value)
            return i;

        // If current array element
        // exceeds K
        else if (arr[i] > value)
            return i;

    // If all elements are smaller
    // than K
    return numElements;
}

//ToDo: Declare a funcxtion that searches for an element in the given array
// searchElement - searches for the element in the given array.
// @param int array[] is an unordered array of integers
// @param int numberOfElements
// @param int element
// @returns index of element or -1 if not found.

int searchElement(int arr[], int numberOfElements, int element) {

    int i;
    for (i = 0; i < numberOfElements; i++)
        if (arr[i] == element)
            return i;
    return -1;


}

//ToDo: Declare a function that removes (i.e., deletes) the element
// removeElement - removes the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int&amp; numberElements
// @param: int position of element to delete
// @returns: true if delete was successful, false otherwise

bool removeElement(int arr[], int &amp, int position)
{
    if (position<amp){
            for(int i=position;i<amp;i++){
                    arr[i]=arr[i+1];

            }
        return true;
    }
    else{
        return false;
    }

}

//ToDo: Delcare a function that inserts the target element in the given position
// insertElement - removes the element of the given index from the given array.
// @param: int array[] is an ordered array of integers
// @param: int &numElements
// @param: int position to insert into
// @param: int target to insert.
// @returns: true if insert was successful, false otherwise

bool insertElement (int arr[], int &numElements, int position,int target){
        int temp;
    if(position<numElements){
        arr[position]=temp;
        temp=target;
        arr[position]=temp;
        return true;
    }
    else{
        return false;
    }

}




int main()
{
   // The numArray can be partially filled, we use the variable numArrayElems
   // to keep track of how many numbers have been stored in the array.
   int numArray[CAPACITY];	// an int array with a given CAPACITY
   int numArrayElems=0;     // the array is initially empty, i.e., contains 0 elements
   // 1. ToDo: Call your fillArray function to read in a sequence of integer values,
   // separated by space, and ending with -1. Store the values in the numArray array
   // and the number of elements in numArrayElems.
   // Display the content of the array afterwards
    // an int array with a given CAPACITY
    // number of elements in the array. the array is initially empty, i.e., contains 0 elements
	int element, position;
	bool isSorted, isInserted, isRemoved;

	// 1. ToDo: Call your fillArray function to read in a sequence of integer values, separated by space, and ending with -1. Store the values in the numArray array and the number of elements in numArrayElems.
	fillArray(numArray, numArrayElems);
    numArrayElems=No_of_elements;
	// Display the contents of the array afterwards
	displayArray(numArray, numArrayElems);

	// 2. ToDo: Read in a value from the user. Call your findPosition function to get the position to insert, then call insertElement to insert the value into the position of the array.
	cout << "Enter a value to insert: ";
	cin >> element;
	position = findPosition(numArray, numArrayElems, element);
     cout<< " No 2 Ans: Position of the value "<< position;
	isInserted = insertElement (numArray, numArrayElems, position, element);

	if (!isInserted)
		cout << "Error: array is full" << endl;


	// 3. ToDo: Use your isArraySorted function to tell whether the array is sorted.
	isSorted = isArraySorted (numArray, numArrayElems);

	if (isSorted)
		cout << "Array is sorted" << endl;
	else
		cout << "Array is not sorted" << endl;





	// 4. ToDo: Read in a value from the user. Call your searchElement function to get the position to remove, then call removeElement to delete it.
	cout << "Enter a value to remove: ";
	cin >> element;

	position = searchElement (numArray, numArrayElems, element);
	isRemoved = removeElement (numArray, numArrayElems, position);

	if (!isRemoved)
		cout << "Error: position out of range: " << position << endl;
	// Display the content of the array afterwards
	displayArray (numArray, numArrayElems);




   return 0;
}

//TODO: Implement all functions declared above.
//Don't forget to put precondition/postcondition comments under or over the function header.


