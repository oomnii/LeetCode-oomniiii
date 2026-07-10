class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        // Pair each value with its original index
        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
        }

        sort(sorted.begin(), sorted.end());

        // Map original index -> sorted position
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[sorted[i].second] = i;
        }

        // Binary lifting levels
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;

        vector<vector<int>> up(n, vector<int>(LOG));

        // Compute farthest reachable index in one hop
        int r = 0;
        for (int l = 0; l < n; l++) {
            if (r < l) r = l;

            while (r + 1 < n && sorted[r + 1].first - sorted[l].first <= maxDiff)
                r++;

            up[l][0] = r;
        }

        // Build binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int src = mp[q[0]];
            int dest = mp[q[1]];

            if (src > dest)
                swap(src, dest);

            if (src == dest) {
                ans.push_back(0);
                continue;
            }

            int curr = src;
            int hops = 0;

            // Greedily take the largest jump possible
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[curr][j] < dest) {
                    curr = up[curr][j];
                    hops += (1 << j);
                }
            }

            if (up[curr][0] >= dest)
                ans.push_back(hops + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};