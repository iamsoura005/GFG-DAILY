class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (r[i] - l[i] + 1);
        }

        vector<int> ans;
        ans.reserve(rank.size());

        for (int rk : rank) {
            auto it = lower_bound(pref.begin(), pref.end(), rk);
            int idx = (it - pref.begin()) - 1;
            long long rem = rk - pref[idx];
            ans.push_back(l[idx] + rem - 1);
        }

        return ans;
    }
};