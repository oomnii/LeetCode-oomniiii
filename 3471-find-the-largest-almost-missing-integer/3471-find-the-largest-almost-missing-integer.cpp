class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<k;j++){
                mp[nums[i+j]]++;
            }
        }
        int ans = -1;
        for(auto &it:mp){
            if(it.second==1) ans = max(ans,it.first);
        }
        return ans ;
    }
};