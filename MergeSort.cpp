#include <queue>
#include <iostream>
using std::cout;
using std::queue;

template<class T>
queue<T> merge(T* begin, T* end) {
    if(end - begin == 1) {
        queue<T> q;
        q.push(*begin);
        return q;
    }

    T* mid = begin + (end - begin)/2;

    queue<T>
        l = merge(begin, mid),
        r = merge(mid, end);
    queue<T> res;
    while(!l.empty() && !r.empty()) {
        if(l.front() < r.front()) {
            res.push(l.front());
            l.pop();
        } else {
            res.push(r.front());
            r.pop();
        }
    }

    while(!l.empty()) {
        res.push(l.front());
        l.pop();
    }
    while(!r.empty()) {
        res.push(r.front());
        r.pop();
    }
    return res;
}

template<class T>
void MergeSort(T* begin, T* end) {
    auto res = merge(begin, end);
    for(T* p = begin; p != end; p++) {
        *p = res.front();
        res.pop();
    }
}


int main() {
    int mas[8] = {5, 3, 7, 1, 0, 2, 4, 8};
    MergeSort(mas, mas + 8);
    for(auto v: mas) {
        cout << v << '\n';
    }
}