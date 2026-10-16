class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front();
                q.pop();
                for(auto &it:rooms[r]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
        for(auto seen:visited){
            if(!seen) return false;
        }
        return true;
    }
};