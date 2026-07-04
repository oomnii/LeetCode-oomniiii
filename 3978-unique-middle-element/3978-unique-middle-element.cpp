class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middle = nums[n/2];
        int cnt = 0;
        for(auto &it:nums){
            if(it==middle) cnt++;
        }
        if(cnt==1) return true;
        return false;
    }
};