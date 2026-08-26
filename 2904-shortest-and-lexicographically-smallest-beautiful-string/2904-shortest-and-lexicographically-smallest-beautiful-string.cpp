class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = s;
        int len = INT_MAX;
        int i=0;
        int j = i;
        while(i<n){
            while(j<n && k){
                if(s[j]=='1') k--;
                j++;
            }

            if (k == 0) {
                if (len > (j - i)) {
                    len = j - i;
                    ans = s.substr(i, j - i);
                }
                else if (len == (j - i)) {
                    ans = min(ans, s.substr(i, j - i));
                }
            }

            if(s[i]=='1') k++;
            i++;
        }
        return len==INT_MAX ? "" : ans;
    }
};