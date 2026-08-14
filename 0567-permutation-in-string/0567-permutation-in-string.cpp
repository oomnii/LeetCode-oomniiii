class Solution {
public:
    bool check(vector<int> &freq1 , vector<int> &freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if(m>n) return false;
        vector<int> freq1(26,0);
        for(auto &ch:s1){
            freq1[ch-'a']++;
        }
        vector<int> freq2(26,0);
        for(int i=0;i<m;i++){
            freq2[s2[i]-'a']++;
        }
        int i=0;
        int j=m-1;
        while(1){
            if(check(freq1,freq2)) return true;
            j++;
            if(j>=n) return false;
            freq2[s2[j]-'a']++;
            freq2[s2[i]-'a']--;
            i++;
        }
        return false;
    }
};