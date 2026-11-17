class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int mini = 1e9;
            int And = -1;
            for(int j=i;j<n;j++){
                And &= nums[j];
                mini = min(mini,nums[j]);
                if(And == mini) count++;
            }
        }
        return count;
    }
};