class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp ="";
        for(int i=0;i<n;i++){
            temp += ".";
        }
        ans.push_back(temp);
        for(int i=1;i<m;i++){
            string temp2 = "";
            for(int j=0;j<n-1;j++){
                temp2 += "#";
            }
            temp2 += ".";
            ans.push_back(temp2);
        }
        return ans;
    }
};