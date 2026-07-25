class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        int max_sum = INT_MIN;
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                int current_sum = pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k];
                max_sum = max(max_sum, current_sum);
            }
        }

        return max_sum;
    }
};