#include <iostream>

using namespace std;


// Function declarations
void print_array(const int [], int);

void initialize_array(int [], int n);

int *shuffle_array(const int [], int);

int *createOddArray(const int [], int, int &);

int *createEvenArray(const int [], int, int &);

void array_war(int *, int, int *, int);

void sort_array(int *, int);

// main function
int main() {

    // Get the size of the array from user
    int n;
    cout << "Please enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for array
    int * array = new int[n];

    // Initialize the array and display it
    initialize_array(array, n);
    cout << "\nOriginal array is: ";
    print_array(array, n);

    // Shuffle the array and display it
    int * shuffled_array = shuffle_array(array, n);
    cout << "\nShuffled array is: ";
    print_array(shuffled_array, n);


    int odd_array_size, even_array_size;

    // Create odd array and display it
    int * oddArray = createOddArray(shuffled_array, n, odd_array_size);
    cout << "\nAfter call to createOddArray, oddArray is: ";
    print_array(oddArray, odd_array_size);

    // Create even array and display it
    int * evenArray = createEvenArray(shuffled_array, n, even_array_size);
    cout << "\nAfter call to createEvenArray, evenArray is: ";
    print_array(evenArray, even_array_size);

    // Call array_war function
    array_war(evenArray, even_array_size, oddArray, odd_array_size);

    return 0;
}

// Function to initialize the array
void initialize_array(int array[], int n) {
    // Iterate through each integer from 0 to n
    for (int i = 0; i < n; ++i) {
        // Fill the array
        array[i] = i;
    }
}

// Function to print an array
void print_array(const int array[], int n) {
    cout << "[ ";

    // Iterate through each element in the array
    for (int i = 0; i < n; ++i) {
        // Display the current element
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

// Function to shuffle the array
int *shuffle_array(const int array[], int n) {
    srand(time(NULL));
    // Create new array to store the shuffled array
    int *shuffled_array = new int[n];

    // Copy array to shuffled array
    for (int i = 0; i < n; ++i) {
        shuffled_array[i] = array[i];
    }

    // Implement shuffling using the given algorithm
    for (int i = n - 1; i >= 1; --i) {
        int j = rand() % i;
        int temp = shuffled_array[j];
        shuffled_array[j] = shuffled_array[i];
        shuffled_array[i] = temp;
    }

    // Return the shuffled array
    return shuffled_array;

}


// Method to create an array with odd elements
int *createOddArray(const int array[], int n, int &size) {
    // Initialize size to 0
    size = 0;

    // Iterate through each element from the array
    for (int i = 0; i < n; ++i) {
        // If the element is odd
        if (array[i] % 2 == 1)
            // Increment the size by 1
            size++;
    }

    // Create array to hold the odd elements
    int *odd_array = new int[size];
    int j = 0;

    // Iterate through each element of the array
    for (int i = 0; i < n; ++i) {
        // If the current element is odd
        if (array[i] % 2 == 1) {
            // Add that element to the odd_array
            odd_array[j++] = array[i];
        }
    }

    // return off_array
    return odd_array;

}

// Method to create an array with even elements
int *createEvenArray(const int array[], int n, int &size) {
    // Initialize size to 0
    size = 0;

    // Iterate through each element from the array
    for (int i = 0; i < n; ++i) {
        // If the element is even
        if (array[i] % 2 == 0)
            // Increment the size by 1
            size++;
    }

    // Create array to hold the even elements
    int *even_array = new int[size];
    int j = 0;

    // Iterate through each element of the array
    for (int i = 0; i < n; ++i) {
        // If the current element is even
        if (array[i] % 2 == 0) {
            // Add that element to the even_array
            even_array[j++] = array[i];
        }
    }

    return even_array;
}

// array_war function
void array_war(int *array1, int n1, int *array2, int n2) {

    // Get the maximum length of 2 arrays
    int new_array_size = n1 > n2 ? n1 : n2;
    // Get minimum length of 2 arrays
    int shortest_len = n1 > n2 ? n2 : n1;

    // Create new array with the maximum length
    int *new_array = new int[new_array_size];

    // Add the largest element (By comparing corresponding elements) to the new_array
    for (int i = 0; i < shortest_len; ++i) {
        new_array[i] = array1[i] > array2[i] ? array1[i] : array2[i];
    }

    // If one array is not large enough, add elements of other array
    for (int i = shortest_len; i < new_array_size; ++i) {
        new_array[i] = n1 > n2 ? array1[i] : array2[i];
    }

    // Display new array
    cout << "\nArrayFight winners were: ";
    print_array(new_array, new_array_size);

    // Sort the new array
    sort_array(new_array, new_array_size);

    // Display sorted array
    cout << "\nSorted ArrayFight winners were: ";
    print_array(new_array, new_array_size);

}


// Function to sort the array using selection sort
void sort_array(int *array, int n) {
    int i, j, min_idx;

    // Iterate from i to n-1
    for (i = 0; i < n - 1; i++) {

        min_idx = i;

        // Find the minimum element from i+1 to n
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        // Swap minimum element with the element in 'i'th position
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}
