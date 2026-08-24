class Solution {
public:
    int n;
    vector<int> prefix;
    vector<int> dp;
    int solve(int index){
        if(index==n-1) return prefix[n-1];
        if(dp[index]!=INT_MIN) return dp[index];

        int take = prefix[index]-solve(index+1);
        int skip = solve(index+1);

        return dp[index] = max(take,skip); 
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        prefix.assign(n,0);
        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+stones[i];
        }
        dp.assign(n,INT_MIN);
        return solve(1);
    }
};