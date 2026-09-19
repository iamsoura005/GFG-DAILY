class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int prev = dp[0];
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        int lcs = dp[m];
        return (n - lcs) * costS1 + (m - lcs) * costS2;
    }
};