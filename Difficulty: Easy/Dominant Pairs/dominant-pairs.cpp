class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int mid = n / 2;

        sort(arr.begin(), arr.begin() + mid);
        sort(arr.begin() + mid, arr.end());

        int count = 0;
        int j = mid;

        for (int i = 0; i < mid; ++i) {
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            count += (j - mid);
        }

        return count;
    }
};