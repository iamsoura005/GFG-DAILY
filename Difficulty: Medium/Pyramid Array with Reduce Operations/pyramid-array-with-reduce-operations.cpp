class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);

        left[0] = min(arr[0], 1);
        for (int i = 1; i < n; ++i) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        right[n - 1] = min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; --i) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        long long total_sum = 0;
        long long max_pyramid_sum = 0;

        for (int i = 0; i < n; ++i) {
            total_sum += arr[i];
            long long h = min(left[i], right[i]);
            long long pyramid_sum = h * h;
            if (pyramid_sum > max_pyramid_sum) {
                max_pyramid_sum = pyramid_sum;
            }
        }

        return total_sum - max_pyramid_sum;
    }
};