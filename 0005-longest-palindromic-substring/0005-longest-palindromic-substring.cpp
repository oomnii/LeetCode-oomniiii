class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1;
        int strPoint = 0;
        for(int i=0;i<n;i++){
            // Case 1 - odd length:
            int l = i-1;
            int r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int len = r-l-1;
            if(len>maxLen){
                strPoint = l+1;
                maxLen = len;
            }

            // Case 2 - even length:
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            len = r-l-1;
            if(len>maxLen){
                strPoint = l+1;
                maxLen = len;
            }
        }
        return s.substr(strPoint,maxLen);
    }
};