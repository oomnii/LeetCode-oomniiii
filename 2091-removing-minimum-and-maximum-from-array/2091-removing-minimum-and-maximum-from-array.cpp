class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = -1;
        int maxIdx = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini = nums[i];
                minIdx = i;
            }
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIdx = i;
            }
        }
        int case1 = (minIdx+1) + (n-maxIdx);
        int case2 = (maxIdx+1) + (n-minIdx);
        int case3 = max(minIdx,maxIdx)+1;
        int case4 = n-min(minIdx,maxIdx);
        return min({case1,case2,case3,case4});
    }
};