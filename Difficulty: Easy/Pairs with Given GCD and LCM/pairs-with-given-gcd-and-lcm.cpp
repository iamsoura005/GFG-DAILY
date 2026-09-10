class Solution {
public:
    int pairCount(int x, int y) {
        if (y % x != 0) {
            return 0;
        }

        int k = y / x;
        int distinct_prime_factors = 0;

        for (int d = 2; d * d <= k; ++d) {
            if (k % d == 0) {
                distinct_prime_factors++;
                while (k % d == 0) {
                    k /= d;
                }
            }
        }

        if (k > 1) {
            distinct_prime_factors++;
        }

        return 1 << distinct_prime_factors;
    }
};