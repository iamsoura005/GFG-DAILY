class Solution {
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n, long long mod) {
        return power(n, mod - 2, mod);
    }

public:
    int prefixStrings(int n) {
        long long MOD = 1e9 + 7;

        long long num = 1;
        for (int i = 1; i <= 2 * n; ++i) {
            num = (num * i) % MOD;
        }

        long long den = 1;
        for (int i = 1; i <= n; ++i) {
            den = (den * i) % MOD;
        }

        long long den_n_plus_1 = (den * (n + 1)) % MOD;
        long long total_den = (den * den_n_plus_1) % MOD;

        return (num * modInverse(total_den, MOD)) % MOD;
    }
};