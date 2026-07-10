class Solution {
private:
    int maxPath = -1;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void solve(vector<vector<int>>& mat, int r, int c, int xd, int yd, int steps) {
        if (r == xd && c == yd) {
            maxPath = max(maxPath, steps);
            return;
        }

        mat[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && mat[nr][nc] == 1) {
                solve(mat, nr, nc, xd, yd, steps + 1);
            }
        }

        mat[r][c] = 1;
    }

public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
        maxPath = -1;
        solve(mat, xs, ys, xd, yd, 0);
        return maxPath;
    }
};