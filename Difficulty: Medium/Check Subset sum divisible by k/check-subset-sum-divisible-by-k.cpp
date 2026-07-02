class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {
        // If the number of elements is greater than or equal to k,
        // by Pigeonhole Principle, a subset divisible by k always exists.
        if (arr.size() >= k) return true;

        // dp[i] will be true if a subset sum with remainder 'i' is possible
        vector<bool> dp(k, false);

        for (int x : arr) {
            int rem = x % k;
            
            // If the element itself is divisible by k
            if (rem == 0) return true;

            // To store the states formed by including the current element
            vector<bool> next_dp = dp;

            // Form new remainders using existing valid remainders
            for (int i = 0; i < k; i++) {
                if (dp[i]) {
                    next_dp[(i + rem) % k] = true;
                }
            }

            // Also include the current remainder as a standalone subset
            next_dp[rem] = true;
            
            // Update the main DP array
            dp = next_dp;

            // If we found a subset sum divisible by k, return true
            if (dp[0]) return true;
        }

        return dp[0];
    }
};