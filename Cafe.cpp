#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> c(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(ceil(N/2.0) + 1));

    dp[0][0] = 0;
    for(int i = 1; i < dp[0].size(); i++) {
        dp[0][i] = 100000000;
    }
    for(int i = 1; i <= N; i++) {
        dp[i][0] = dp[i-1][1];
        if(c[i] < 100 && dp[i][0] > dp[i-1][0] + c[i])
            dp[i][0] = dp[i-1][0] + c[i];
        for(int j = 1; j < dp[i].size(); j++) {
            if(c[i] < 100) {
                dp[i][j] = min(dp[i-1][j+1], dp[i-1][j] + c[i]);
            } else {
                dp[i][j] = min(dp[i-1][j+1], dp[i-1][j-1] + c[i]);
            }
        }
    }
    cout << min(dp[N][0], dp[N][1]);

    int j = dp[N][0] < dp[N][1] ? 0 : 1;
    vector<int> ans;
    for(int i = N; i > 0; i--) {
        if(dp[i][j] == dp[i-1][j+1])
            ans.push_back(i);
        
    }

}