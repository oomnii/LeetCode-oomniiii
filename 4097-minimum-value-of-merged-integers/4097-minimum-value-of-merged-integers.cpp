class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9;
        for(int i=0;i<n;i=i+2){
            string num = to_string(nums[i]) + to_string(nums[i+1]);
            mini = min(mini,stoi(num));
        }
        return mini;
    }
};