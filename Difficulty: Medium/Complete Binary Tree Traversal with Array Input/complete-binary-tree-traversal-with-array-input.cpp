class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        int start = 0;
        int count = 1;

        while (start < n) {
            int end = min(n, start + count);
            vector<int> level(arr.begin() + start, arr.begin() + end);
            sort(level.begin(), level.end());
            result.push_back(level);
            start = end;
            count *= 2;
        }

        return result;
    }
};