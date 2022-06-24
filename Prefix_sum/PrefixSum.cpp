#include <iostream>
#include <vector>

template<typename T>
std::vector<T> make_pref_sums(const std::vector<T>& vector,
        T (*func)(const T&, const T&)) {
    std::vector<T> sums;
    sums.push_back(vector[0]);
    size_t sz = vector.size();
    for (size_t i = 1; i < sz; ++i) {
        sums.push_back(func(sums[i - 1], vector[i]));
    }
    return sums;
}

template<typename T>
T get_sum(size_t L, size_t R, const std::vector<T>& sums,
        T (*arc_func)(const T&, const T&)) {
    if (L == 0) {
        return sums[R];
    }
    return arc_func(sums[R], sums[L - 1]);
}

int sum(const int& a, const int& b) {
    return a + b;
}

int arc_sum(const int& a, const int& b) {
    return a - b;
}

int main() {
    std::vector<int> arr{1, 4, 2, 1, 5, 2, 1, 6, 3, 2};
    int (*func)(const int&, const int&) = sum;
    int (*arc_func)(const int&, const int&) = arc_sum;
    std::cout << get_sum<int>(0, 8, make_pref_sums<int>(arr, sum), arc_sum);
}
