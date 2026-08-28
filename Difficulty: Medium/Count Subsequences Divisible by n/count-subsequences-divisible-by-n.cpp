class Solution {
public:
    int countSubsequences(string& s, int n) {
        int MOD = 1e9 + 7;
        vector<int> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';
            vector<int> next_dp = dp;

            for (int r = 0; r < n; ++r) {
                if (dp[r] > 0) {
                    int next_rem = (r * 10 + digit) % n;
                    next_dp[next_rem] = (next_dp[next_rem] + dp[r]) % MOD;
                }
            }

            int self_rem = digit % n;
            next_dp[self_rem] = (next_dp[self_rem] + 1) % MOD;

            dp = move(next_dp);
        }

        return dp[0];
    }
};