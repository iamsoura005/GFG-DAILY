class Solution {
public:
    int partyHouse(vector<vector<int>>& adj) {
        int n = adj.size();
        if (n <= 1) return 0;

        // BFS to find the farthest node from an arbitrary start node
        auto bfs = [&](int start_node) -> pair<int, int> {
            vector<int> dist(n + 1, -1);
            queue<int> q;

            q.push(start_node);
            dist[start_node] = 0;
            int farthest_node = start_node;
            int max_dist = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (dist[u] > max_dist) {
                    max_dist = dist[u];
                    farthest_node = u;
                }

                // adj[u - 1] contains neighbors of 1-indexed house u
                for (int v : adj[u - 1]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return {farthest_node, max_dist};
        };

        // First BFS to find one endpoint of the diameter
        pair<int, int> p1 = bfs(1);

        // Second BFS to find the other endpoint and the tree diameter length
        pair<int, int> p2 = bfs(p1.first);

        int diameter = p2.second;
        return (diameter + 1) / 2;
    }
};