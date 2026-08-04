class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(nums[i]-1==nums[i-1]) continue;
            else{
                int num = nums[i-1]+1;
                while(num!=nums[i]) ans.push_back(num++);
            }
        }
        return ans;
    }
};