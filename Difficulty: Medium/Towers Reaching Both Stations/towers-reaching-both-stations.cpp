class Solution {
public:
    int countCoordinates(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        // Tracking reachability to both stations
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        
        queue<pair<int, int>> qP;
        queue<pair<int, int>> qQ;
        
        // Step 1: Add boundary cells into respective queues
        // Top and Bottom boundaries
        for (int j = 0; j < m; j++) {
            qP.push({0, j});
            reachP[0][j] = true;
            
            qQ.push({n - 1, j});
            reachQ[n - 1][j] = true;
        }
        
        // Left and Right boundaries
        for (int i = 0; i < n; i++) {
            qP.push({i, 0});
            reachP[i][0] = true;
            
            qQ.push({i, m - 1});
            reachQ[i][m - 1] = true;
        }
        
        // Direction vectors for moving North, South, East, West
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // Helper BFS lambda function to traverse up the signal strength
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& reach) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];
                    
                    // Check bounds and if it's already visited
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !reach[nr][nc]) {
                        // Signal flows backwards to EQUAL or HIGHER signal strengths
                        if (mat[nr][nc] >= mat[r][c]) {
                            reach[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        };
        
        // Step 2: Run BFS for both stations
        bfs(qP, reachP);
        bfs(qQ, reachQ);
        
        // Step 3: Count cells that can reach both stations
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachP[i][j] && reachQ[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};