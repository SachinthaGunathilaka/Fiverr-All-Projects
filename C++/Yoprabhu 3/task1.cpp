#include <iostream>

template<typename T, size_t size1, size_t size2>

void TemplatedArrayCopy(T (&src)[size1], T (&dest)[size2]) {
    for (int i = 0; (i < size1 && i < size2); ++i) {
        dest[i] = src[i];
    }
}

int main() {
//    double source[] = {1, 2, 5, 6};
//    double dest[] = {9.4, 4, 5, 9};
//    double expected[] = {1, 2, 5, 6};
//    TemplatedArrayCopy(source, dest);
//    for (int i = 0; i < 4; ++i) {
//        ASSERT_EQ(expected[i], dest[i]);
//    }


//    int source[] = {1, 2};
//    int dest[] = {9, 4, 5};
//    int expected[] = {1, 2, 5};
//    TemplatedArrayCopy(source, dest);
//    for (int i = 0; i < 3; ++i) {
//        ASSERT_EQ(expected[i], dest[i]);
//    }
//
//    char source2[] = "ABC";
//    char dest2[] = "DEFGH";
//    char expected2[] = "ABC\0H";
//    TemplatedArrayCopy(source2, dest2);
//    for (int i = 0; i < 5; ++i) {
//        ASSERT_EQ(expected2[i], dest2[i]);
//    }
//
//    int source3[] = {1, 2, 3};
//    int dest3[] = {9, 4};
//    int expected3[] = {1, 2};
//    TemplatedArrayCopy(source3, dest3);
//    for (int i = 0; i < 2; ++i) {
//        ASSERT_EQ(expected3[i], dest3[i]);
//    }
    return 0;
}
