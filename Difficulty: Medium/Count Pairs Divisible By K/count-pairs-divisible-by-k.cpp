class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<long long> rem(k, 0);
        for (int num : arr) {
            rem[(num % k + k) % k]++;
        }
        
        long long ans = 0;
        ans += (rem[0] * (rem[0] - 1)) / 2;
        
        for (int i = 1; i <= k / 2; i++) {
            if (i == k - i) {
                ans += (rem[i] * (rem[i] - 1)) / 2;
            } else {
                ans += rem[i] * rem[k - i];
            }
        }
        
        return ans;
    }
};