class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int special = 0;
        for(auto &it:mp){
            int sz = it.second.size();
            bool consecutive = true;
            for(int i=1;i<sz;i++){
                if(it.second[i]-it.second[i-1]!=1){
                    consecutive = false;
                    break;
                }
            }
            if(consecutive) special++;
        }
        return special;
    }
};