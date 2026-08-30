class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        if (n <= 0) return 0;
        if (n == 1) return i;

        vector<long long> dp(n + 1, 0);
        dp[1] = i;

        for (int j = 2; j <= n; ++j) {
            if (j % 2 == 0) {
                dp[j] = min(dp[j - 1] + i, dp[j / 2] + c);
            } else {
                dp[j] = min(dp[j - 1] + i, dp[(j + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};