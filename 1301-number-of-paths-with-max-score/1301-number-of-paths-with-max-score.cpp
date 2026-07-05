class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;

    // dp[i][j] = {maxScore, ways}
    vector<vector<pair<int,int>>> dp;
    vector<string> b;

    pair<int,int> dfs(int i, int j) {
        if (i < 0 || j < 0 || b[i][j] == 'X')
            return {-1, 0};

        if (i == 0 && j == 0)
            return {0, 1};

        if (dp[i][j].first != -2)
            return dp[i][j];

        pair<int,int> up = dfs(i - 1, j);
        pair<int,int> left = dfs(i, j - 1);
        pair<int,int> diag = dfs(i - 1, j - 1);

        int best = max({up.first, left.first, diag.first});

        if (best == -1)
            return dp[i][j] = {-1, 0};

        long long ways = 0;

        if (up.first == best) ways = (ways + up.second) % MOD;
        if (left.first == best) ways = (ways + left.second) % MOD;
        if (diag.first == best) ways = (ways + diag.second) % MOD;

        int val = 0;
        if (b[i][j] != 'S' && b[i][j] != 'E')
            val = b[i][j] - '0';

        return dp[i][j] = {best + val, (int)ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        b = board;
        n = board.size();

        dp.assign(n, vector<pair<int,int>>(n, {-2, -2}));

        auto ans = dfs(n - 1, n - 1);

        if (ans.first == -1)
            return {0, 0};

        return {ans.first, ans.second};
    }
};