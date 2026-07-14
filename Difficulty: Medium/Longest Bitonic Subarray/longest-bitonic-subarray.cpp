class Solution {
public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return n;

        // inc[i] stores the length of the longest increasing subarray ending at index i
        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        // dec[i] stores the length of the longest decreasing subarray starting at index i
        vector<int> dec(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        int max_len = 1;
        for (int i = 0; i < n; i++) {
            max_len = max(max_len, inc[i] + dec[i] - 1);
        }

        return max_len;
    }
};