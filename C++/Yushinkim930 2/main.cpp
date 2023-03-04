#include <iostream>
#include "SearchAndSort.h"
#include <chrono>

using namespace std;

// Function to display a vector
void displayVector(const vector<int> &list) {
    for (int number: list) {
        cout << number << " ";
    }
    cout << endl;
}


// Function to fill vector with random values
void fillVector(vector<int> &list, int n) {
    list.clear();

    for (int i = 0; i < n; ++i) {
        list.push_back(1 + rand() % (n * 10));
    }
}

// Main function
int main() {
    int n;
    int number;
    srand(time(0));
    SearchAndSort searchandsort;
    vector<int> list1;


    cout << "Enter number of values: ";
    cin >> n;


    // Test linear search
    cout << "\n-------------------Linear Search-------------------" << endl;

    // Create random array of data
    fillVector(list1, n);

    displayVector(list1);
    cout << endl;

    // Get user input
    cout << "Enter number to search for: ";
    cin >> number;

    // Calculate and show execution times and search results
    auto start = std::chrono::high_resolution_clock::now();
    int position = searchandsort.linearSearch(list1, number);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Found in position: " << position << endl;
    cout << "Time taken by Linear Search: " << duration.count() << " microseconds" << endl;


    // ---------------------------------------------------------------------------------------
    // Test recursive binary search
    cout << "\n-------------------Recursive Binary Search-------------------" << endl;

    // Create random array of data
    fillVector(list1, n);
    searchandsort.bubbleSort(list1);
    displayVector(list1);


    // Get user input
    cout << "Enter number to search for: ";
    cin >> number;

    // Calculate and show execution times and search results
    start = std::chrono::high_resolution_clock::now();
    position = searchandsort.recursiveBinarySearch(list1, number);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Found in position: " << position << endl;
    cout << "Time taken by Recursive Binary Search: " << duration.count() << " microseconds" << endl;


    // ---------------------------------------------------------------------------------------
    // Test bubble sort
    cout << "\n-------------------Bubble Sort-------------------" << endl;

    cout << "Before: ";
    fillVector(list1, n);
    displayVector(list1);


    // Calculate and show execution times and search results
    start = std::chrono::high_resolution_clock::now();
    searchandsort.bubbleSort(list1);
    stop = std::chrono::high_resolution_clock::now();

    cout << "After: ";
    displayVector(list1);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by Bubble Sort:  " << duration.count() << " microseconds" << endl;


    // ---------------------------------------------------------------------------------------
    // Test Selection sort
    cout << "\n-------------------Selection Sort-------------------" << endl;

    cout << "Before: ";
    fillVector(list1, n);
    displayVector(list1);


    // Calculate and show execution times and search results
    start = std::chrono::high_resolution_clock::now();
    searchandsort.selectionSort(list1);
    stop = std::chrono::high_resolution_clock::now();

    cout << "After: ";
    displayVector(list1);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by Selection Sort:  " << duration.count() << " microseconds" << endl;


    return 0;
}
