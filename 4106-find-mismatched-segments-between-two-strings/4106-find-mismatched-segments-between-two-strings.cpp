class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> ans;
        int i=0;
        while(i<n){
            if(s1[i]!=s2[i]){
                int j = i;
                while(j<n && s1[j]!=s2[j]) j++;
                ans.push_back({s1.substr(i,j-i),s2.substr(i,j-i)});
                i = j;
            }
            else i++;   
        }
        return ans;
    }
};