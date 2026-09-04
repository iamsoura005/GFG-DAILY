class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        if (m >= n) {
            long long total = 0;
            for (int x : arr) total += x;
            return total;
        }

        long long current_sum = 0;
        for (int i = 0; i < m; ++i) {
            current_sum += arr[i];
        }

        long long max_sum = current_sum;

        for (int i = 1; i < n; ++i) {
            current_sum += arr[(i + m - 1) % n] - arr[i - 1];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }

        return max_sum;
    }
};