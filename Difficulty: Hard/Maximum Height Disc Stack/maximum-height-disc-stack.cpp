class Solution {
    struct Fenwick {
        int sz;
        vector<int> tree;
        Fenwick(int n) : sz(n), tree(n + 1, 0) {}

        void update(int idx, int val) {
            for (; idx <= sz; idx += idx & -idx) {
                tree[idx] = max(tree[idx], val);
            }
        }

        int query(int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx) {
                res = max(res, tree[idx]);
            }
            return res;
        }
    };

public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        if (n == 0) return 0;

        vector<pair<int, int>> discs(n);
        for (int i = 0; i < n; ++i) {
            discs[i] = {r[i], h[i]};
        }

        sort(discs.begin(), discs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        int max_h = 0;
        for (int val : h) {
            if (val > max_h) max_h = val;
        }

        Fenwick bit(max_h);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int current_h = discs[i].second;
            int best_prev = bit.query(current_h - 1);
            int cur_total = best_prev + current_h;
            ans = max(ans, cur_total);
            bit.update(current_h, cur_total);
        }

        return ans;
    }
};