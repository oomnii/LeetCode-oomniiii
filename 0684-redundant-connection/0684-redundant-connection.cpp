class Solution {
public:
    vector<vector<int>> adjList;
    bool pathExist(int u, int v,vector<int> &visited){
        if(u==v) return true;
        visited[u] = 1;
        for(auto &nbr:adjList[u]){
            if(visited[nbr]==0){
                if(pathExist(nbr,v,visited)) return true;;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adjList.resize(n+1);
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            vector<int> visited(n+1,0);
            if(pathExist(u,v,visited)) return it;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return {};
    }
};