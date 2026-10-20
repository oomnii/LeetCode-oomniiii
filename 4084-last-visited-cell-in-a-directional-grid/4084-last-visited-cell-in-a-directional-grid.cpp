class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r = 0;
        int c = 0;
        while(1){
            char dir = grid[r][c];
            grid[r][c] = '$';
            if(dir == 'L'){
                if(c-1<0 || grid[r][c-1]=='$') break;
                c--;
            }
            else if(dir == 'R'){
                if(c+1>=m || grid[r][c+1]=='$') break;
                c++;
            }
            else if(dir == 'U'){
                if(r-1<0 || grid[r-1][c]=='$') break;
                r--;
            }
            else{
                if(r+1>=n || grid[r+1][c]=='$') break;
                r++;
            }
        }
        return {r,c};
    }
};