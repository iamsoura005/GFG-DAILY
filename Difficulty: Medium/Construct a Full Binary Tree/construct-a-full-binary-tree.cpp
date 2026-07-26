class Solution {
    unordered_map<int, int> mp;

    Node* build(vector<int>& pre, vector<int>& preMirror, int& preIndex, int l, int r) {
        if (preIndex >= pre.size() || l > r) return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (l == r || preIndex >= pre.size()) return root;

        int idx = mp[pre[preIndex]];

        if (idx >= l && idx <= r) {
            root->left = build(pre, preMirror, preIndex, idx, r);
            root->right = build(pre, preMirror, preIndex, l + 1, idx - 1);
        }

        return root;
    }

public:
    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();
        mp.clear();
        for (int i = 0; i < n; i++) {
            mp[preMirror[i]] = i;
        }
        int preIndex = 0;
        return build(pre, preMirror, preIndex, 0, n - 1);
    }
};