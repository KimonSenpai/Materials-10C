#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(ceil(N/2 + 1)));
    dp[0][0] = 0;
    for(int i = 1; i < dp[0].size(); i++) 
        dp[0][i] = 1e9;
    
    for(int d = 1; d <= N; d++) {
        dp[d][0] = dp[d-1][1];
        if(A[d] < 100 && dp[d][0] > dp[d-1][0] + A[d])
            dp[d][0] = dp[d-1][0] + A[d];
        
        for(int k = 1; k < dp[d].size() - 1; k++) {
            if(A[d] < 100)
                dp[d][k] = min(dp[d-1][k+1], dp[d-1][k] + A[d]);
            else
                dp[d][k] = min(dp[d-1][k+1], dp[d-1][k-1] + A[d]);
        }
        dp[d][dp[d].size() - 1] = 1e9;
    }
    int k;
    if(dp[N][0] < dp[N][1]) {
        k = 0;
    } else {
        k = 1;
    }

    cout << dp[N][k] << '\n' << k << '\n';

    int d = N;
    vector<int> res;
    while(d > 0) {
        if(dp[d][k] == dp[d-1][k+1]) {
            res.push_back(d);
            d--;
            k++;
        } else {
            if(A[d] < 100) {
                d--;
            } else {
                d--;
                k--;
            }
        }
    }

    reverse(begin(res), end(res));
    for(int a: res) {
        cout << a << ' ';
    }
    cout << '\n';

}