#include <iostream>
using std::cout;

struct Node {
    int value;
    Node* next;
    Node(int val = 0) {
        value = val;
        next = nullptr;
    }
};
/*
Node* a;
(*a).value;
a->value;
*/

struct List {
private:
    Node* lst;
    int count;

    void remove(Node* node){
        if(!node) return;
        remove(node->next);
        delete node;
    }
public:
    List(): lst(nullptr), count(0) {}

    void push_front(int val) {
        Node* node = new Node(val);
        node->next = lst;
        lst = node;
        count++;
    }

    void pop_front() {
        if(lst == nullptr) return;
        Node* node = lst->next;
        delete lst;
        lst = node;
        count--;
    }

    void insert(Node* pos, int val) {
        if(pos == nullptr) return;
        Node* node = new Node(val);
        node->next = pos->next;
        pos->next = node;
        count++;
    }

    void erase(Node* pos) {
        if(!pos || !(pos->next)) return;

        Node* node = pos->next->next;
        delete pos->next;
        pos->next = node;
        count--;
    }

    Node* operator[](size_t i) {
        if(i >= count) return nullptr;
        Node* p = lst;
        for(; i > 0; i--) {
            p = p->next;
        }
        return p;
    }

    void print() {
        for(Node* p = lst; p != nullptr; p = p->next) {
            cout << p->value << ' ';
        }
        cout << '\n';
    }

    ~List() {
        remove(lst);
    }
};


int main() {
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.insert(l[3], 10);
    l.print();
}