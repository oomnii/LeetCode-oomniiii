class Solution {
public:
    typedef long long ll;
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        vector<ll> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        ll totalSum = prefixSum[n];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int end = i + half;
            ll leftSum = 0;

            if (end <= n) {
                leftSum = prefixSum[end] - prefixSum[i];
            } 
            else {
                leftSum = prefixSum[n] - prefixSum[i] + prefixSum[end - n];
            }
            if (leftSum > totalSum - leftSum) {
                cnt++;
            }
        }
        return cnt;
    }
};