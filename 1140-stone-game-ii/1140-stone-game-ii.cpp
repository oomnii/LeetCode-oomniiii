class Solution {

private:
    int n;
    vector<int> ps;
    vector<vector<int>> dp;
    int solve(int index, int M) {
        if (index >= n)
            return 0;

        if (dp[index][M] != -1)
            return dp[index][M];

        int total = ps[n] - ps[index];

        int ans = 0;
        for (int x = 1; x <= 2 * M && index + x <= n; x++) {
            int opponent = solve(index + x, max(M, x));
            ans = max(ans, total - opponent);
        }

        return dp[index][M] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        ps.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};