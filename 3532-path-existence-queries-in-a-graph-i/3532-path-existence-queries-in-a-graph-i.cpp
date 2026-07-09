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
        int last = -1;
        int l=0;
        int r=n-1;
        int idx = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]-nums[0]<=maxDiff){
                idx = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        last = idx;
        for(int i=0;i<=last;i++){
            unionUV(0,i);
        }
        for(int i=1;i<n;i++){
            l = last;
            r = n-1;
            idx = -1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(nums[mid]-nums[i]<=maxDiff){
                    idx = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            for(int j = last+1;j<=idx;j++){
                unionUV(i,j);
            }
            last = idx;
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