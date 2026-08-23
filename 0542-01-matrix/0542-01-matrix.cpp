// class Solution {
// public:
//     int m ;
//     int n;
//     int findDist(int i,int j,vector<vector<int>>& mat){
//         queue<pair<int,int>> q;
//         vector<vector<int>> visited(m,vector<int>(n,0));
//         q.push({i,j});
//         visited[i][j] = 1;
//         int dist = 0;
//         while(!q.empty()){
//             int sz = q.size();
//             dist++;
//             while(sz--){
//                 int r = q.front().first;
//                 int c = q.front().second;
//                 q.pop();
//                 // UP:
//                 if(r-1>=0 && visited[r-1][c]==0){
//                     if(mat[r-1][c]==0){
//                         return dist;
//                     }
//                     else{
//                         q.push({r-1,c});
//                         visited[r-1][c] = 1;
//                     }
//                 }
//                 // DOWN:
//                 if(r+1<m && visited[r+1][c]==0){
//                     if(mat[r+1][c]==0){
//                         return dist;
//                     }
//                     else{
//                         q.push({r+1,c});
//                         visited[r+1][c] = 1;
//                     }
//                 }
//                 // LEFT:
//                 if(c-1>=0 && visited[r][c-1]==0){
//                     if(mat[r][c-1]==0){
//                         return dist;
//                     }
//                     else{
//                         q.push({r,c-1});
//                         visited[r][c-1] = 1;
//                     }
//                 }
//                 // RIGHT:
//                 if(c+1<n && visited[r][c+1]==0){
//                     if(mat[r][c+1]==0){
//                         return dist;
//                     }
//                     else{
//                         q.push({r,c+1});
//                         visited[r][c+1] = 1;
//                     }
//                 }
//             }
//         }
//         return dist;
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         m = mat.size();
//         n = mat[0].size();
//         vector<vector<int>> result(m,vector<int>(n,INT_MAX));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==1){
//                     int D = findDist(i,j,mat);
//                     result[i][j] = D;
//                 }
//                 else{
//                     result[i][j] = 0;
//                 }
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));

        // All zeroes are starting points.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};