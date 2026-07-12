class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll curr = k;
        ll operation = 0;
        ll cost = 0;
        for(int i=0;i<n;i++){
            ll x = nums[i];
            if(curr<x){
                ll diff = x-curr;
                ll need = (diff+k-1)/k;
                curr += need*k;
                ll addCost = ((((__int128)(operation + need) * (operation + need + 1) / 2) % mod)
                            - (((__int128)operation * (operation + 1) / 2) % mod)+ mod) % mod;   

                operation += need;            
                cost = (cost+addCost)%mod;
            }
            curr -= x;
        }
        return cost%mod;
    }
};