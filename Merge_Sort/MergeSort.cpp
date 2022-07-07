#include <iostream>
#include <vector>

template<typename T>
void Merge(std::vector<T>& A, const std::vector<T>& B,
        const std::vector<T>& C) {
    size_t a = 0;
    size_t b = 0;
    size_t c = 0;
    while (b < B.size() && c < C.size()) {
        if (B[b] < C[c]) {
            A[a++] = B[b++];
        } else {
            A[a++] = C[c++];
        }
    }
    while (b < B.size()) {
        A[a++] = B[b++];
    }
    while (c < C.size()) {
        A[a++] = C[c++];
    }
}

template<typename T>
void MergeSort(std::vector<T>& A) {
    if (A.size() == 1) {
        return;
    }
    auto begin = A.begin();
    auto end = A.end();
    std::vector<T> B(begin, begin + (end - begin) / 2);
    std::vector<T> C(begin + (end - begin) / 2, end);
    MergeSort<T>(B);
    MergeSort<T>(C);
    Merge<T>(A, B, C);
}


int main() {
    std::vector<int> A{1, 3, 100, 8, 20, -4, 91, 5, 6};
    MergeSort<int>(A);
    for (auto& i: A) {
        std::cout << i << ' ';
    }
}
