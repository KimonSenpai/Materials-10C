#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n + 1), B(n + 1), C(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = A[1];
    dp[2] = min(B[1], A[1] + A[2]);

    for(int i = 3; i <= n; i++) {
        dp[i] = min({   A[i] + dp[i - 1], 
                        B[i - 1] + dp[i - 2],
                        C[i - 2] + dp[i - 3]
                    });
    }
    cout << dp[n] << '\n';
}