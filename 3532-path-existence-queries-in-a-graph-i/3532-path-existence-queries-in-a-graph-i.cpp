class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionUV(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;
        if (u < v)
            parent[v] = u;  
        else
            parent[u] = v;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        int i = 0;
        int j = i+1;
        while(i<n){
            while(j<n && (nums[j]-nums[i])<=maxDiff){
                unionUV(i,j);
                j++;
            }
            i++;   
        }
        vector<bool> ans;
        for(auto &it:queries){
            int u = it[0];
            int v = it[1];
            if(parent[u]==parent[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};