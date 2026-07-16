class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        
        vector<int> left_max(n), left_min(n);
        vector<int> right_max(n), right_min(n);
        
        int max_ending_here = arr[0];
        left_max[0] = arr[0];
        for (int i = 1; i < n; i++) {
            max_ending_here = max(arr[i], max_ending_here + arr[i]);
            left_max[i] = max(left_max[i - 1], max_ending_here);
        }
        
        int min_ending_here = arr[0];
        left_min[0] = arr[0];
        for (int i = 1; i < n; i++) {
            min_ending_here = min(arr[i], min_ending_here + arr[i]);
            left_min[i] = min(left_min[i - 1], min_ending_here);
        }
        
        max_ending_here = arr[n - 1];
        right_max[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_ending_here = max(arr[i], max_ending_here + arr[i]);
            right_max[i] = max(right_max[i + 1], max_ending_here);
        }
        
        min_ending_here = arr[n - 1];
        right_min[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            min_ending_here = min(arr[i], min_ending_here + arr[i]);
            right_min[i] = min(right_min[i + 1], min_ending_here);
        }
        
        int max_diff = 0;
        for (int i = 0; i < n - 1; i++) {
            max_diff = max(max_diff, abs(left_max[i] - right_min[i + 1]));
            max_diff = max(max_diff, abs(left_min[i] - right_max[i + 1]));
        }
        
        return max_diff;
    }
};