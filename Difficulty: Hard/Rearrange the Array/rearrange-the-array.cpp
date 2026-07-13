class Solution {
public:
    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> visited(n, false);
        vector<int> max_power(n + 1, 0);
        long long MOD = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int len = 0;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr] - 1; // 1-based to 0-based indexing
                    len++;
                }

                // Factorize the cycle length
                int temp = len;
                for (int d = 2; d * d <= temp; ++d) {
                    if (temp % d == 0) {
                        int count = 0;
                        while (temp % d == 0) {
                            count++;
                            temp /= d;
                        }
                        max_power[d] = max(max_power[d], count);
                    }
                }
                if (temp > 1) {
                    max_power[temp] = max(max_power[temp], 1);
                }
            }
        }

        long long ans = 1;
        for (int i = 2; i <= n; ++i) {
            while (max_power[i] > 0) {
                ans = (ans * i) % MOD;
                max_power[i]--;
            }
        }

        return ans;
    }
};