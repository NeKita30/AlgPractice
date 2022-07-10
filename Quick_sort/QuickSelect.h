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
T QuickSelect(std::vector<T>& A, size_t k) {
    if (A.size() == 1) {
        return A[0];
    }
    size_t x = rand() % A.size();
    std::vector<T> B;
    std::vector<T> C;
    std::vector<T> D;
    Partition<T>(A, B, C, D, A[x]);
    
    if (k < B.size()) {
        return QuickSelect(B, k);
    }
    if (k < B.size() + C.size()) {
        return A[x];
    }
    return QuickSelect(D, k - B.size() - C.size());
}
