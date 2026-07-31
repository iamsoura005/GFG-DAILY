class Solution {
public:
    int countSubsets(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> freq(31, 0);
        for (int x : arr) {
            freq[x]++;
        }

        vector<int> num_mask(31, 0);
        for (int i = 2; i <= 30; ++i) {
            int temp = i;
            int mask = 0;
            bool valid = true;
            for (int j = 0; j < 10; ++j) {
                int p = primes[j];
                int count = 0;
                while (temp % p == 0) {
                    count++;
                    temp /= p;
                }
                if (count > 1) {
                    valid = false;
                    break;
                }
                if (count == 1) {
                    mask |= (1 << j);
                }
            }
            if (valid) {
                num_mask[i] = mask;
            } else {
                num_mask[i] = -1;
            }
        }

        vector<long long> dp(1024, 0);
        dp[0] = 1;

        for (int i = 2; i <= 30; ++i) {
            if (freq[i] == 0 || num_mask[i] == -1) continue;
            int mask = num_mask[i];
            long long count = freq[i];

            for (int prev_mask = 1023; prev_mask >= 0; --prev_mask) {
                if ((prev_mask & mask) == 0) {
                    dp[prev_mask | mask] = (dp[prev_mask | mask] + dp[prev_mask] * count) % MOD;
                }
            }
        }

        long long total_subsets = 0;
        for (int mask = 1; mask < 1024; ++mask) {
            total_subsets = (total_subsets + dp[mask]) % MOD;
        }

        long long ones_ways = 1;
        for (int i = 0; i < freq[1]; ++i) {
            ones_ways = (ones_ways * 2) % MOD;
        }

        return (total_subsets * ones_ways) % MOD;
    }
};