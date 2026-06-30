class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> forward(n), backward(n);
        
        // Step 1: Compute max sum subarray ending at each index (Standard Kadane)
        int max_so_far = arr[0];
        forward[0] = arr[0];
        for (int i = 1; i < n; i++) {
            forward[i] = max(arr[i], forward[i - 1] + arr[i]);
            max_so_far = max(max_so_far, forward[i]);
        }

        // Step 2: Compute max sum subarray starting at each index
        backward[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            backward[i] = max(arr[i], backward[i + 1] + arr[i]);
        }

        // Step 3: Choose the maximum by trying to drop an element at index i
        for (int i = 1; i < n - 1; i++) {
            max_so_far = max(max_so_far, forward[i - 1] + backward[i + 1]);
        }

        return max_so_far;
    }
};