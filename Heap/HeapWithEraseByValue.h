#include "Heap.h"

template<typename T>
class EHeap {
public:
     void insert(T& x);
     void insert(T&& x);
     T getMin();
     void extractMin();
     void decreaseKeyByTime(size_t t, T& delta);
     void decreaseKeyByTime(size_t t, T&& delta);
     void erase(T& x);
     void erase(T&& x);
     size_t size();
private:
     Heap<T> A;
     Heap<T> D;
};

template<typename T>
void EHeap<T>::insert(T& x) {
    A.insert(x);
}

template<typename T>
void EHeap<T>::insert(T&& x) {
    A.insert(x);
}

template<typename T>
T EHeap<T>::getMin() {
    while (D.size() > 0 && A.getMin() == D.getMin()) {
        A.extractMin();
        D.extractMin();
    }
    return A.getMin();
}

template<typename T>
void EHeap<T>::extractMin() {
    while (D.size() > 0 && A.getMin() == D.getMin()) {
        A.extractMin();
        D.extractMin();
    }
    A.extractMin();
}

template<typename T>
void EHeap<T>::decreaseKeyByTime(size_t t, T& delta) {
    A.decreaseKeyByTime(t, delta);
}

template<typename T>
void EHeap<T>::decreaseKeyByTime(size_t t, T&& delta) {
    A.decreaseKeyByTime(t, delta);
}

template<typename T>
void EHeap<T>::erase(T& x) {
    D.insert(x);
}

template<typename T>
void EHeap<T>::erase(T&& x) {
    D.insert(x);
}

template<typename T>
size_t EHeap<T>::size() {
    return A.size() - D.size();
}
