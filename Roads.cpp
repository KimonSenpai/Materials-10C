#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int A(0), B(t);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A += a;
        B = min(A + t, B + b);
    }
    cout << B;
}