class Solution {
public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        vector<int> rows, cols;
        
        // Add boundary conditions (0 and boundaries + 1)
        rows.push_back(0);
        rows.push_back(n + 1);
        cols.push_back(0);
        cols.push_back(m + 1);
        
        // Collect all blocked rows and columns
        for (int i = 0; i < k; i++) {
            rows.push_back(arr[i][0]);
            cols.push_back(arr[i][1]);
        }
        
        // Sort to find consecutive gaps
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        // Find the maximum gap between consecutive blocked rows
        int max_row_gap = 0;
        for (size_t i = 1; i < rows.size(); i++) {
            max_row_gap = max(max_row_gap, rows[i] - rows[i - 1] - 1);
        }
        
        // Find the maximum gap between consecutive blocked columns
        int max_col_gap = 0;
        for (size_t i = 1; i < cols.size(); i++) {
            max_col_gap = max(max_col_gap, cols[i] - cols[i - 1] - 1);
        }
        
        // The largest continuous area is the product of the two maximum gaps
        return max_row_gap * max_col_gap;
    }
};