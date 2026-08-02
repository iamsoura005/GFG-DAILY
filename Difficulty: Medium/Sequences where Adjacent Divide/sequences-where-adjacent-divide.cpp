class Solution {
  public:
    int count(int n, int m) {
        vector<vector<int>> adj(m + 1);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i % j == 0 || j % i == 0) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> dp(m + 1, 1);

        for (int len = 2; len <= n; ++len) {
            vector<int> next_dp(m + 1, 0);
            for (int i = 1; i <= m; ++i) {
                for (int prev : adj[i]) {
                    next_dp[i] += dp[prev];
                }
            }
            dp = next_dp;
        }

        int total_count = 0;
        for (int i = 1; i <= m; ++i) {
            total_count += dp[i];
        }

        return total_count;
    }
};