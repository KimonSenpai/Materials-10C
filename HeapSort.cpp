#include <iostream>
using namespace std;

void PushHeap(int* mas, int& n, int val) {
    mas[n] = val;
    n++;
    int i = n - 1;
    while (i != 0) {
        if (mas[i] < mas[(i + 1) / 2 - 1]) {
            swap(mas[i], mas[(i + 1) / 2 - 1]);
            i = (i + 1) / 2 - 1;
        } else {
            break;
        }
    }
}

int PopHeap(int* mas, int& n) {
    int v = mas[0];
    mas[0] = mas[n - 1];
    n--;
    int i = 0;
    while (true) {
        int 
            l = 2 * i + 1, 
            r = 2 * i + 2;

            
        if (l >= n) break;
        if (r >= n) {
            if (mas[i] > mas[l]) swap(mas[i], mas[l]);
            break;
        }
        if (mas[l] > mas[r]) swap(l, r);

        if (mas[i] > mas[l]) {
            swap(mas[i], mas[l]);
            i = l;
        } else {
            break;
        }
    }
    return v;
}

void HeapSort(int* beg, int* end) {
    int n = end - beg;
    int* heap = new int[n];
    int count = 0;
    for (int* p = beg; p < end; p++) {
        PushHeap(heap, count, *p);
    }
    for (int* p = beg; p < end; p++) {
        *p = PopHeap(heap, count);
    }
}

int main() {
    int mas[10] = {5, 3, 7, 1, 9, 2, 4, 8, 6, 0};
    for (int v : mas) cout << v << ' ';
    cout << '\n';
    HeapSort(mas, mas + 10);
    for (int v : mas) cout << v << ' ';
    cout << '\n';
}