class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> elements;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                elements.push_back(grid[i][j]);
            }
        }
        int sz = n*m;
        k = k%sz;
        int idx = sz-k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = elements[idx%sz];
                idx++;
            }
        }
        return grid;
    }
};