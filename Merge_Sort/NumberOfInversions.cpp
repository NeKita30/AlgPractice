#include <iostream>
#include <vector>

template<typename T>
size_t Merge(std::vector<T>& A, const std::vector<T>& B,
        const std::vector<T>& C) {
    size_t number = 0;
    size_t a = 0;
    size_t b = 0;
    size_t c = 0;
    while (b < B.size() && c < C.size()) {
        if (B[b] <= C[c]) {
            A[a++] = B[b++];
            number += c;
        } else {
            A[a++] = C[c++];
        }
    }
    while (b < B.size()) {
        A[a++] = B[b++];
        number += c;
    }

    while (c < C.size()) {
        A[a++] = C[c++];
    }

    return number;
}

template<typename T>
size_t MergeSort(std::vector<T>& A) {
    if (A.size() == 1) {
        return 0;
    }
    size_t number = 0;
    auto begin = A.begin();
    auto end = A.end();
    std::vector<T> B(begin, begin + (end - begin) / 2);
    std::vector<T> C(begin + (end - begin) / 2, end);
    number += MergeSort<T>(B);
    number += MergeSort<T>(C);
    number += Merge<T>(A, B, C);
    return number;
}

int main() {
    std::vector<int> A{3, 2, 1};
    std::cout << MergeSort<int>(A);
}
