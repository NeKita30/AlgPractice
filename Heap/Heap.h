#include <vector>
#include <climits>
#include <cstddef>

template<typename T>
class Heap {
public:
    Heap() = default;
    Heap(std::vector<T>& a);

    void insert(T& x);
    void insert(T&& x);
    T getMin();
    void extractMin();
    void decreaseKey(size_t v, T& delta);
    void decreaseKey(size_t v, T&& delta);
    void decreaseKeyByTime(size_t t, T& delta);
    void decreaseKeyByTime(size_t t, T&& delta);
    void erase(size_t t);
    size_t size();

    std::vector<size_t> ptr;
    std::vector<size_t> num;
private:
    size_t sz = 0;
    std::vector<T> arr;

    void heapify();
    void SiftUp(size_t v);
    void SiftDown(size_t v);
    void exchange(size_t v, size_t u);
};

template<typename T>
size_t Heap<T>::size() {
    return sz;
}

template<typename T>
Heap<T>::Heap(std::vector<T>& a): ptr(0, sz), num(0, sz),
    sz(a.size()), arr(a) {
    heapify();
}

template<typename T>
void Heap<T>::SiftUp(size_t v) {
    while (v != 0) {
        size_t p = (v - 1) / 2;
        if (arr[v] < arr[p]) {
            exchange(v, p);
            v = p;
        } else {
            break;
        }
    }
}

template<typename T>
void Heap<T>::SiftDown(size_t v) {
    while (2 * v + 1 < sz) {
        size_t u = 2 * v + 1;
        if ((u + 1 < sz) && (arr[u + 1] < arr[u])) {
            u = u + 1;
        }
        if (arr[v] > arr[u]) {
            exchange(v, u);
            v = u;
        } else {
            break;
        }
    }
}

template<typename T>
void Heap<T>::exchange(size_t v, size_t u) {
    size_t k = num[u];
    size_t m = num[v];
    std::swap(num[u], num[v]);
    std::swap(ptr[k], ptr[m]);
    std::swap(arr[u], arr[v]);
}

template<typename T>
T Heap<T>::getMin() {
    return arr[0];
}

template<typename T>
void Heap<T>::decreaseKey(size_t v, T& delta) {
    arr[v] -= delta;
    SiftUp(v);
}

template<typename T>
void Heap<T>::decreaseKey(size_t v, T&& delta) {
    arr[v] -= delta;
    SiftUp(v);
}

template<typename T>
void Heap<T>::decreaseKeyByTime(size_t t, T& delta) {
    arr[ptr[t]] -= delta;
    SiftUp(ptr[t]);
}

template<typename T>
void Heap<T>::decreaseKeyByTime(size_t t, T&& delta) {
    arr[ptr[t]] -= delta;
    SiftUp(ptr[t]);
}

template<typename T>
void Heap<T>::insert(T& x) {
    arr.push_back(x);
    num.push_back(ptr.size());
    ptr.push_back(sz);
    SiftUp(sz);
    ++sz;
}

template<typename T>
void Heap<T>::insert(T&& x) {
    arr.push_back(x);
    num.push_back(ptr.size());
    ptr.push_back(sz);
    SiftUp(sz);
    ++sz;
}

template<typename T>
void Heap<T>::extractMin() {
    exchange(0, --sz);
    ptr[num[sz]] = INT_MAX;
    num.pop_back();
    arr.pop_back();
    SiftDown(0);
}

template<typename T>
void Heap<T>::erase(size_t t) {
    size_t z = num[--sz];
    exchange(ptr[t], sz);
    ptr[num[sz]] = INT_MAX;
    num.pop_back();
    arr.pop_back();
    SiftUp(ptr[z]);
    SiftDown(ptr[z]);
}


template<typename T>
void Heap<T>::heapify() {
    for (size_t i = sz; i >= 1; --i) {
        SiftDown(i - 1);
    }
}
