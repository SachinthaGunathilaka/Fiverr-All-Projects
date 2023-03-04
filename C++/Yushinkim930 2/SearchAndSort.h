#ifndef SEARCHANDSORT_H
#define SEARCHANDSORT_H

#include<vector>

using namespace std;
class SearchAndSort {
public:
    int linearSearch(vector<int> list, int target);

    int recursiveBinarySearch(const vector<int>& list, int target);

    int recursiveBinarySearch(vector<int> list, int target, int low, int high);

    void selectionSort(vector<int> & list);

    void bubbleSort(vector<int> & list);


};


#endif
