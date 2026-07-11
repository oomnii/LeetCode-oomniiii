class Solution {
public:
    vector<int> parent;
    int findP(int x){
        if(parent[x]==x) return x;
        else return parent[x] = findP(parent[x]);
    }

    void unionUV(int u,int v){
        int uP = findP(u);
        int vP = findP(v);
        if(uP>vP) parent[uP]=vP;
        else parent[vP] = uP;
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            unionUV(u,v);
        }

        vector<int> nodeCount(n, 0), edgeCount(n, 0);
        for(int i=0;i<n;i++) nodeCount[findP(i)]++;
        for(auto &it : edges) edgeCount[findP(it[0])]++;

        int cmp = 0;
        for(int i=0;i<n;i++){
            if(findP(i) != i) continue;
            int nc = nodeCount[i];
            if(edgeCount[i] == nc*(nc-1)/2) cmp++;
        }
        return cmp;
    }
};