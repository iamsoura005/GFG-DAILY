class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        if (n == 0) return 0;

        int prev2 = 0;
        int prev1 = max(h[0], l[0]);

        for (int i = 1; i < n; ++i) {
            int curr = max(prev1 + l[i], prev2 + h[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};