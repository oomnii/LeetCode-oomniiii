class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;

    bool is_Island(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        bool closed = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                closed = false;
            }

            // Up
            if (r - 1 >= 0 && !visited[r - 1][c] &&
                grid[r - 1][c] == 0) {
                q.push({r - 1, c});
                visited[r - 1][c] = true;
            }

            // Down
            if (r + 1 < n && !visited[r + 1][c] &&
                grid[r + 1][c] == 0) {
                q.push({r + 1, c});
                visited[r + 1][c] = true;
            }

            // Left
            if (c - 1 >= 0 && !visited[r][c - 1] &&
                grid[r][c - 1] == 0) {
                q.push({r, c - 1});
                visited[r][c - 1] = true;
            }

            // Right
            if (c + 1 < m && !visited[r][c + 1] &&
                grid[r][c + 1] == 0) {
                q.push({r, c + 1});
                visited[r][c + 1] = true;
            }
        }
        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        visited.assign(n, vector<bool>(m, false));
        int island = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    if (is_Island(i, j, grid)) {
                        island++;
                    }
                }
            }
        }
        return island;
    }
};