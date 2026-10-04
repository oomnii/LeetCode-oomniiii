class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool solve(string &s,int i,int cnt){
        if(cnt<0) return false;
        if(i==n){
            if(cnt==0) return true;
            return false;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        bool valid = false;
        if(s[i]=='('){
            valid = solve(s,i+1,cnt+1);
        }
        else if(s[i]==')'){
            valid = solve(s,i+1,cnt-1);
        }
        else{
            valid = solve(s,i+1,cnt+1) || solve(s,i+1,cnt-1) || solve(s,i+1,cnt);
        }
        return dp[i][cnt] = valid;
    }
    bool checkValidString(string s) {
        n = s.length();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(s,0,0);
    }
};