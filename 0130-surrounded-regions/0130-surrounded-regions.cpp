class Solution {
public:
    int m;
    int n;
    vector<vector<int>> visited;

    bool check(int i, int j, vector<vector<char>>& board,vector<pair<int, int>>& cells) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        cells.push_back({i, j});
        bool isSurrounded = true;  // Added

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if (r == m - 1 || r == 0 || c == n - 1 || c == 0) {
                    isSurrounded = false;
                }

                // Up
                if (r - 1 >= 0 && visited[r - 1][c] == 0 && board[r - 1][c] == 'O') {
                    q.push({r - 1, c});
                    visited[r - 1][c] = 1;
                    cells.push_back({r - 1, c});
                }

                // Down
                if (r + 1 < m && visited[r + 1][c] == 0 && board[r + 1][c] == 'O') {
                    q.push({r + 1, c});
                    visited[r + 1][c] = 1;
                    cells.push_back({r + 1, c});
                }

                // Left
                if (c - 1 >= 0 && visited[r][c - 1] == 0 && board[r][c - 1] == 'O') {
                    q.push({r, c - 1});
                    visited[r][c - 1] = 1;
                    cells.push_back({r, c - 1});
                }

                // Right
                if (c + 1 < n && visited[r][c + 1] == 0 && board[r][c + 1] == 'O') {
                    q.push({r, c + 1});
                    visited[r][c + 1] = 1;
                    cells.push_back({r, c + 1});
                }
            }
        }
        return isSurrounded;
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        m = board.size();
        n = board[0].size();

        visited.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    vector<pair<int, int>> cells;
                    if (check(i, j, board, cells)) {
                        for (auto& cell : cells) {
                            int r = cell.first;
                            int c = cell.second;
                            board[r][c] = 'X';
                        }
                    }
                } else {
                    visited[i][j] = 1;
                }
            }
        }
        return;
    }
};