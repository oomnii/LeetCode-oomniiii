class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> v;
        for(auto &it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int> topK;
        for(auto &it:v){
            if(k==0) break;
            topK.push_back(it.second);
            k--;
        }
        return topK;
    }
};