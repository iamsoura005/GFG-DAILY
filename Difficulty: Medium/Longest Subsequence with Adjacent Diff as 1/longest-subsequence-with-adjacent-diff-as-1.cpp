class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        unordered_map<int, int> dp;
        int max_len = 0;

        for (int x : arr) {
            int len1 = dp.count(x - 1) ? dp[x - 1] : 0;
            int len2 = dp.count(x + 1) ? dp[x + 1] : 0;

            dp[x] = max(dp[x], 1 + max(len1, len2));
            max_len = max(max_len, dp[x]);
        }

        return max_len;
    }
};