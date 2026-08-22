class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>> adjList(n+1);
        for(auto &it:times){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adjList[u].push_back({v,t});
        }
        priority_queue<P,vector<P> ,greater<>> pq; // {time,node}
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int tm1 = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(tm1>time[node]) continue;
            for(auto &nbr:adjList[node]){
                int nxNode = nbr.first;
                int tm2 = nbr.second;
                if(time[nxNode]>tm1+tm2){
                    time[nxNode] = tm1+tm2;
                    pq.push({tm1+tm2,nxNode});
                }
            }
        }
        int delay = 0;
        for(int i=1;i<n+1;i++){
            if(time[i]==INT_MAX) return -1;
            delay = max(delay,time[i]);
        }
        return delay;
    }
};