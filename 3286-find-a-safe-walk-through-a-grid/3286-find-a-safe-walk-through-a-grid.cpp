class Solution {
public:
    const int INF = 1e9;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int,int,int>> q; // {health,row,col}
        vector<vector<int>> healthAtcurr(m,vector<int>(n,0));
        if(grid[0][0]==1){
            q.push({health-1,0,0});
            healthAtcurr[0][0] = health-1;
        }
        else {
            q.push({health,0,0});
            healthAtcurr[0][0] = health;
        }

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [h,r,c] = q.front();
                q.pop();

                if(r==m-1 && c==n-1){
                    return true;
                }

                //up:
                if(r-1>=0){
                    if(grid[r-1][c]==1){
                        if(healthAtcurr[r-1][c]<(h-1)){
                            q.push({h-1,r-1,c});
                            healthAtcurr[r-1][c] = h-1;
                        }
                    }
                    else{
                        if(healthAtcurr[r-1][c]<h){
                            q.push({h,r-1,c});
                            healthAtcurr[r-1][c] = h;
                        }
                    }
                }

                //down:
                if(r+1<m){
                    if(grid[r+1][c]==1){
                        if(healthAtcurr[r+1][c]<(h-1)){
                            q.push({h-1,r+1,c});
                            healthAtcurr[r+1][c] = h-1;
                        }
                    }
                    else{
                        if(healthAtcurr[r+1][c]<h){
                            q.push({h,r+1,c});
                            healthAtcurr[r+1][c] = h;
                        }
                    }
                }

                //left:
                if(c-1>=0){
                    if(grid[r][c-1]==1){
                        if(healthAtcurr[r][c-1]<(h-1)){
                            q.push({h-1,r,c-1});
                            healthAtcurr[r][c-1] = h-1;
                        }
                    }
                    else{
                        if(healthAtcurr[r][c-1]<h){
                            q.push({h,r,c-1});
                            healthAtcurr[r][c-1] = h;
                        }
                    } 
                }

                //right:
                if(c+1<n){
                    if(grid[r][c+1]==1){
                        if(healthAtcurr[r][c+1]<(h-1)){
                            q.push({h-1,r,c+1});
                            healthAtcurr[r][c+1] = h-1;
                        }
                    }
                    else{
                        if(healthAtcurr[r][c+1]<h){
                            q.push({h,r,c+1});
                            healthAtcurr[r][c+1] = h;
                        }
                    }
                }
            }
        }
        return false;
    }
};