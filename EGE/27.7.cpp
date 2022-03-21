#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    for (auto file : {"D:\\Downloads\\27A.txt", "D:\\Downloads\\27B.txt"}) {
        ifstream in(file);
        long long n, a, ans = 1e9;
        in >> n;
        vector<long long> v(144, 1e6);
        for (int i = 0; i < n; ++i) {
            in >> a;
            ans = min(ans, a + v[(144 - a % 144) % 144]);
            v[a % 144] = min(a, v[a % 144]);
        }

        cout << ans << '\n';
    }
    return 0;
}