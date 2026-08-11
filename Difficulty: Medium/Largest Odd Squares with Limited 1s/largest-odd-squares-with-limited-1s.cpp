class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int r = q[0];
            int c = q[1];

            int max_rad = min({r, c, n - 1 - r, m - 1 - c});
            int low = 0, high = max_rad;
            int best_rad = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int ones = getSum(r - mid, c - mid, r + mid, c + mid);

                if (ones <= k) {
                    best_rad = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (best_rad == -1) {
                ans.push_back(-1);
            } else {
                ans.push_back(2 * best_rad + 1);
            }
        }

        return ans;
    }
};