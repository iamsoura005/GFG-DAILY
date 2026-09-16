class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        deque<int> dq;
        vector<int> dist(n + 1, 1e9);

        dist[src] = 0;
        dq.push_back(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == dst) {
                return dist[u];
            }

            for (const auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    if (weight == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};