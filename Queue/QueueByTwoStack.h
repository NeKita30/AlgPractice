#include "Stack.h"

template<typename T>
class Queue {
private:
    Stack<T> add;
    Stack<T> del;
public:
    void push(T x);
    void pop();
    T front();
    T min();
    size_t size();
    bool empty();
};

template<typename T>
void Queue<T>::push(T x) {
    add.push(x);
}

template<typename T>
void Queue<T>::pop() {
    if (del.empty()) {
        while (!add.empty()) {
            T x = add.top();
            add.pop();
            del.push(x);
        }
    }
    del.pop();
}

template<typename T>
T Queue<T>::front() {
    if (del.empty()) {
        while (!add.empty()) {
            T x = add.top();
            add.pop();
            del.push(x);
        }
    }
    return del.top();
}


template<typename T>
T Queue<T>::min() {
    T minim;
    if (!add.empty()) {
        minim = add.min();
    }
    if (!del.empty()) {
        minim = del.min();
    }
    return minim;
}

template<typename T>
size_t Queue<T>::size() {
    return add.size() + del.size();
}

template<typename T>
bool Queue<T>::empty() {
    return add.empty() && del.empty();
}
