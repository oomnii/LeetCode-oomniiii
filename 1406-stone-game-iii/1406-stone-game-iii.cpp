class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& v) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        int ans = INT_MIN;
        int sum = 0;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += v[i + k];
            ans = max(ans, sum - solve(i + k + 1, v));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int stones = solve(0, stoneValue);

        if (stones > 0) return "Alice";
        if (stones < 0) return "Bob";
        return "Tie";
    }
};