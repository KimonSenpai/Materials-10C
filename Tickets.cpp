#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1), B(N + 1), C(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<int> dp(N+1);
    dp[0] = 0;
    dp[1] = A[1];
    dp[2] = min(B[1], A[2] + dp[1]);

    for(int i = 3; i <= N; i++) {
        dp[i] = min({A[i] + dp[i-1], B[i-1] + dp[i-2], C[i-2] + dp[i-3]});
    }

    cout << dp[N];
}