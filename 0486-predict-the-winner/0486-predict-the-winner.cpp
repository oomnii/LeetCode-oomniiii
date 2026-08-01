class Solution {
public:
    int n;
    int totalSum;
    //vector<vector<vector<vector<int>>>> dp;
    bool solve(int i,int j,int chance,int sum,vector<int>& nums){
        if(i==j){
            if(chance==0){
                sum += nums[i];
            }
            return sum>=(totalSum-sum);
        }
        //if(dp[i][j][chance][sum]!=-1) return dp[i][j][chance][sum];
        bool ans = false;
        if(chance==0){
            ans = ans ||
                    solve(i+1,j,(chance+1)%2,sum+nums[i],nums) ||
                    solve(i,j-1,(chance+1)%2,sum+nums[j],nums);
        }
        else{
            ans = ans || 
                    solve(i+1,j,(chance+1)%2,sum,nums) && 
                    solve(i,j-1,(chance+1)%2,sum,nums);
        }
        return ans ;
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        totalSum = 0;
        for(auto &it:nums){
            totalSum += it;
        }
        //dp.assign(n,vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(totalSum,-1))));
        return solve(0,n-1,0,0,nums);
    }
};