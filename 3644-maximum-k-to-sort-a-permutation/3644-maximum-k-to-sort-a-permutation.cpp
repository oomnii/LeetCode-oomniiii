class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i) k &= nums[i];
            i++;
        }
        return k==INT_MAX? 0:k;
    }
};