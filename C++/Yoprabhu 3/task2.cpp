#include<iostream>
#include<vector>

template <typename T>
std::vector<T> ArrayToVector(T * arr, int size){
    std::vector<T> result;
    for (int i = 0; i < size; ++i) {
        result.push_back(arr[i]);
    }

    free(arr);

    return result;
}



//int main(){
//    int size = 1;
//    int * array = new int[size];
//    array[0] = 8;
//
//    std::vector<int> result = ArrayToVector(array, size);
//    ASSERT_EQ(result.size(), 1);
//    ASSERT_EQ(result.at(0), 8);

//    int size = 4;
//    char * const array = new char[size];
//    array[0] = '8';
//    array[1] = '1';
//    array[2] = 'd';
//    array[3] = '!';
//
//    std::vector<char> result = ArrayToVector<char>(array, 3);
//    ASSERT_EQ(result.size(), 3);
//    ASSERT_EQ(result.at(2), 'd');
//    ASSERT_EQ(result.at(0), '8');
//
//    return 0;
//}