class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto &it:mp){
            if(it.second.size()==3){
                int gap1 = it.second[1]-it.second[0];
                int gap2 = it.second[2]-it.second[1];
                if(gap1==gap2) cnt++;
            }
        }
        return cnt;
    }
};