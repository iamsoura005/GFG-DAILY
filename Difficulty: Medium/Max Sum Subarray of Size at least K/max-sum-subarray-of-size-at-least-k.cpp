class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> max_ending(n);
        max_ending[0] = arr[0];
        for (int i = 1; i < n; i++) {
            max_ending[i] = max(arr[i], max_ending[i - 1] + arr[i]);
        }
        
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        int max_sum = sum;
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i - k];
            max_sum = max(max_sum, sum);
            max_sum = max(max_sum, sum + max_ending[i - k]);
        }
        
        return max_sum;
    }
};