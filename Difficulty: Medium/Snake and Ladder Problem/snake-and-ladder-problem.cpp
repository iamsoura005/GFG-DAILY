class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int target = n * n;
        vector<int> board(target + 1, 0);

        for (int i = 1; i <= target; ++i) {
            board[i] = i;
        }

        for (int i = 0; i < lad.size(); i += 2) {
            board[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            board[sn[i]] = sn[i + 1];
        }

        vector<int> dist(target + 1, -1);
        queue<int> q;

        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == target) return dist[curr];

            for (int dice = 1; dice <= 6; ++dice) {
                int next_cell = curr + dice;
                if (next_cell <= target) {
                    int dest = board[next_cell];
                    if (dist[dest] == -1) {
                        dist[dest] = dist[curr] + 1;
                        q.push(dest);
                    }
                }
            }
        }

        return -1;
    }
};