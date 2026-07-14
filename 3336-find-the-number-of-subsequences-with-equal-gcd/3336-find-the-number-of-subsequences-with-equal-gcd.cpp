class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int n;

    int solve(vector<int>& nums , int index ,int gcd1, int gcd2){
        if(index==n){
            if(gcd1==gcd2 && gcd1!=0) return 1;
            return 0;
        }

        if(dp[index][gcd1][gcd2]!= -1) return dp[index][gcd1][gcd2];

        int ans = 0;
        // take in seq 1:
        int take1 = solve(nums,index+1,__gcd(nums[index],gcd1),gcd2);
        // take in seq 2:
        int take2 = solve(nums,index+1,gcd1,__gcd(nums[index],gcd2));
        // skip curr Element:
        int skip = solve(nums,index+1,gcd1,gcd2);

        ans = ((take1%mod + take2%mod)%mod + skip%mod)%mod;

        return dp[index][gcd1][gcd2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());
        dp.assign(n,vector<vector<int>>(maxEle+1,vector<int>(maxEle+1,-1)));

        return solve(nums,0,0,0);
    }
};