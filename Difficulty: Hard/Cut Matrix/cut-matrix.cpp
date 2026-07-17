#include <vector>

using namespace std;

class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long MOD = 1e9 + 7;

        // pref[i][j] stores the number of 1s in matrix[0...i-1][0...j-1]
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] = matrix[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        auto has1 = [&](int r1, int c1, int r2, int c2) {
            if (r1 > r2 || c1 > c2) return false;
            int count = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
            return count > 0;
        };

        // Precompute the minimum row/col index to contain at least one 1
        vector<vector<int>> V_h(n, vector<int>(m, -1));
        vector<vector<int>> V_v(n, vector<int>(m, -1));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                // For horizontal cuts
                for (int i = r; i < n; i++) {
                    if (has1(r, c, i, m - 1)) {
                        V_h[r][c] = i;
                        break;
                    }
                }
                // For vertical cuts
                for (int j = c; j < m; j++) {
                    if (has1(r, c, n - 1, j)) {
                        V_v[r][c] = j;
                        break;
                    }
                }
            }
        }

        // dp[r][c][rem]
        // sumH[r][c] = sum_{i=r}^{n-1} dp[i][c]
        // sumV[r][c] = sum_{j=c}^{m-1} dp[r][j]
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        vector<vector<long long>> sumH(n + 1, vector<long long>(m, 0));
        vector<vector<long long>> sumV(n, vector<long long>(m + 1, 0));

        // Base case: rem = 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (has1(r, c, n - 1, m - 1)) {
                    dp[r][c] = 1;
                }
                sumH[r][c] = dp[r][c];
                sumV[r][c] = dp[r][c];
            }
        }

        for (int r = n - 1; r >= 0; r--) {
            for (int c = m - 1; c >= 0; c--) {
                sumH[r][c] = (dp[r][c] + sumH[r + 1][c]) % MOD;
                sumV[r][c] = (dp[r][c] + sumV[r][c + 1]) % MOD;
            }
        }

        for (int rem = 2; rem <= k; rem++) {
            vector<vector<long long>> next_dp(n, vector<long long>(m, 0));
            vector<vector<long long>> next_sumH(n + 1, vector<long long>(m, 0));
            vector<vector<long long>> next_sumV(n, vector<long long>(m + 1, 0));

            for (int r = n - 1; r >= 0; r--) {
                for (int c = m - 1; c >= 0; c--) {
                    long long ways = 0;

                    // Horizontal cuts
                    int idx_h = V_h[r][c];
                    if (idx_h != -1 && idx_h <= n - 2) {
                        ways = (ways + sumH[idx_h + 1][c] - sumH[n][c] + MOD) % MOD;
                    }

                    // Vertical cuts
                    int idx_v = V_v[r][c];
                    if (idx_v != -1 && idx_v <= m - 2) {
                        ways = (ways + sumV[r][idx_v + 1] - sumV[r][m] + MOD) % MOD;
                    }

                    next_dp[r][c] = ways;
                    next_sumH[r][c] = (ways + next_sumH[r + 1][c]) % MOD;
                    next_sumV[r][c] = (ways + next_sumV[r][c + 1]) % MOD;
                }
            }
            dp = move(next_dp);
            sumH = move(next_sumH);
            sumV = move(next_sumV);
        }

        return dp[0][0];
    }
};