class Solution {
  public:
    bool areAnagrams(Node *root1, Node *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int sz1 = q1.size();
            int sz2 = q2.size();

            if (sz1 != sz2) return false;

            unordered_map<int, int> countMap;

            for (int i = 0; i < sz1; ++i) {
                Node* curr1 = q1.front();
                q1.pop();
                countMap[curr1->data]++;

                if (curr1->left) q1.push(curr1->left);
                if (curr1->right) q1.push(curr1->right);
            }

            for (int i = 0; i < sz2; ++i) {
                Node* curr2 = q2.front();
                q2.pop();

                auto it = countMap.find(curr2->data);
                if (it == countMap.end() || it->second == 0) {
                    return false;
                }
                it->second--;
                if (it->second == 0) {
                    countMap.erase(it);
                }

                if (curr2->left) q2.push(curr2->left);
                if (curr2->right) q2.push(curr2->right);
            }

            if (!countMap.empty()) return false;
        }

        return q1.empty() && q2.empty();
    }
};