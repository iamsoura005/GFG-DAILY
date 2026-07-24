class Solution {
  private:
    int maxLen = 0;

    void dfs(Node* node, Node* parent, int curLen) {
        if (!node) return;

        if (parent && node->data == parent->data + 1) {
            curLen++;
        } else {
            curLen = 1;
        }

        if (curLen > maxLen) {
            maxLen = curLen;
        }

        dfs(node->left, node, curLen);
        dfs(node->right, node, curLen);
    }

  public:
    int longestConsecutive(Node* root) {
        maxLen = 0;
        dfs(root, nullptr, 0);
        return maxLen > 1 ? maxLen : -1;
    }
};