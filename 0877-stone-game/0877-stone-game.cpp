class Solution {
public:
    int totalPiles;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int chance,vector<int>& piles){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j][chance]!=-1) return dp[i][j][chance];
        int ans = 0;
        if(chance==0){
            ans = ans + max(piles[i]+solve(i+1,j,(chance+1)%2,piles),  
                                piles[j]+solve(i,j-1,(chance+1)%2,piles));
        }
        else{
            ans = ans - max(piles[i]-solve(i+1,j,(chance+1)%2,piles),  
                                piles[j]-solve(i,j-1,(chance+1)%2,piles));
        }

        return dp[i][j][chance] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        totalPiles = 0;
        for(auto &it:piles){
            totalPiles += it;
        }
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,n-1,0,piles)>0;
    }
};