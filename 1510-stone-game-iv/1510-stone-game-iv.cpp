class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int n, int chance) {
        if (n == 0) {
            if (chance == 0) return false;
            else return true;
        }

        if (dp[n][chance] != -1)
            return dp[n][chance];

        if (chance == 0) {
            // My turn -> need at least one winning move
            bool ans = false;

            for (int i = 1; ; i++) {
                int square = i * i;

                if (square > n)
                    break;

                ans = ans || solve(n - square, 1);
            }

            return dp[n][chance] = ans;
        }
        else {
            // Opponent's turn -> all moves must still let me win
            bool ans = true;

            for (int i = 1; ; i++) {
                int square = i * i;

                if (square > n)
                    break;

                ans = ans && solve(n - square, 0);
            }

            return dp[n][chance] = ans;
        }
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, vector<int>(2, -1));
        return solve(n, 0);
    }
};