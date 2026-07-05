class Solution {
public:
    int mod = 1e9+7;
    int divisibleGame(vector<int>& nums) {
        unordered_set<int> k;
        k.insert(2);
        for(auto &num:nums){
            if(num>=2) k.insert(num);
            for(int i=3;i*i<=num;i++){
                if(num%i==0) k.insert(i);
                k.insert(num/i);
            }
        }

        int bestK = INT_MAX;
        int bestScore = INT_MIN;
        for(auto &it:k){
            int curr = 0;
            int best = INT_MIN;
            for(auto &x:nums){
                int val;
                if(x%it==0) val = x;
                else val = -x;
                curr = max(val , curr+val);
                best = max(best,curr);
            }
            if (best > bestScore) {
                bestScore = best;
                bestK = it;
            }
            else if (best == bestScore) {
                bestK = min(bestK, it);
            }
        }
        long long ans = ((1LL*bestK*bestScore)%mod+mod)%mod;
        return (int)ans;
    }
};