class Solution {
public:
    int maxSubsetXOR(vector<int>& arr) {
        vector<int> basis(32, 0);
        for (int x : arr) {
            for (int i = 31; i >= 0; i--) {
                if ((x & (1 << i)) == 0) continue;
                if (!basis[i]) {
                    basis[i] = x;
                    break;
                }
                x ^= basis[i];
            }
        }
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ((ans ^ basis[i]) > ans) {
                ans ^= basis[i];
            }
        }
        return ans;
    }
};