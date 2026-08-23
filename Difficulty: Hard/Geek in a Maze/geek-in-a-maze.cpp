#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {

        int n = mat.size();                    // Number of rows
        int m = mat[0].size();                 // Number of columns

        // If starting cell is blocked
        if(mat[r][c] == '#')
            return 0;

        // dist[i][j] = minimum upward moves needed
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Deque for 0-1 BFS
        deque<pair<int,int>> dq;

        // Starting cell requires 0 upward moves
        dist[r][c] = 0;
        dq.push_front({r, c});

        // Directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!dq.empty()) {

            // Get current cell
            auto [x, y] = dq.front();
            dq.pop_front();

            // Try all 4 directions
            for(int k = 0; k < 4; k++) {

                int nx = x + dr[k];
                int ny = y + dc[k];

                // Check boundaries
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                // Skip obstacle
                if(mat[nx][ny] == '#')
                    continue;

                // Moving UP costs 1
                // Other moves cost 0
                int cost = (nx < x) ? 1 : 0;

                int newDist = dist[x][y] + cost;

                // Found a better path
                if(newDist < dist[nx][ny]) {

                    dist[nx][ny] = newDist;

                    // 0 cost -> front
                    if(cost == 0)
                        dq.push_front({nx, ny});

                    // 1 cost -> back
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        int ans = 0;

        // Check every cell
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // Ignore obstacle/unreachable cells
                if(mat[i][j] == '#' || dist[i][j] == INT_MAX)
                    continue;

                // Minimum upward moves
                int upMoves = dist[i][j];

                // Relation:
                // down - up = i - r
                int downMoves = upMoves + (i - r);

                // Check both limits
                if(upMoves <= u && downMoves <= d)
                    ans++;
            }
        }

        return ans;
    }
};