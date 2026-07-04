class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto &it:roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adjList[u].push_back({v,d});
            adjList[v].push_back({u,d});
        }
        queue<pair<int,int>> q;
        vector<int> reachMin(n+1,INT_MAX);
        q.push({1,INT_MAX});
        reachMin[1] = INT_MAX;
        int minS = INT_MAX;
    
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [city , dist] = q.front();
                q.pop();
                minS = min(minS,dist);
                for(auto &[nextC , nextD]:adjList[city]){
                    if(reachMin[nextC]>nextD){
                        q.push({nextC,nextD});
                        reachMin[nextC] = nextD; 
                    }
                }
            }
        }
        return minS;
    }
};