class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int maxSplits = 0;

        for (int remove = -1; remove < n; remove++) {
            vector<int> GCDSuffix(n, 0);
            int g = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (i == remove) continue;

                g = __gcd(nums[i], g);
                GCDSuffix[i] = g;
            }

            int splits = 0;
            int GCDPrefix = 0;

            for (int i = 0; i < n - 1; i++) {
                if (i != remove) GCDPrefix = __gcd(GCDPrefix, nums[i]);
                if (i + 1 == remove) continue;

                if (GCDPrefix == GCDSuffix[i + 1])
                    splits++;
            }
            maxSplits = max(maxSplits, splits);
        }
        return maxSplits;
    }
};