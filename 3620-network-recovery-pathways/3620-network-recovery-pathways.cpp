class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> adjList;
    bool checkPath(int mid, vector<bool>& online, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [cost,node] = pq.top();
            pq.pop();

            if(cost > dist[node])
                continue;

            if(node == n-1)
                return true;

            for(auto &[newNode,newCost] : adjList[node]){
                if(!online[newNode]) continue;
                if(newCost < mid) continue;
                if(cost + newCost < dist[newNode] && cost + newCost <= k){
                    dist[newNode] = cost + newCost;
                    pq.push({dist[newNode], newNode});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        adjList.resize(n);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int c = it[2];
            adjList[u].push_back({v,c});
            mini = min(mini,c);
            maxi = max(maxi,c);
        }
        int ans = -1;
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
            if(checkPath(mid,online,k)){
                ans = mid;
                mini = mid+1;
            }
            else{
                maxi = mid-1;
            }
        }
        return ans;
    }
};