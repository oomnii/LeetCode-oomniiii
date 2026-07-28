class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        int idx = 0;
        int i=0;
        int j=n-1;
        char mid = '$';
        while(i<j){
            while(freq[idx]>=2){
                s[i] = idx+'a';
                s[j] = idx+'a';
                i++;
                j--;
                freq[idx] -= 2;
            }
            if(freq[idx]==1){
                mid = idx+'a';
            }
            idx++;
        }
        if(mid!='$') s[i] = mid;
        return s;
    }
};