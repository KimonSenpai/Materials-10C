#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

int main() {
    ifstream in("27.txt");
    int n;
    cin >> n;
    vector<ull> prefs(11, 100000000000000);
    int pref = 0, maxSum = -1;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pref += val;
        maxSum = max(maxSum, pref - prefs[pref%11]);
        prefs[pref%11] = min(prefs[pref%11], pref);
    }

    cout << maxSum << '\n';
}