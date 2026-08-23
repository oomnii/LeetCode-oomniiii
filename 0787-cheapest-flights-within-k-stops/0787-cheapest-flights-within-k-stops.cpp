class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &it:flights){
            int u = it[0];
            int v = it[1];
            int p = it[2];
            adjList[u].push_back({v,p});
        }
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<>> pq;
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        pq.push({0,0,src});
        dist[src][0] = 0;
        while(!pq.empty()){
            auto [currP, currK, currPos] = pq.top();
            pq.pop();
            if(currK==k+1) continue;
            if(dist[currPos][currK]<currP) continue;
            for(auto &nbr:adjList[currPos]){
                if(dist[nbr.first][currK+1] > currP+nbr.second){
                    dist[nbr.first][currK+1] = currP+nbr.second;
                    pq.push({currP+nbr.second,currK+1,nbr.first});
                }
            }
        }
        int minPrice = INT_MAX;
        for(int i=0;i<=k+1;i++){
            minPrice = min(minPrice,dist[dst][i]);
        } 
        return minPrice==INT_MAX ? -1 : minPrice;
    }
};