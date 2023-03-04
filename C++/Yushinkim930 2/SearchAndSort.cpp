#include "SearchAndSort.h"

// Linear Search Function
int SearchAndSort::linearSearch(vector<int> list, int target) {
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == target)
            return i;
    }

    return -1;
}

// Recursive binary Search Function
int SearchAndSort::recursiveBinarySearch(const vector<int> &list, int target) {
    return recursiveBinarySearch(list, target, 0, list.size() - 1);

}

// Recursive binary Search Helper Function
int SearchAndSort::recursiveBinarySearch(vector<int> list, int target, int low, int high) {

    int middle = (low + high + 1) / 2;

    if (low > high)
        return -1;

    if (target == list[middle])
        return middle;

    if (target < list[middle])
        return recursiveBinarySearch(list, target, low, (middle - 1));
    else
        return recursiveBinarySearch(list, target, (middle + 1), high);


}


// Selection sort function
void SearchAndSort::selectionSort(vector<int> &list) {
    int i, j, min_idx;

    for (i = 0; i < list.size() - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < list.size(); j++)
            if (list[j] < list[min_idx])
                min_idx = j;

        if (min_idx != i) {
            int temp = list[min_idx];
            list[min_idx] = list[i];
            list[i] = temp;
        }
    }
}


// Bubble sort function
void SearchAndSort::bubbleSort(vector<int> &list) {
    int i, j;
    for (i = 0; i < list.size() - 1; i++)
        for (j = 0; j < list.size() - i - 1; j++)
            if (list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
}
