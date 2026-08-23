class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1) return -1;
        vector<int> dirX = {0,0,-1,1,-1,-1,1,1};
        vector<int> dirY = {-1,1,0,0,1,-1,1,-1};
        queue<pair<int,int>> q;
        int dist = 1;
        q.push({0,0});
        grid[0][0] = -1;
        while(!q.empty()){
            int sz = q.size();
            dist++;
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r==n-1 && c==n-1) return dist-1;
                int nr = 0;
                int nc = 0;
                for(auto &i:dirX){
                    for(auto &j:dirY){
                        nr = r+j;
                        nc = c+i;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                            q.push({nr,nc});
                            grid[nr][nc] = -1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};