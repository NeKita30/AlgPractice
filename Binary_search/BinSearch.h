#include <vector>

template<class T>
size_t bin_search(const T& val,
        const std::vector<T>& list) {
    size_t L = 0;
    size_t R = list.size();
    while (R - L > 1) {
        size_t M = (R + L) / 2;
        if (list[M] == val) {
            return M;
        }
        if (list[M] > val) {
            R = M;
        } else {
            L = M;
        }
    }
    if (list[L] == val) {
        return L;
    }
    return list.size();
}
