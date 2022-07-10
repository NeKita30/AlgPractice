#include <ctime>
#include <vector>

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
void QuickSort(std::vector<T>& A) {
    if (A.size() <= 1) {
        return;
    }
    size_t x = rand() % A.size();
    std::vector<T> B;
    std::vector<T> C;
    std::vector<T> D;
    Partition<T>(A, B, C, D, A[x]);
    QuickSort<T>(B);
    QuickSort<T>(D);
    A.clear();
    A.insert(A.begin(), B.begin(), B.end());
    A.insert(A.end(), C.begin(), C.end());
    A.insert(A.end(), D.begin(), D.end());
}
