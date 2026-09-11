class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // If k == n, the only subsequence is the entire array.
        if (k == n) {
            long long prod = 1;
            for (int x : arr) prod *= x;
            return prod;
        }

        // If all numbers are negative and k is odd,
        // picking any k elements yields a negative product.
        // To maximize a negative product, pick elements with the smallest absolute values (end of sorted array).
        if (arr.back() < 0 && (k % 2 != 0)) {
            long long prod = 1;
            for (int i = n - 1; i >= n - k; --i) {
                prod *= arr[i];
            }
            return prod;
        }

        int left = 0;
        int right = n - 1;
        long long prod = 1;

        // If k is odd, take the largest positive element first.
        if (k % 2 != 0) {
            prod *= arr[right--];
            k--;
        }

        // Greedily take pairs from either end that produce the maximum product.
        while (k > 0) {
            long long left_pair = 1LL * arr[left] * arr[left + 1];
            long long right_pair = 1LL * arr[right] * arr[right - 1];

            if (left_pair > right_pair) {
                prod *= left_pair;
                left += 2;
            } else {
                prod *= right_pair;
                right -= 2;
            }
            k -= 2;
        }

        return prod;
    }
};