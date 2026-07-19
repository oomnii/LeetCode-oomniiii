class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        vector<vector<bool>> visited(8,vector<bool>(8,false));
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        visited[start[0]][start[1]] = true;
        int moves = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [r,c] = q.front();
                q.pop();
                if(r==target[0] && c == target[1] && moves%2==0) return true;
                // move 1:
                if(r-2>=0 && c+1<8 && !visited[r-2][c+1]){
                    q.push({r-2,c+1});
                    visited[r-2][c+1] = true;
                }
                // move 2:
                if(r-1>=0 && c+2<8 && !visited[r-1][c+2]){
                    q.push({r-1,c+2});
                    visited[r-1][c+2] = true;
                }
                // move 3:
                if(r-2>=0 && c-1>=0 && !visited[r-2][c-1]){
                    q.push({r-2,c-1});
                    visited[r-2][c-1] = true;
                }
                // move 4:
                if(r-1>=0 && c-2>=0 && !visited[r-1][c-2]){
                    q.push({r-1,c-2});
                    visited[r-1][c-2] = true;
                }
                // move 5:
                if(r+2<8 && c-1>=0 && !visited[r+2][c-1]){
                    q.push({r+2,c-1});
                    visited[r+2][c-1] = true;
                }
                // move 6:
                if(r+1<8 && c-2>=0 && !visited[r+1][c-2]){
                    q.push({r+1,c-2});
                    visited[r+1][c-2] = true;
                }
                // move 7:
                if(r+2<8 && c+1<8 && !visited[r+2][c+1]){
                    q.push({r+2,c+1});
                    visited[r+2][c+1] = true;
                }
                // move 8:
                if(r+1<8 && c+2<8 && !visited[r+1][c+2]){
                    q.push({r+1,c+2});
                    visited[r+1][c+2] = true;
                }
            }
            moves++;
        }
        return false;
    }
};