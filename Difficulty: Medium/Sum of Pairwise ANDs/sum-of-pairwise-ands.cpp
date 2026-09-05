class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long totalSum = 0;

        for (int bit = 0; bit < 32; bit++) {
            long long count = 0;
            for (int x : arr) {
                if ((x >> bit) & 1) {
                    count++;
                }
            }

            long long pairs = (count * (count - 1)) / 2;
            totalSum += pairs * (1LL << bit);
        }

        return totalSum;
    }
};