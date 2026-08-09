class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        int max1 = 0, max2 = 0, max1_col = -1;

        for (int j = 0; j < n; j++) {
            if (mat[0][j] > max1) {
                max2 = max1;
                max1 = mat[0][j];
                max1_col = j;
            } else if (mat[0][j] > max2) {
                max2 = mat[0][j];
            }
        }

        for (int i = 1; i < n; i++) {
            int next_max1 = 0, next_max2 = 0, next_max1_col = -1;
            for (int j = 0; j < n; j++) {
                int prev_max = (j == max1_col) ? max2 : max1;
                int current = mat[i][j] + prev_max;

                if (current > next_max1) {
                    next_max2 = next_max1;
                    next_max1 = current;
                    next_max1_col = j;
                } else if (current > next_max2) {
                    next_max2 = current;
                }
            }
            max1 = next_max1;
            max2 = next_max2;
            max1_col = next_max1_col;
        }

        return max1;
    }
};