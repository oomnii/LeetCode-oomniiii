class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int i=0;
        while(i<s.length()){
            int j=i+1;
            while(j<s.length() && s[j]==s[i]){
                j++;
            }
            if((j-i)%2==0){
                i=j;
            }
            else{
                changes++;
                i=j+1;
            }
        }
        return changes;
    }
};