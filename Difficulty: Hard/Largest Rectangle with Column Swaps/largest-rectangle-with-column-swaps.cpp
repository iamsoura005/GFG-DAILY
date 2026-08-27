class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;

        vector<vector<int>> hist(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            hist[0][j] = mat[0][j];
            for (int i = 1; i < n; ++i) {
                hist[i][j] = (mat[i][j] == 0) ? 0 : hist[i - 1][j] + 1;
            }
        }

        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> count(n + 1, 0);
            for (int j = 0; j < m; ++j) {
                count[hist[i][j]]++;
            }

            int curr_cols = 0;
            for (int h = n; h >= 1; --h) {
                curr_cols += count[h];
                max_area = max(max_area, h * curr_cols);
            }
        }

        return max_area;
    }
};