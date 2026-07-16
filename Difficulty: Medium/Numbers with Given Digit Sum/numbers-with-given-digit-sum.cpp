class Solution {
public:
    int countWays(int n, int sum) {
        if (sum < 1 || sum > 9 * n) {
            return -1;
        }

        // dp[i][j] stores the count of i-digit numbers with digit sum equal to j
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // For 1 digit, numbers 1-9 can form sums 1-9
        for (int j = 1; j <= 9 && j <= sum; ++j) {
            dp[1][j] = 1;
        }

        // Fill DP table for length 2 to n
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                for (int digit = 0; digit <= 9; ++digit) {
                    if (j - digit >= 1) {
                        dp[i][j] += dp[i - 1][j - digit];
                    }
                }
            }
        }

        return dp[n][sum] == 0 ? -1 : dp[n][sum];
    }
};