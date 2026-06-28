class Solution {
public:
    int countStrings(int n, int k) {
        // If k is greater than or equal to n, it's impossible to have k adjacent 1s
        if (k >= n) return 0;
        
        long long MOD = 1e9 + 7;
        
        // dp[i][j][0/1] -> length i, j adjacent 1s, ending with 0 or 1
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(2, 0)));
        
        // Base cases for length 1
        dp[1][0][0] = 1; // "0"
        dp[1][0][1] = 1; // "1"
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                // Ending with 0
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                
                // Ending with 1
                dp[i][j][1] = dp[i-1][j][0];
                if (j > 0) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][1]) % MOD;
                }
            }
        }
        
        return (dp[n][k][0] + dp[n][k][1]) % MOD;
    }
};