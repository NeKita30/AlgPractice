#include <string>

template<typename T>
class Queue {
public:
    void push(T x);
    void pop();
    T front();
    size_t size();
    bool empty();
private:
    struct Node {
        T val;
        Node* next;
        Node(T v, Node* n): val(v), next(n) {}
    };
    Node* s = nullptr;
    Node* l = nullptr;
    size_t sz = 0;
};

template<typename T>
void Queue<T>::push(T x) {
    Node* n = new Node{x, nullptr};
    if (empty()) {
        s = n;
    } else {
        l->next = n;
    }
    l = n;
    ++sz;
}

template<typename T>
void Queue<T>::pop() {
    Node* n = s->next;
    delete s;
    s = n;
    --sz;
    if (sz == 0) {
        l = nullptr;
    }
}

template<typename T>
T Queue<T>::front() {
    return l->val;
}

template<typename T>
size_t Queue<T>::size() {
    return sz;
}

template<typename T>
bool Queue<T>::empty() {
    return sz == 0;
}
