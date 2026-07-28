class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        int dummyCount = 0;
        for (const auto& e : edges) {
            if (e[2] == 2) dummyCount++;
        }

        int totalNodes = V + dummyCount;
        vector<vector<int>> adj(totalNodes);
        int nextDummy = V;

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                adj[u].push_back(nextDummy);
                adj[nextDummy].push_back(u);
                adj[nextDummy].push_back(v);
                adj[v].push_back(nextDummy);
                nextDummy++;
            }
        }

        vector<int> dist(totalNodes, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == dest) return dist[u];

            for (int neighbor : adj[u]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[u] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist[dest];
    }
};