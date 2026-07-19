class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, n - 1);
        
        left[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] <= arr[i - 1]) {
                left[i] = left[i - 1];
            } else {
                left[i] = i;
            }
        }
        
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1]) {
                right[i] = right[i + 1];
            } else {
                right[i] = i;
            }
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(right[l] >= left[r]);
        }
        
        return ans;
    }
};