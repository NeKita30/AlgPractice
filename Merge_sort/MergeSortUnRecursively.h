// #include "Queue.h"
#include "QueueByTwoStack.h"
// #include <queue>
#include <vector>
#include <iostream>

template<typename T>
std::vector<T> Merge(std::vector<T>& B, std::vector<T>& C) {
    std::vector<T> A;
    size_t b = 0;
    size_t c = 0;
    while (b < B.size() && c < C.size()) {
        if (B[b] < C[c]) {
            A.push_back(B[b++]);
        } else {
            A.push_back(C[c++]);
        }
    }
    while (b < B.size()) {
        A.push_back(B[b++]);
    }
    while (c < C.size()) {
        A.push_back(C[c++]);
    }
    return A;
}

template<typename T>
void MergeSort(std::vector<T>& A) {
    Queue<std::vector<T>> q;
    // std::queue<std::vector<T>> q;
    for (auto& x: A) {
        q.push(std::vector<T>{x});
    }
    while (q.size() > 1) {
        auto v_b = q.front();
        q.pop();
        auto v_c = q.front();
        q.pop();
        auto v_a = Merge<T>(v_b, v_c);
        q.push(v_a);
    }
    A = q.front();
}
