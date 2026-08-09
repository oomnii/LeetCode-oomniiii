class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adjList(n);
        for (int i = 1; i < n; i++) {
            adjList[parent[i]].push_back(i);
        }

        vector<int> depth(n, -1);
        queue<int> q;
        q.push(0);
        depth[0] = 1;

        int h = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            h = max(h, depth[node]);
            for (int nbr : adjList[node]) {
                depth[nbr] = depth[node] + 1;
                q.push(nbr);
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return sum;
    }
};