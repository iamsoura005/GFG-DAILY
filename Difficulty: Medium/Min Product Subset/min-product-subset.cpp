class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int max_neg = -1e9;
        int min_pos = 1e9;
        int count_neg = 0, count_zero = 0;
        long long prod = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count_zero++;
                continue;
            }
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            }
            if (arr[i] > 0) {
                min_pos = min(min_pos, arr[i]);
            }
            prod *= arr[i];
        }

        if (count_zero == n || (count_neg == 0 && count_zero > 0)) {
            return 0;
        }

        if (count_neg == 0) {
            return min_pos;
        }

        if (count_neg % 2 == 0 && count_neg != 0) {
            prod = prod / max_neg;
        }

        return (int)prod;
    }
};