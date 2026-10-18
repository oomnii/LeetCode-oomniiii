class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int minDel = 0;
        int prev = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==prev) minDel++;
            else{
                prev = nums[i];
            }
        }
        return minDel;
    }
};