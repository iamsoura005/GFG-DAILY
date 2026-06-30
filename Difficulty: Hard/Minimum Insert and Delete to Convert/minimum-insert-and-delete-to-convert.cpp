class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        // Since elements in b are sorted and distinct, we can use binary search
        // to filter elements of 'a' and find their target positions in 'b'.
        vector<int> targetIndices;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            if (it != b.end() && *it == a[i]) {
                // Store the index position in 'b'
                targetIndices.push_back(it - b.begin());
            }
        }
        
        // Find the Longest Increasing Subsequence (LIS) of targetIndices
        vector<int> lis;
        for (int idx : targetIndices) {
            auto it = lower_bound(lis.begin(), lis.end(), idx);
            if (it == lis.end()) {
                lis.push_back(idx);
            } else {
                *it = idx;
            }
        }
        
        int lisLength = lis.size();
        
        // Total operations = deletions from a + insertions from b
        return (n - lisLength) + (m - lisLength);
    }
};