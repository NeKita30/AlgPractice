#include <iostream>

template<typename T>
class Stack {
private:
    struct Node{
        Node(T v, Node* p): val(v), prev(p) {};
        T val;
        Node* prev;
    };
    Node* s = nullptr;
    size_t sz = 0;
public:
    void push(T x);
    void pop();
    T top();
    bool empty();
    size_t size();
};

template<typename T>
void Stack<T>::push(T x) {
    Node* n = new Node{x, s};
    s = n;
    ++sz;
}

template<typename T>
void Stack<T>::pop() {
    Node* n = s->prev;
    delete s;
    s = n;
    --sz;
}

template<typename T>
T Stack<T>::top() {
    return s->val;
}

template<typename T>
bool Stack<T>::empty() {
    return (s == nullptr);
}

template<typename T>
size_t Stack<T>::size() {
    return sz;
}

int main() {
    Stack<int> st;
    st.push(10);
    st.push(111);
    st.push(123);
    st.pop();
    if (!st.empty()) {
        std::cout << st.size();
        std::cout << st.top();
    }
}
