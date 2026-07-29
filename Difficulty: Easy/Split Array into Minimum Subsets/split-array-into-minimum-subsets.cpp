class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int count = 0;
        
        for (int num : arr) {
            if (s.find(num - 1) == s.end()) {
                count++;
            }
        }
        
        return count;
    }
};