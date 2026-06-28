class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        // dp[i][j] stores the max dot product using first i elements of a and first j elements of b
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int j = 1; j <= m; j++) {
            for (int i = j; i <= n; i++) {
                // Choice 1: Match a[i-1] with b[j-1]
                int take = dp[i - 1][j - 1] + a[i - 1] * b[j - 1];
                
                // Choice 2: Skip a[i-1] (Insert 0 in array b)
                int skip = dp[i - 1][j];
                
                dp[i][j] = max(take, skip);
            }
        }
        
        return dp[n][m];
    }
};