#include <iostream>
#include <sstream>

void display(int data[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void selectionSort(int data[], int n) {
    int data_copy[n];
    for (int i = 0; i < n; ++i) {
        data_copy[i] = data[i];
    }
    display(data_copy, n);
    int i, j, select_index;
    for (i = 0; i < n - 1; i++) {
        select_index = i;
        for (j = i + 1; j < n; j++) {
            if (data_copy[j] < data_copy[select_index])
                select_index = j;
        }

        if (select_index != i) {
            int temp = data_copy[select_index];
            data_copy[select_index] = data_copy[i];
            data_copy[i] = temp;

            display(data_copy, n);
        }
    }
}

void insertionSort(int data[], int n) {
    int data_copy[n];
    for (int i = 0; i < n; ++i) {
        data_copy[i] = data[i];
    }

    display(data_copy, n);

    for (int i = 1; i < n; i++) {
        int temp = data_copy[i];
        int j = i - 1;
        while (j >= 0 && temp < data_copy[j]) {

            data_copy[j + 1] = data_copy[j];
            j = j - 1;
            data_copy[j + 1] = temp;
            display(data_copy, n);
        }
    }
}

void bubbleSort(int data[], int n) {
    int data_copy[n];
    for (int i = 0; i < n; ++i) {
        data_copy[i] = data[i];
    }

    display(data_copy, n);

    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++) {
            if (data_copy[j] > data_copy[j + 1]) {
                int temp = data_copy[j];
                data_copy[j] = data_copy[j + 1];
                data_copy[j + 1] = temp;

                display(data_copy, n);
            }
        }
}

int main() {
    int data[100];
    int n = 0, value;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream ss(input);

    while (ss >> value) {
        data[n++] = value;
    }

    std::cout << "Selection Sort" << std::endl;
    selectionSort(data, n);
    std::cout << "Insertion Sort" << std::endl;
    insertionSort(data, n);
    std::cout << "Bubble Sort" << std::endl;
    bubbleSort(data, n);
    return 0;
}