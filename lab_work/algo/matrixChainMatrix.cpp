#include<iostream>
#include <climits>
#include <vector>

using namespace std;

//matrix chain multiplication using dp table
int matrixChainOrder(vector<int> p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }
    return dp[1][n - 1];
}


int main() {
    vector<int> p = {1, 2, 3, 4};
    cout << matrixChainOrder(p) << endl;
    return 0;
}