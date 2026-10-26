class Solution {
public:
    int n;
    int m;
    bool check(int i,int j,vector<vector<int>>& grid, int k){
        int sum = 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        sum += grid[i][j];
        grid[i][j] = 0;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            // up:
            if(r-1>=0 && grid[r-1][c]!=0){
                sum += grid[r-1][c];
                q.push({r-1,c});
                grid[r-1][c]=0;
            }
            // down:
            if(r+1<n && grid[r+1][c]!=0){
                sum += grid[r+1][c];
                q.push({r+1,c});
                grid[r+1][c]=0;
            }
            // left:
            if(c-1>=0 && grid[r][c-1]!=0){
                sum += grid[r][c-1];
                q.push({r,c-1});
                grid[r][c-1]=0;
            }
            // right:
            if(c+1<m && grid[r][c+1]!=0){
                sum += grid[r][c+1];
                q.push({r,c+1});
                grid[r][c+1]=0;
            }
        }
        return sum%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    if(check(i,j,grid,k)) island++; 
                }
            }
        }
        return island;
    }
};