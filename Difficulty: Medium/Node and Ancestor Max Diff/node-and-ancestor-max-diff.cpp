/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
private:
    int solve(Node* root, int &max_diff) {
        if (!root) {
            return INT_MAX;
        }

        if (!root->left && !root->right) {
            return root->data;
        }

        int left_min = solve(root->left, max_diff);
        int right_min = solve(root->right, max_diff);
        int min_child = std::min(left_min, right_min);

        max_diff = std::max(max_diff, root->data - min_child);

        return std::min(root->data, min_child);
    }

public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        solve(root, max_diff);
        return max_diff;
    }
};