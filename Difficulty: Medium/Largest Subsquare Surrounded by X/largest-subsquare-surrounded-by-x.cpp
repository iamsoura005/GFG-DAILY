class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // left[i][j] stores consecutive 'X's ending at (i, j) in the row
        // top[i][j] stores consecutive 'X's ending at (i, j) in the column
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> top(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'X') {
                    left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                    top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;
                }
            }
        }

        int max_len = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int small = min(left[i][j], top[i][j]);
                while (small > max_len) {
                    if (top[i][j - small + 1] >= small && left[i - small + 1][j] >= small) {
                        max_len = small;
                        break;
                    }
                    small--;
                }
            }
        }

        return max_len;
    }
};