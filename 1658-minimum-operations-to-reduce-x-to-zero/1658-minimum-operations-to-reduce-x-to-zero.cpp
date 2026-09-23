class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<long long,int> mp;
        mp[0] = -1;
        int minOper = n+1;
        long long prefixSum = 0;
        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            if(prefixSum==x) minOper = min(minOper,i+1);
            mp[prefixSum]=i;
        }
        
        long long suffixSum = 0;
        for(int i=n-1;i>=0;i--){
            suffixSum += nums[i];
            long long diff = x-suffixSum;
            if(mp.count(diff)){
                minOper = min(minOper,n-i+mp[diff]+1);
            }
        }
        return minOper==n+1?-1:minOper;
    }
};