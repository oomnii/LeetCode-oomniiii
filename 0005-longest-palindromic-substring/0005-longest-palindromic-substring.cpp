class Solution {
public:
    vector<vector<int>> dp;
    bool checkPalindrome(int l , int r,string &s){
        if(l>=r) return 1;

        if(dp[l][r] != -1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r] = checkPalindrome(l+1,r-1,s);
        }
        return dp[l][r] = false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        dp.assign(n,vector<int>(n,-1));
        int maxLen = 0;
        int strPoint = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(len>maxLen && checkPalindrome(i,j,s)){
                    strPoint = i;
                    maxLen = j-i+1;
                }
            }
        }
        return s.substr(strPoint,maxLen);
    }
};