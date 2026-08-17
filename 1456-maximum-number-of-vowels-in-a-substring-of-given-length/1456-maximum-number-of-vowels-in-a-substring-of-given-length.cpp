class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxV = 0;
        int currV = 0;
        int i=0;
        int j=0;
        while(j-i+1 != k+1){
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') currV++;
                j++;
        }
        j--;
        while(j<n){
            maxV = max(maxV,currV);
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') currV--;
            i++;
            j++;
            if (j==n) return maxV;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') currV++;
        }
        return maxV;
    }
};