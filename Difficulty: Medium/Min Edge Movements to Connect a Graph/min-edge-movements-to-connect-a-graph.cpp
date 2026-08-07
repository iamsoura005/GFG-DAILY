class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) 
            return -1;

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;
        for (auto& edge : edges) {
            int root1 = find(edge[0], parent);
            int root2 = find(edge[1], parent);

            if (root1 != root2) {
                parent[root1] = root2;
                components--;
            }
        }

        return components - 1;
    }
};