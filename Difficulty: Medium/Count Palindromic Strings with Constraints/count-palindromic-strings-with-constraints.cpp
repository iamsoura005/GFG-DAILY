class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long ans = 0;
        long long MOD = 1e9 + 7;

        // P[i] = P(k, i) = k * (k - 1) * ... * (k - i + 1)
        long long current_perm = 1;
        vector<long long> P(k + 1, 0);
        P[0] = 1;
        for (int i = 1; i <= k; ++i) {
            current_perm = (current_perm * (k - i + 1)) % MOD;
            P[i] = current_perm;
        }

        for (int L = 1; L <= n; ++L) {
            int distinct_needed = (L + 1) / 2;
            if (distinct_needed <= k) {
                ans = (ans + P[distinct_needed]) % MOD;
            }
        }

        return ans;
    }
};