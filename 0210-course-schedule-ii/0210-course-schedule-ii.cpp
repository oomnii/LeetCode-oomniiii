class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
            inDegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for(auto &nbr:adjList[curr]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(result.size()==numCourses) return result;
        return {};
    }
};