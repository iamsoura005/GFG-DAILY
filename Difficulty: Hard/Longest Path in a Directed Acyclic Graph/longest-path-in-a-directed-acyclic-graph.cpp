class Solution {
private:
    void topoSort(int u, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                topoSort(v, adj, visited, st);
            }
        }
        st.push(u);
    }

public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, adj, visited, st);
            }
        }

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] != INT_MIN) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (dist[u] + w > dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        return dist;
    }
};