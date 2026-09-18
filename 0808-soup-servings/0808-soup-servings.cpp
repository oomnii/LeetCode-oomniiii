class Solution {
public:
    double dp[205][205];

    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        return dp[a][b] = 0.25 * (
            solve(a - 4, b) +
            solve(a - 3, b - 1) +
            solve(a - 2, b - 2) +
            solve(a - 1, b - 3)
        );
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        n = (n + 24) / 25;
        fill(&dp[0][0], &dp[0][0] + 205 * 205, -1.0);
        return solve(n, n);
    }
};