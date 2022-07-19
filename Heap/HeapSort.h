#include <vector>
#include <cstddef>

template<typename T>
class HeapSort {
public:
    HeapSort(std::vector<T>& arr): sz(arr.size()) {
        heapify(arr);
        for (size_t i = 0; i < arr.size(); ++i) {
            extractMax(arr);
        }
    }
private:
    size_t sz;
    void heapify(std::vector<T>& arr);
    void extractMax(std::vector<T>& arr);
    void SiftDown(std::vector<T>& arr, size_t i);
};

template<typename T>
void HeapSort<T>::heapify(std::vector<T>& arr) {
    for (size_t i = sz; i > 0; --i) {
        SiftDown(arr, i - 1);
    }
}

template<typename T>
void HeapSort<T>::extractMax(std::vector<T>& arr) {
    std::swap(arr[0], arr[--sz]);
    SiftDown(arr, 0);
}

template<typename T>
void HeapSort<T>::SiftDown(std::vector<T>& arr, size_t i) {
    while (2 * i + 1 < sz) {
        size_t u = 2 * i + 1;
        if (u + 1 < sz && arr[u + 1] > arr[u]) {
            u = u + 1;
        }
        if (arr[u] > arr[i]) {
            std::swap(arr[u], arr[i]);
            i = u;
        } else {
            break;
        }
    }
}
