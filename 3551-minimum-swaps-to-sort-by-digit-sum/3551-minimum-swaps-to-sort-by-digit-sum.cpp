
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            int num = nums[i], sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            v.push_back({sum, nums[i]});
        }

        sort(v.begin(), v.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[nums[i]] == i)
                continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
