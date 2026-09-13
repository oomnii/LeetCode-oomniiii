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
            if(it.second.size()>=3){
                int gap = it.second[1]-it.second[0];
                bool cond = true;
                for(int i=1;i<it.second.size()-1;i++){
                    if(it.second[i+1]-it.second[i]!=gap){
                        cond = false;
                        break;
                    }
                }
                if(cond) cnt++;
            }
        }
        return cnt;
    }
};