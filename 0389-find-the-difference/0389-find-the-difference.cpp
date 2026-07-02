class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++; 
        }
        for(auto &ch:t){
            freq[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]--) return i+'a';
        }
        return 'a';
    }
};