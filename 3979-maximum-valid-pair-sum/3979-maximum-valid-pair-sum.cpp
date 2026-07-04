class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            maxi[i] = max(maxi[i+1],nums[i]);
        }

        int maxPair = 0;
        for(int i=0;i<n-k;i++){
            maxPair = max(maxPair,nums[i]+maxi[i+k]);
        }
        return maxPair;
    }
};