class Solution {
private:
    void inorder(Node* root, Node*& prev, int& minDiff) {
        if (!root) return;

        inorder(root->left, prev, minDiff);

        if (prev != nullptr) {
            minDiff = std::min(minDiff, root->data - prev->data);
        }
        prev = root;

        inorder(root->right, prev, minDiff);
    }

public:
    int absDiff(Node* root) {
        int minDiff = INT_MAX;
        Node* prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};