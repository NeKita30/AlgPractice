#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void Partition(std::vector<T>& A, std::vector<T>& B, std::vector<T>& C, std::vector<T>& D, T& x) {
    for (auto& a: A) {
        if (a < x) {
            B.push_back(a);
        } else if (a > x) {
            D.push_back(a);
        } else {
            C.push_back(a);
        }
    }
}

template<typename T>
T find_median_of_five(std::vector<T>& fives) {
    auto b = fives.begin();
    auto e = fives.end();
    std::sort(b, e);
    return fives[fives.size() / 2];
}

template<typename T>
void make_vector_of_medians(const std::vector<T>& A, std::vector<T>& B) {
    auto it = A.begin();
    while (it != A.end()) {
        auto it_end = A.end();
        if ((it + 5) - A.begin() <= A.size()) {
            it_end = it + 5;
        }
        std::vector<T> fives(it, it_end);
        B.push_back(find_median_of_five(fives));
        it = it_end;
    }
}

template<typename T>
T kth(std::vector<T>& A, size_t k) {
    if (A.size() == 1) {
        return A[0];
    }
    std::vector<T> M;
    make_vector_of_medians<T>(A, M);
    T m = kth<T>(M, A.size() / 10);
    std::vector<T> B;
    std::vector<T> C;
    std::vector<T> D;
    Partition<T>(A, B, C, D, m);
    if (k < B.size()) {
        return kth(B, k);
    }
    if (k < B.size() + C.size()) {
        return m;
    }
    return kth(D, k - B.size() - C.size());
}

template<typename T>
void QuickSort(std::vector<T>& A) {
    if (A.size() <= 1) {
        return;
    }
    T m = kth(A, A.size() / 2);
    std::vector<T> B;
    std::vector<T> C;
    std::vector<T> D;
    Partition<T>(A, B, C, D, m);
    QuickSort(B);
    QuickSort(D);
    A.clear();
    A.insert(A.begin(), B.begin(), B.end());
    A.insert(A.end(), C.begin(), C.end());
    A.insert(A.end(), D.begin(), D.end());
}

int main() {
    std::vector<int> v{4, 3, 7, 6, 10, 0, 25, 15, 14, 8, -1, 13, 1, 20, -10, 22, 11};
    QuickSort<int>(v);
    for (auto& x: v) {
        std::cout << x << ' ';
    }
}
