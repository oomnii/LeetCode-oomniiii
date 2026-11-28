class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        int i = 0;

        while (i < n) {
            int j = i;

            // Find consecutive equal elements
            while (j + 1 < n && nums[j + 1] == nums[i]) {
                j++;
            }

            // Block must contain at least one valid pivot
            if (j >= 1 && i <= n - 2) {
                long long len = j - i + 1;

                long long cost = (n - len) * 1LL * nums[i];

                ans = min(ans, cost);
            }

            i = j + 1;
        }

        return ans;
    }
};