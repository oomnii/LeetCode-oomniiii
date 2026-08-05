class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < m; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }

        unordered_set<int> st;
        queue<int> q;
        q.push(k);
        st.insert(k);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &it : adjList[node]) {
                if (!st.count(it)) {
                    st.insert(it);
                    q.push(it);
                }
            }
        }

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];
            if (!st.count(u) && st.count(v)) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!st.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};