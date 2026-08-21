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
}; */

class Solution {
    Node* findLCA(Node* root, int n1, int n2) {
        if (!root) return nullptr;
        if (root->data == n1 || root->data == n2) return root;

        Node* left = findLCA(root->left, n1, n2);
        Node* right = findLCA(root->right, n1, n2);

        if (left && right) return root;
        return left ? left : right;
    }

    bool getPath(Node* root, int target, string& path) {
        if (!root) return false;
        if (root->data == target) return true;

        path.push_back('L');
        if (getPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

    int countTurns(const string& path) {
        int turns = 0;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] != path[i - 1]) {
                turns++;
            }
        }
        return turns;
    }

public:
    int numberOfTurns(Node* root, int p, int q) {
        if (!root || p == q) return -1;

        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;

        if (lca->data == p) {
            string path = "";
            getPath(lca, q, path);
            int turns = countTurns(path);
            return turns == 0 ? -1 : turns;
        } 
        else if (lca->data == q) {
            string path = "";
            getPath(lca, p, path);
            int turns = countTurns(path);
            return turns == 0 ? -1 : turns;
        } 
        else {
            string pathP = "", pathQ = "";
            getPath(lca, p, pathP);
            getPath(lca, q, pathQ);

            // Reversing the direction for path to P, plus the direction change at the LCA (+1)
            int turns = countTurns(pathP) + countTurns(pathQ) + 1;
            return turns == 0 ? -1 : turns;
        }
    }
};