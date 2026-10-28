class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>& grid,int row,int col,int xr,vector<vector<vector<int>>> &dp){
        if(row>=m || col>=n) return INT_MAX;
        int nxr = xr^grid[row][col];
        if (row == m - 1 && col == n - 1) return dp[row][col][xr]=nxr;
        
        if (dp[row][col][xr]!=-1) return dp[row][col][xr];
        

        int right = solve(grid, row, col + 1, nxr,dp);
        int down  = solve(grid, row + 1, col, nxr,dp);

        return dp[row][col][xr] = min(right, down);
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024,-1)));
        return solve(grid,0,0,0,dp);
    }
};